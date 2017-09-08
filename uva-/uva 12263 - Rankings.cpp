#include<bits/stdc++.h>
using namespace std;

const int maxn = 700500;

int ra[maxn], inDeg[maxn];

int adj[550][550];

int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	while (T--){
		int n; scanf("%d", &n);
		memset(inDeg, 0, sizeof(inDeg));
		memset(adj, 0, sizeof(adj));
		for (int i = 0; i < n; i++) scanf("%d", ra + i);
		for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++)
			adj[ra[i]][ra[j]] = 1;
		int m; scanf("%d", &m);
		for (int i = 0; i < m; i++){
			int u, v; scanf("%d%d", &u, &v);
			swap(adj[u][v], adj[v][u]);
		}
		for (int i = 1; i <= n; i++){
			inDeg[i] = 0;
			for (int j = 1; j <= n; j++)
				inDeg[i] += adj[j][i];
		}
		queue<int> q; 
		for (int i = 1; i <= n; i++) if (inDeg[i] == 0)	 q.push(i);
		vector<int> pa;
		while (!q.empty()){
			int u = q.front(); q.pop();
			pa.push_back(u);
			for (int v = 1; v <= n; v++) if (adj[u][v])
				if (--inDeg[v] == 0)
					q.push(v);
		}
		if (pa.size() != n) puts("IMPOSSIBLE");
		else{
			for (int i = 0; i < pa.size(); i++)
				printf("%d%s", pa[i], i + 1 == pa.size() ? "\n" : " ");
		}
	}
}
