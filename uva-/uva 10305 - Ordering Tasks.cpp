#include<stdlib.h>
#include<stdio.h>
#include<cstring>
using namespace std;

int n, m, from, to;
bool adj[105][105], used[105];


int ans[105], cnt;

void dfs(int u){
	used[u] = true;
	for (int i = 1; i <= n; i++)
		if (adj[u][i] && used[i] == false)
			dfs(i);
	ans[cnt++] = u;
}

int main(){
	while (scanf("%d%d", &n, &m)) {
		if (n == 0 && m == 0)
			break;
		memset(adj, 0, sizeof(adj));
		memset(used, 0, sizeof(used));
		for (int i = 0; i < m; i++)
			scanf("%d%d", &from, &to), adj[from][to] = 1;
		cnt = 0;
		for (int i = 1; i <= n; i++)
			if (used[i] == false)
				dfs(i);
		for (int i = cnt - 1; i >= 0; i--)
			printf("%d%s", ans[i], (i) ? " " : "");
		puts("");
	}
}
