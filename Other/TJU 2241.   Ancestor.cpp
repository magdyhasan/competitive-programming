#include<bits/stdc++.h>
using namespace std;




const int maxn = 200500, L = 19;

int h[maxn], par[maxn][L];
vector<int> adj[maxn];

void dfs(int u, int p = -1){
	h[u] = (~p ? h[p] + 1 : 0);
	par[u][0] = p;
	for (int i = 1; i < L&& par[u][i - 1] != -1; i++)
		par[u][i] = par[par[u][i - 1]][i - 1];
	int v;
	for (int i = 0; i < adj[u].size();i++) {
		v = adj[u][i];
		if (v - p)
			dfs(v, u);
	}
}

int lca(int u, int v){
	if (h[v] > h[u]) swap(u, v);
	for (int i = L - 1; i >= 0; i--) if (h[u] - (1 << i) >= h[v])
		u = par[u][i];
	if (u == v) return u;
	for (int i = L - 1; i >= 0; i--) if (par[u][i] != -1 && par[u][i] != par[v][i])
		u = par[u][i], v = par[v][i];
	return par[u][0];
}



int main(){
	freopen("uva.txt", "r", stdin);
	int T; scanf("%d", &T);
	while (T--){
		int n, q; scanf("%d", &n);
		int u, v;
		for (int i = 0; i <= n; i++) adj[i].clear();
		for (int i = 0; i + 1 < n; i++){
			scanf("%d%d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfs(0);
		scanf("%d", &q);
		while (q--){
			scanf("%d%d", &u, &v);
			if (u != v&&lca(u, v) == u) puts("Yes");
			else puts("No");
		}
		puts("");
	}
}