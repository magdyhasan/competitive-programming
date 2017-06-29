#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

const int maxn = 300500;

int deg[maxn];
bool rem[maxn], vis[maxn];
vector<int> adj[maxn];


int main(){
    freopen("uva.txt","rt",stdin);
	int n, m, k;
	while (scanf("%d%d", &n, &m)){
		if (!n && !m) break;
		scanf("%d", &k);
		for (int i = 0; i <= n; i++) deg[i] = 0, rem[i] = 0, vis[i] = 0, adj[i].clear();
		for (int i = 0; i < m; i++){
			int u, v; 
			scanf("%d%d", &u, &v);
			deg[u]++, deg[v]++;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		queue<int> q; 
		for (int i = 1; i <= n; i++) if (deg[i] < k) q.push(i), rem[i] = 1;
		while (!q.empty()){
			int u = q.front(); q.pop();
			for (int v : adj[u]) if (!rem[v] && --deg[v] < k)				q.push(v), rem[v] = 1;
		}
		int ret = 0;
		for (int i = 1; i <= n; i++) if(!rem[i] && !vis[i]){
			q = queue<int>();
			q.push(i);
			int cur = 0;
			vis[i] = 1;
			vector<int> path;
			while (!q.empty()){
				int u = q.front(); q.pop();
				cur++;
				path.push_back(u);
				for (int v : adj[u]) if (!rem[v] && !vis[v])
					q.push(v), vis[v] = 1;
			}
			ret = max(ret, cur);
		}
		printf("%d\n", ret);
	}
}

