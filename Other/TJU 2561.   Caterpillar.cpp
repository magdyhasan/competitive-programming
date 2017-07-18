#include<bits/stdc++.h>
using namespace std;


const int maxn = 105;
int n, m;

vector<int> adj[maxn];
int sz[maxn], vis[maxn], in[maxn];
int cnt;

bool computersz(int u, int p){
	if (vis[u]) return 0;
	cnt++;
	int ret = 1;
	vis[u] = 1;
	for (int i = 0; i<adj[u].size(); i++){
		int v = adj[u][i];
		if (v != p){
			if (!computersz(v, u)) return 0;
			ret += sz[v];
		}
	}
	sz[u] = ret;
	return 1;
}

bool rec(int u, int p){
	int mx = -1, mxv;
	for (int i = 0; i<adj[u].size(); i++){
		int v = adj[u][i];
		if (v != p){
			if (sz[v] > 1){
				if (mx == -1) mx = sz[v], mxv = v;
				else return 0;
			}
		}
	}
	if (mx != -1) return rec(mxv, u);
	return 1;
}



int main(){
	freopen("uva.txt", "r", stdin);
	int tc = 0;
	while (scanf("%d%d", &n, &m)){
		if (!n) break;
		tc++;
		for (int i = 0; i <= n; i++) adj[i].clear(), vis[i] = 0, in[i] = 0;
		int u, v;
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int st = -1;
		for (int i = 1; i <= n; i++) if (in[i] == 0)
			st = i;
		cnt = 0;
		if (st == -1 || !computersz(st, -1) || cnt != n || !rec(st, -1)) printf("Graph %d is not a caterpillar.\n", tc);
		else printf("Graph %d is a caterpillar.\n", tc);
	}
}