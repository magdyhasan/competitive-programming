#include<stdlib.h>
#include<stdio.h>
#include<cstring>
using namespace std;

int deg[250];
int adj[250][250];
bool vis[250];

int n, m;

void dfs(int u) {
	vis[u] = true;	
	for (int v = 0; v < n; v++)
		if (adj[u][v] && !vis[v])
			dfs(v);
	return;
}

int main(){
	freopen("uva.txt", "rt", stdin);
	while (scanf("%d%d", &n, &m) == 2) {
		memset(adj, 0, sizeof(adj));
		for (int i = 0; i < n; i++)	deg[i] = 0, vis[i] = 1; // handle vertices with no edges ( mark them as visited )
		int a, b;
		for (int i = 0; i < m; i++)
			scanf("%d%d", &a, &b), deg[a]++, deg[b]++, adj[a][b] = adj[b][a] = true, vis[a] = vis[b] = false;
		bool t = false; // if graph is empty ( we must have exactly one connected component we will walk on, and possibly some vertices with no edges we don't care about )
		for (int i = 0; i < n; i++)	if (!vis[i]) { dfs(i);	t = true; break; } // get exactly one connected componet
		for (int i = 0; i < n; i++)
			if (deg[i] % 2 == 1 || !vis[i]) t = false; // all vertices must have even number of edges 
		puts(t ? "Possible" : "Not Possible");
	}
}
