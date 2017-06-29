#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;


const int maxn = 10500;

bool art[maxn];
int n, m;
int dfs_num[maxn], dfs_low[maxn], dfs_p[maxn], dfs_n, dfsRoot, rootChildren;

vector<int> adj[maxn];

void find_art(int u){
	dfs_low[u] = dfs_num[u] = dfs_n++;
	for (int v : adj[u]){
		if (dfs_num[v] == -1){
			dfs_p[v] = u;
			if (u == dfsRoot) rootChildren++;
			find_art(v);
			if (dfs_low[v] >= dfs_num[u]) art[u] = 1;
			dfs_low[u] = min(dfs_low[v], dfs_low[u]);
		}
		else if(dfs_p[u] !=  v)
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
	}
}



int main(){
    freopen("uva.txt","rt",stdin);
	int i;
	while (scanf("%d%d", &n, &m)) {
		if (!n && !m) break;
		dfs_n = 0;
		for (i = 0; i <= n; i++)
			adj[i].clear(), dfs_num[i] = -1, art[i] = 0;
		// read inputs and adj
		for (i = 0; i < m; i++) {
			int u, v; scanf("%d%d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for (int i = 1; i <= n; i++) if (dfs_num[i] == -1){
			dfsRoot = i;
			rootChildren = 0;
			find_art(i);
			art[i] = rootChildren > 1;
		}
		int artCnt = 0;
		for (i = 1; i <= n; i++)
			artCnt += art[i];
		printf("%d\n", artCnt);
	}
}
