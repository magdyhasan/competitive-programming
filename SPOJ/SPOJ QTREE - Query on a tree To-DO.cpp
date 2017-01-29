#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

const int maxn = 10000 + 500;

struct chain{
	vector<int> a;
	vector<int> segTree;
	int p, pPos, dep;

	void init(){
		a.clear();
		p = -1, dep = 0;
	}
} chains[maxn];



vector<pair<int,int>> adj[maxn];
int hNext[maxn], vis[maxn];
int nodeIdxChain[maxn], nodeChain[maxn], edgesCost[maxn];
int edgeEndNode[maxn];
int curChainNu, n;

int dfs(int u, int p){
	int sz = 1, h_sz = -1, h_idx = -1, t_sz;
	for (auto v : adj[u]) 
		if (v.first != p) {
			t_sz = dfs(v.first, u);
			edgeEndNode[v.second] = u;
			if (t_sz > h_sz)
				h_sz = t_sz, h_idx = v.first;
			sz += t_sz;
		}
	hNext[u] = h_idx;
	return sz;
}

void buildSegTree(chain &ch, int idx, int l, int r){
	if (l > r)	return;
	if (l == r) {
		ch.segTree[idx] = edgesCost[ch.a[l]];
		return;
	}
	int mid = (l + r) >> 1;
	buildSegTree(ch, idx << 1, l, mid);
	buildSegTree(ch, idx << 1 | 1, mid + 1, r);
	ch.segTree[idx] = max(ch.segTree[idx << 1], ch.segTree[idx << 1 | 1]);
}

void heavy_light_init(int u, int p,int pEdge){
	if (vis[u] == 0) {
		chain &ch = chains[++curChainNu];
		ch.init();
		int t = u;
		while (t != -1) {
			vis[t] = true;
			nodeChain[t] = curChainNu;
			nodeIdxChain[t] = ch.a.size();
			ch.a.push_back(hEdgeNu[t]);
			t = hNext[t];
		}
		ch.a.pop_back();
		ch.segTree.resize((int)(ch.a.size()) * 4, 0);
		buildSegTree(ch, 1, 0, ch.a.size() - 1);
		if (p != -1) {
			ch.p = edgeChain[p], ch.pPos = edgeIdxChain[p];
			ch.dep = chains[ch.p].dep + 1;
		}
	}
	for (auto v : adj[u])
		if (v.first != p)
			heavy_light_init(v.first, u);
}

int segTreeQuery(chain &ch, int x, int y, int idx, int l, int r){
 	if (x <= l && y >= r)
		return ch.segTree[idx];
	int mid = (l + r) >> 1;
	int ls = -12345678, rs = -12345678;
	if (x <= mid)
		ls = segTreeQuery(ch, x, y, idx << 1, l, mid);
	if (y > mid)
		rs = segTreeQuery(ch, x, y, idx << 1 | 1, mid + 1, r);
	return max(ls, rs);
}

int heavy_light_query(int u, int v){
	int ret = -12345678;
	int x = edgeChain[u], y = edgeChain[v];
	u = edgeIdxChain[u], v = edgeIdxChain[v];
	while (x != y) {
		if (chains[x].dep < chains[y].dep)
			swap(x, y), swap(u, v);
		if (!chains[x].a.empty())
			ret = max(ret, segTreeQuery(chains[x], 0, u-1, 1, 0, chains[x].a.size() - 1));
		u = chains[x].pPos, x = chains[x].p;
	}
	if (u > v)
		swap(u, v);
	if (!chains[x].a.empty())
		ret = max(ret, segTreeQuery(chains[x], u, v-1, 1, 0, chains[x].a.size() - 1));
	return ret;
}


void update(chain &ch, int x, int y, int idx, int l, int r){
	if (l == r) {
		ch.segTree[idx] = y;
		return;
	}
	int mid = (l + r) >> 1;
	if (x <= mid)
		update(ch, x, y, idx << 1, l, mid);
	else
		update(ch, x, y, idx << 1 | 1, mid + 1, r);
}

int main(){
    freopen("uva.txt","rt",stdin);
	int tc, u ,v;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		for (int i = 0; i <= n; i++)	adj[i].clear(), vis[i] = 0;
		curChainNu = 0;
		for (int i = 0; i < n - 1; i++)
			scanf("%d%d%d", &u, &v, edgesCost + i), adj[u - 1].push_back(make_pair(v - 1,i)), adj[v - 1].push_back(make_pair(u - 1,i));
		dfs(0, -1);
		heavy_light_init(0, -1);
		char st[50];
		while (scanf("%s",st)) {
			if (st[0] == 'D')	break;
			scanf("%d%d", &u, &v);
			u--;
			if (st[0] == 'Q')
				printf("%d\n", heavy_light_query(u, v-1));
			else
				update(chains[edgeChain[u]], edgeIdxChain[u], v, 1, 0, chains[edgeChain[u]].a.size() - 1);
		}
	}
}
