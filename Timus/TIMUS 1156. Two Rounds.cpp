#include<bits/stdc++.h>
using namespace std;

const int maxn = 10050;

int f;
int vis[maxn];

vector<int> r[maxn][2];
vector<int> adj[maxn];

int cur;

void dfs(int u, int co){
	if (f == -1) return;
	if (vis[u] != -1 && vis[u] != co) {
		f = -1;
		return;
	}
	if (vis[u] != -1) return;
	vis[u] = co;
	r[cur][co - 1].push_back(u);
	for (int v : adj[u])
		dfs(v, 3 - co);
}
int n, m;

int dp[105][105][105];

int rec(int idx, int s1, int s2){
	if (idx == cur) return s1 == s2;
	int &ret = dp[idx][s1][s2];
	if (ret != -1) return ret;
	ret = rec(idx + 1, s1 + r[idx][0].size(), s2 + r[idx][1].size());
	if (ret == 0)
		ret = rec(idx + 1, s1 + r[idx][1].size(), s2 + r[idx][0].size());
	return ret;
}
vector<int> ret1, ret2;

void build(int idx, int s1, int s2){
	if (idx == cur) return;
	int &ret = dp[idx][s1][s2];
	if (rec(idx + 1, s1 + r[idx][0].size(), s2 + r[idx][1].size())){
		for (int i : r[idx][0]) ret1.push_back(i);
		for (int i : r[idx][1]) ret2.push_back(i);
		build(idx + 1, s1 + r[idx][0].size(), s2 + r[idx][1].size());
	}
	else{
		for (int i : r[idx][0]) ret2.push_back(i);
		for (int i : r[idx][1]) ret1.push_back(i);
		build(idx + 1, s1 + r[idx][1].size(), s2 + r[idx][0].size());
	}
}


int main(){
    freopen("uva.txt","rt",stdin);
	scanf("%d%d", &n, &m);
	n *= 2;
	for (int i = 0; i <= n; i++) vis[i] = -1;
	for (int i = 0; i < m; i++){
		int u, v; 
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cur = 0;
	for (int i = 1; i <= n; i++) 
		if (vis[i] == -1) dfs(i, 1), cur++;
	if (f == -1) {
		puts("IMPOSSIBLE"); return 0;
	}

	memset(dp, -1, sizeof(dp));
	if (rec(0, 0, 0) == 0) {
		puts("IMPOSSIBLE"); return 0;
	}
	build(0, 0, 0);
	for (int i : ret1) printf("%d ", i); puts("");
	for (int i : ret2) printf("%d ", i); puts("");
}

