#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int adj[22][22];
int n, m;

int dp[(1 << 11)][(1 << 11)][21][2];

int rec(int fi, int se, int u, bool f){
	if (f && !fi && !se) return 0;
	if (!f && u+1 == n && fi == 1 << (n >> 1) && se == 1 << ((n + 1) >> 1)) // reached n-1 node after visiting all nodes
		return rec(fi, se, u, 1); 

}

int main(){
    freopen("uva.txt","rt",stdin);
	while (scanf("%d%d", &n, &m) != EOF){
		memset(adj, 63, sizeof(adj));
		int u, v;
		for (int i = 0; i < m; i++){
			scanf("%d%d", &u, &v);
			adj[u][v] = adj[v][u] = 1;
		}
		for (int k = 0; k < n; k++)	 for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
			adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

	}

}
