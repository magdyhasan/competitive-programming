#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn = 100000 + 40;

int child_chain[maxn], par_chain[maxn], first_chain[maxn];

// lca code from: http://e-maxx.ru/algo/lca_simpler
int n, lo;
vector < int > adj[maxn];
int tin[maxn], tout[maxn];
int timer;
int vis[maxn];
vector < int > up[maxn];
ll segTree[maxn * 8];

void dfs(int v, int p = 1) {
	tin[v] = ++timer; 
	up[v][0] = p; // parent of this node
	for (int i = 1; i <= lo; ++i) // build all 2^i parent for v
		up[v][i] = up[up[v][i - 1]][i - 1];
	for (size_t i = 0; i<adj[v].size(); ++i) { // make tree
		int to = adj[v][i];
		if (to != p && !vis[to])
			dfs(to, v);
	}
	tout[v] = ++timer;
}

void lca_init(){ // After reading n
	lo = 1;
	while ((1 << lo) <= n)  ++lo; // log(n)
	for (int i = 0; i<=n; ++i)  up[i].resize(lo + 1); // initialize up[maxn][log(n)]
	vis[1] = 1;
	dfs(1); // make tree from root 1
}

bool upper(int a, int b) { // is node a is ancestor of node b
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b) {
	if (upper(a, b))  return a; 
	if (upper(b, a))  return b;
	for (int i = lo; i >= 0; --i)
		if (!upper(up[a][i], b)) 
			a = up[a][i];
	return up[a][0];
}
// end lca code


// heavy light decomposition code

int heavy_light_decomposition(int u,int p = 1){
	int mx_child_s = -1, mx_child_idx = -1, subtree_size = 1; // pick the node with max_size_subtree
	for (int v : adj[u]) {
		if (v == p)	continue; 
		int t = heavy_light_decomposition(v, u);
		subtree_size += t;
		if (t > mx_child_s)
			mx_child_s = t, mx_child_idx = v;
	}
	if (mx_child_idx != -1) { // if this not a leaf node 
		child_chain[u] = mx_child_idx; // u --> mx_child_idx is the heavy edge 
		par_chain[mx_child_idx] = u;
	}
	return subtree_size;
}

int nodeIdxChain[maxn];

void set_chains(){
	int idx = 0, chain_nu = 0;
	for (int i = 1; i <= n;i++)
		if (par_chain[i] == -1) { // this the start of a chain
			chain_nu++; // we have a new chain
			int t = i;
			while (t != -1) { // go theough all this chain
				nodeIdxChain[t] = ++idx; // numbering the nodes for the segment tree 
				first_chain[t] = i; // make i the root of the chain
				t = child_chain[t];
			}
		}
}


// end heavy light decomposition code

// segment tree on chain code

void update_segtree(int x, int y, int idx = 1, int l = 1, int r = n){
	if (l == r) {
		segTree[idx] += y;
		return;
	}
	int mid = (l + r) >> 1;
	if (x <= mid)
		update_segtree(x, y, idx << 1, l, mid);
	else
		update_segtree(x, y, (idx << 1) + 1, mid + 1, r);
	segTree[idx] = max(segTree[idx << 1], segTree[(idx << 1) + 1]);
}

ll query_segtree(int x, int y, int idx = 1, int l = 1, int r = n){
	if (x > r || y < l)
		return -1;
	if (x <= l && y >= r)
		return segTree[idx];
	int mid = (l + r) >> 1;
	int l_seg = query_segtree(x, y, idx << 1, l, mid);
	int r_seg = query_segtree(x, y, (idx << 1) + 1, mid + 1, r);
	return max(l_seg, r_seg);
}

// end segment tree on chain code


ll heavy_light_query_2(int u, int v){
	ll ret = 0;
	while (first_chain[u] != first_chain[v]) // while we are not in the same chain go up in u ( as v is the lca so we want to reach it )
		ret = max(ret, query_segtree(nodeIdxChain[first_chain[u]], nodeIdxChain[u])), u = up[first_chain[u]][0];
	ret = max(ret, query_segtree(nodeIdxChain[v], nodeIdxChain[u])); // we are now in the same chain so query seg_tree between v,u ( not u,v )
	return ret;
}

ll heavy_light_query(int u, int v){
	int lca_node = lca(u, v); 
	return max(heavy_light_query_2(u, lca_node), heavy_light_query_2(v, lca_node));
}

int main(){
    freopen("uva.txt","rt",stdin);
	scanf("%d", &n);
	memset(par_chain, -1, sizeof(par_chain));
	memset(child_chain, -1, sizeof(child_chain));
	int u, v;
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	lca_init();
	heavy_light_decomposition(1);
	set_chains();
	int q;	scanf("%d", &q);
	while (q--) {
		char st[100];
		scanf("%s%d%d", st, &u, &v);
		if (st[0] == 'I')
			update_segtree(nodeIdxChain[u], v);
		else
			printf("%lld\n", heavy_light_query(u, v));
	}
}
