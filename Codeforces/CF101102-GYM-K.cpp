/*
	notice that we can't solve this problem because normal topological sort,
	require use to update all edges of adjacent vertices with -1
	because we are give removed edges, actuall edges can be > 1e5 so we can't iterate over them

	now as defination of topological sort we first choose maximum node that have no incoming edges
	when we process node we need to remove all it's edges to all other nodes 
	and decrement their incoming edges, so if we have node 2, we have to remove edge [3,n]
	except edges that already been removed
	this can be done with segment tree with lazy propagation

*/
#include <bits/stdc++.h>
using namespace std;



#define all(v)           ((v).begin()), ((v).end())
#define sz size()
#define clr(v,d)         memset(v,d,sizeof(v))
#define lp(i, n)         for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define sci(a)	scanf("%d",&a)
#define scii(a, b)	scanf("%d%d",&a, &b)
#define pri(a)	printf("%d\n",a)

const int maxn = 300500;


int in[maxn];
vector<int> adj[maxn];



int n;

pair<int, int> segT[maxn * 4];
int lazy[maxn * 4];


void push(int idx, int l, int r){
	if (lazy[idx]){
		segT[idx].first += lazy[idx];
		if (l != r){
			lazy[idx << 1] += lazy[idx];
			lazy[(idx << 1) | 1] += lazy[idx];
		}
		lazy[idx] = 0;
	}
}

void merge(int idx, int lidx, int ridx){
	segT[idx].first = min(segT[lidx].first, segT[ridx].first);
	segT[idx].second = 0;
	if (segT[idx].first == segT[lidx].first) segT[idx].second = segT[lidx].second;
	if (segT[idx].first == segT[ridx].first) segT[idx].second = max(segT[idx].second, segT[ridx].second);
}

void updateSeg(int x, int y, int v, int idx = 1, int l = 1, int r = n){
	push(idx, l, r);
	if (x > r || y < l) return;
	if (x <= l && y >= r){
		lazy[idx] += v;
		push(idx, l, r);
		return;
	}
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	updateSeg(x, y, v, lidx, l, mid);
	updateSeg(x, y, v, ridx, mid + 1, r);
	merge(idx, lidx, ridx);
}

void build(int idx = 1, int l = 1, int r = n){
	if (l == r){
		segT[idx] = { in[l], l };
		return;
	}
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	build(lidx, l, mid);
	build(ridx, mid + 1, r);
	merge(idx, lidx, ridx);
}



int main(){
	freopen("uva.txt", "r", stdin);
	int tc; sci(tc);
	while (tc--){
		int m; scii(n, m);
		memset(in, 0, sizeof(in));
		memset(segT, 0, sizeof(segT));
		memset(lazy, 0, sizeof(lazy));
		for (int i = 0; i <= n; i++) adj[i].clear();
		lpi(i, 1, n + 1) in[i] = i - 1;
		lp(i, m){
			int u, v; scii(u, v);
			in[v]--;
			adj[u].push_back(v);
		}
		build();
		vector<int> ret;
		for (int i = 1; i <= n; i++){
			int u = segT[1].second;
			ret.push_back(u);
			updateSeg(u + 1, n, -1); // remove all adjacent edges in [u+1,n]
			for (int v : adj[u]) updateSeg(v, v, 1);// except edges has been already removed
			updateSeg(u, u, 12345678);// mark this node with big number so we can find minimum node from segment tree
		}
		for (int i : ret) printf("%d ", i);
		puts("");
	}

}