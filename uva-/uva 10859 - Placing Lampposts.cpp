#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 1005;

int dp[maxn][2], dp1[maxn][2];
bool vis[maxn];
vector<int> adj[maxn];

void rec(int u){
	vis[u] = 1;
	dp[u][0] = dp1[u][0] = dp1[u][1] = 0;
	dp[u][1] = 1;
	for (int v : adj[u]) if (!vis[v]){
		rec(v);
		dp[u][1] += min(dp[v][0], dp[v][1]);
		if (dp[v][0] != dp[v][1])
			dp1[u][1] += (dp[v][0] < dp[v][1]) ? dp1[v][0] : (dp1[v][1] + 1);
		else
			dp1[u][1] += max(dp1[v][0], dp1[v][1] + 1);
		dp[u][0] += dp[v][1];
		dp1[u][0] += dp1[v][1];
	}
}

int main(){
	freopen("uva.txt", "rt", stdin);
	int T; scanf("%d", &T);
	while (T--){
		int n, m;	 scanf("%d%d", &n, &m);
		for (int i = 0; i <= n; i++) adj[i].clear(), vis[i] = 0;
		int u, v;
		for (int i = 0; i < m; i++){
			scanf("%d%d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int mivc = 0, mx2 = 0;
		for (int i = 0; i < n; i++) if (!vis[i]){
			rec(i);
			mivc += min(dp[i][0], dp[i][1]);
			if (dp[i][0] == dp[i][1]) mx2 += max(dp1[i][0], dp1[i][1]);
			else mx2 += (dp[i][0] < dp[i][1]) ? dp1[i][0] : dp1[i][1];
		}
		printf("%d %d %d\n", mivc, mx2, m - mx2);
	}
}
