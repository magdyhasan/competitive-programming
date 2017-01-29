#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int> adj[150];
int dfs_low[150], dfs_num[150], dfs_n;
bool bridge[150][150];

void find_bridges(int u, int p){
	dfs_low[u] = dfs_num[u] = ++dfs_n;
	for (int v : adj[u])	if (v != p)
		if (dfs_num[v] == -1) {
			find_bridges(v, u);
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
			if (dfs_low[v] == dfs_num[v])
				bridge[u][v] = bridge[v][u] = true;
		}
		else
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
	return;
}

int main(){
	freopen("uva.txt", "rt", stdin);
	int i, m, a, b, j;
	while (scanf("%d",&n) == 1) {
		for (i = 0; i <= n; i++)	adj[i].clear();
		for (i = 0; i < n; i++) {
			scanf("%d (%d)", &a, &m);
			for (j = 0; j < m; j++)
				scanf("%d", &b), adj[a].push_back(b), adj[b].push_back(a);
		}
		memset(dfs_num, -1, sizeof(dfs_num));
		memset(bridge, 0, sizeof(bridge));
		for (i = 0; i < n; i++)
			if (dfs_num[i] == -1)
				find_bridges(i, -1);
		int bridgesCnt = 0;
		for (i = 0; i < n; i++)	for (j = i + 1; j < n; j++)
			bridgesCnt += bridge[i][j];
		printf("%d critical links\n", bridgesCnt);
		for (i = 0; i < n; i++)	for (j = i + 1; j < n; j++)
			if (bridge[i][j])
				printf("%d - %d\n", i, j);
		puts("");
	}
}
