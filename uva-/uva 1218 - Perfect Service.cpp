/*
	it can be solved with dp,
	where our state is dp[nodes][3]

	dp[u][0]: u parent is a server
	dp[u][1]: u parent is not a server but grandparent is server
	dp[u][2]: u parent is not a server and grandparent isn't a server
*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 300500;

vector<int> adj[maxn];

int dp[maxn][3];
int n, tc;


int rec(int u, int st, int p = -1){
	int &ret = dp[u][st];
	if (ret != -1) return ret;
	ret = n;
	// make u a server
	if (st != 1 || u == 1){
		int s = 0;
		for (int v : adj[u]) if (v != p)
			s += rec(v, 0, u);
		ret = min(ret, s + 1);
	}
	//make u not a server
	if (st != 2 && (st != 1 || (adj[u].size() - (p != -1) > 0))){
		int s = 0;
		for (int v : adj[u]) if (v != p){
			s += rec(v, st + 1, u);
		}
		ret = min(ret, s);
	}
	return ret;
}


int main(){
	freopen("uva.txt", "r", stdin);
	while (scanf("%d", &n)){
		for (int i = 0; i <= n; i++)adj[i].clear();
		for (int i = 0; i + 1 < n; i++){
			int u, v; scanf("%d%d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		memset(dp, -1, sizeof(dp));
		printf("%d\n", rec(1, 1));
		scanf("%d", &tc);
		if (tc == -1) break;
	}
}
