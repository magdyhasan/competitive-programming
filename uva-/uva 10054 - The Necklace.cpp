#include<stdlib.h>
#include<stdio.h>
#include<cstring>
using namespace std;


int g[60][60], path[1005], path_len;
int n, a, b;

void dfs(int u){
	for (int v = 1; v < 60;v++)
		if (g[u][v]) {
			g[u][v]--;
			g[v][u]--;
			dfs(v);
		}
	path[path_len++] = u;
}

void check(){
	for (int i = 1; i < 60; i++) {
		int sum = 0;
		for (int j = 1; j < 60; j++)
			sum += g[i][j];
		if (sum % 2) {
			puts("some beads may be lost");
			return;
		}
	}
	path_len = 0;
	dfs(a);
	for (int i = 0; i < path_len - 1; i++)
		printf("%d %d\n", path[i], path[i + 1]);
}


int main(){
	int tc;
	scanf("%d", &tc);
	for (int tt = 1; tt <= tc; tt++) {
		printf("Case #%d\n", tt);
		memset(g, 0, sizeof(g));
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d%d", &a, &b), g[a][b]++, g[b][a]++;
		check();
		if (tt != tc)
			puts("");
	}
}
