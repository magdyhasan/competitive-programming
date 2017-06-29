#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;




const int maxn = 200500, L = 19;

int h[maxn], par[maxn][L], mi[maxn][L], mx[maxn][L];
vector<pii> adj[maxn];

void dfs(int u, int p = -1,int lastEdgeCost = -1){
	h[u] = (~p ? h[p] + 1 : 0);
	par[u][0] = p;
	if (p == -1) mi[u][0] = 123456789, mx[u][0] = -1;
	else mi[u][0] = lastEdgeCost, mx[u][0] = lastEdgeCost;
	for (int i = 1; i < L && par[u][i-1] != -1; i++){
		if (par[u][i - 1] == -1) break;
		par[u][i] = par[par[u][i - 1]][i - 1];
		mi[u][i] = min(mi[u][i - 1], mi[par[u][i - 1]][i - 1]);
		mx[u][i] = max(mx[u][i - 1], mx[par[u][i - 1]][i - 1]);
	}
	for (auto v : adj[u]) if (v.first - p)
		dfs(v.first, u, v.second);
}

int curmx, curmi;
int lca(int u, int v){
	if (h[v] > h[u]) swap(u, v);
	for (int i = L-1; i >= 0; i--) 
		if (h[u] - (1 << i) >= h[v]){
			curmi = min(curmi, mi[u][i]), curmx = max(curmx, mx[u][i]), u = par[u][i];
		}
	if (u == v) return u;
	for (int i = L-1; i >= 0; i--) 
		if (par[u][i] != -1 && par[u][i] != par[v][i]){
		curmi = min(curmi, mi[u][i]), curmx = max(curmx, mx[u][i]);
		curmi = min(curmi, mi[v][i]), curmx = max(curmx, mx[v][i]);
		u = par[u][i], v = par[v][i];
	}
	curmi = min(curmi, mi[u][0]), curmx = max(curmx, mx[u][0]);
	curmi = min(curmi, mi[v][0]), curmx = max(curmx, mx[v][0]);
	return par[u][0];
}


int main(){
    freopen("uva.txt","rt",stdin);
	memset(par, -1, sizeof(par));
	int n; scanf("%d", &n);
	for (int i = 0; i + 1 < n; i++){
		int u, v, va;
		scanf("%d%d%d", &u, &v, &va);
		adj[u].push_back({ v, va });
		adj[v].push_back({ u, va });
	}
	dfs(1);
	int q; scanf("%d", &q);
	for (int i = 0; i < q; i++){
		int u, v; scanf("%d%d", &u, &v);
		curmi = 123456789, curmx = -1;
		lca(u, v);
		printf("%d %d\n", curmi, curmx);
	}
}
