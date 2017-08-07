#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

const int maxn = 300500;

int sz[maxn], mxsz[maxn];
vector<int> adj[maxn];
int n;

void dfs(int u, int p){
	sz[u] = 1;
	for (int i = 0; i < adj[u].size(); i++) if (adj[u][i] != p){
		dfs(adj[u][i], u);
		sz[u] += sz[adj[u][i]];
		mxsz[u] = max(mxsz[u], sz[adj[u][i]]);
	}
	mxsz[u] = max(mxsz[u], n - sz[u]);
}

int main(){
	freopen("uva.txt", "r", stdin);
	scanf("%d", &n);
	int u, v;
	for (int i = 0; i + 1 < n; i++){
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, -1);
	int mx = 123456789;
	for (int i = 1; i <= n; i++)
			mx = min(mx,mxsz[i]);
	bool fi = 1;
	for (int i = 1; i <= n; i++) if (mxsz[i] == mx)
		printf("%s%d", fi?"":" ",  i), fi = 0;
	puts("");
}