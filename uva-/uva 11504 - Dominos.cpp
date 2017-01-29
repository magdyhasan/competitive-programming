#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<cstring>
using namespace std;

int n, m, x, y;

vector< vector<int> > adj;
vector<int> toposort;
bool vis[100500];
bool first;

void dfs(int u){ 
	vis[u] = 1;
	for (auto v : adj[u])
		if (!vis[v])
			dfs(v);
	if (first) // if we are at the first dfs get the topological order
		toposort.push_back(u);
	return;
}

int main(){
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &n, &m);
		int ret = 0;
		adj = vector< vector<int> >(n + 1);
		toposort = vector<int>();
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &x, &y);
			adj[x].push_back(y);
		}
		memset(vis, 0, sizeof(vis));
		first = 1;
		for (int i = 1; i <= n; i++) // first dfs to get the order
			if (!vis[i])
				dfs(i);

		memset(vis, 0, sizeof(vis));
		reverse(toposort.begin(), toposort.end());
		first = 0;
		for (auto u : toposort) // start from the end of the topological order and construct each possible component
			if (!vis[u])
				dfs(u), ret++;
		printf("%d\n", ret);
	}
}
