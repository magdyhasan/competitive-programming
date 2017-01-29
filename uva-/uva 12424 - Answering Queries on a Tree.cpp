#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 100500;

struct chain{
	vector<int> a;
	vector<int> segTree[10];
	int p, pPos, dep;
	void init(){
		a.clear();
		p = -1, dep = 0;
	}
} chains[maxn];

vector<int> adj[maxn];
int col[maxn], h_next[maxn], nodeChain[maxn], posInChain[maxn];
bool vis[maxn];
int n, q;




int dfs(int u, int p){
	int sz = 1, h_edge = -1, h_idx = -1, t_sz; // pick heavy edge
	for (int v : adj[u]) 
		if (v != p) {
			sz += (t_sz = dfs(v, u));
			if (t_sz > h_edge)
				h_edge = t_sz, h_idx = v;
		}
	h_next[u] = h_idx; // next node is the node with the heavy edge
	return sz;
}

void buildSegTree(chain &ch, int idx, int l, int r){
	if (l > r)	return;
	if (l == r) {
		ch.segTree[col[ch.a[l]]][idx] = 1;
		return;
	}
	int mid = (l + r) >> 1;
	buildSegTree(ch, idx << 1, l, mid);
	buildSegTree(ch, (idx << 1) | 1, mid + 1, r);
	for (int i = 0; i < 10; i++)
		ch.segTree[i][idx] = ch.segTree[i][idx << 1] + ch.segTree[i][(idx << 1) | 1];
}

int curChain;

void heavy_light_init(int u,int p){
	if (vis[u] == 0) { // this the first node of the chain
		chain &ch = chains[++curChain]; // add new chain
		ch.init(); 
		int t = u; 
		while (t != -1) {// traverse the whole chain
			vis[t] = true;
			nodeChain[t] = curChain;  // node t is in chain (curChain)
			posInChain[t] = ch.a.size(); // node t is in pos (ch.a.size()) in curChain
			ch.a.push_back(t); // push this element in the chain
			t = h_next[t]; // go to next node in this chain
		}
		for (int i = 0; i < 10; i++)
			ch.segTree[i].clear(), ch.segTree[i].resize((int)(ch.a.size()) * 4, 0); // make segment tree sum for each color
		buildSegTree(ch, 1, 0, ch.a.size() - 1); // build segment tree for this chain
		if (p != -1) { // if this chain is not the first chain
			ch.p = nodeChain[p], ch.pPos = posInChain[p]; // ch.p is the parent chain and ch.pPos is p pos
			ch.dep = chains[ch.p].dep + 1;// depth of this chain
		}
	}
	for (int v : adj[u])
		if (v != p)
			heavy_light_init(v, u);
}

void update(chain &ch, int x, int y, int idx, int l, int r){
	if (l == r) {
		for (int i = 0; i < 10; i++) // reset all number 
			ch.segTree[i][idx] = 0;
		ch.segTree[y][idx]++; // we now have this number
		return;
	}
	int mid = (l + r) >> 1;
	if (x <= mid)
		update(ch, x, y, idx << 1, l, mid);
	else
		update(ch, x, y, (idx << 1) | 1, mid + 1, r);
	for (int i = 0; i < 10; i++)
		ch.segTree[i][idx] = ch.segTree[i][idx << 1] + ch.segTree[i][(idx << 1) | 1]; // accumulate segment tree
}

int cnt[10];

void segTreeQuery(chain &ch, int x, int y, int idx, int l, int r){
	if (x <= l && y >= r) {
		for (int i = 0; i < 10; i++)
			cnt[i] += ch.segTree[i][idx];
		return;
	}
	int mid = (l + r) >> 1;
	if (x <= mid)
		segTreeQuery(ch, x, y, idx << 1, l, mid);
	if (y > mid)
		segTreeQuery(ch, x, y, (idx << 1) | 1, mid + 1, r);
}

int heavy_light_query(int u, int v){
	memset(cnt, 0, sizeof(cnt)); // resest sum of each number
	int x = nodeChain[u], y = nodeChain[v]; // find chain of u,v
	u = posInChain[u], v = posInChain[v];// pos of  u and v in x,y
	while (x != y) {// while x != y are not the same chain
		if (chains[x].dep < chains[y].dep) // find the one with bigger depth
			swap(x, y), swap(u, v);
		segTreeQuery(chains[x], 0, u, 1, 0, chains[x].a.size() - 1); // query chain of u 
		u = chains[x].pPos, x = chains[x].p;// go up from chain x to parent of x
	}
	if (u > v)	swap(u, v);
	segTreeQuery(chains[x], u, v, 1, 0, chains[x].a.size() - 1);// query when we are in the same chain
	int ret = 0;
	for (int i = 0; i < 10; i++) // for each sum of number find the max
		ret = max(ret, cnt[i]);
	return ret;
}

int main(){
	int tc, u ,v, cmd;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &n, &q);
		memset(vis, 0, sizeof(vis));
		curChain = 0;
		for (int i = 0; i <= n; i++)	adj[i].clear();
		for (int i = 0; i < n; i++)	scanf("%d", col + i), col[i]--;
		for (int i = 1; i < n; i++)
			scanf("%d%d", &u, &v), adj[u - 1].push_back(v - 1), adj[v - 1].push_back(u - 1);
		dfs(0, -1); // size of subtrees
		heavy_light_init(0, -1); // set chains
		for (int i = 0; i < q; i++) {
			scanf("%d%d%d", &cmd, &u, &v);
			u--;	v--;
			if (cmd == 0)
				// update chain of nodeChain[u], pos of u 
				update(chains[nodeChain[u]], posInChain[u], v, 1, 0, chains[nodeChain[u]].a.size() - 1);
			else
				printf("%d\n",heavy_light_query(u, v));
		}
	}
}
