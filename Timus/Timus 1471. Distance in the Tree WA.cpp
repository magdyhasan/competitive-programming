#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

const int maxn = 150500;
vector<pair<int,int>> adj[maxn];
int d[maxn];



// lca code from: http://e-maxx.ru/algo/lca_simpler
int n, lo, l = 20;
int tin[maxn], tout[maxn];
int timer;
int vis[maxn];
vector < int > up[maxn];

void dfs(int v, int p = 0) {
	tin[v] = ++timer;
	up[v][0] = p;
	for (int i = 1; i <= l; ++i)
		up[v][i] = up[up[v][i - 1]][i - 1];
	for (size_t i = 0; i<adj[v].size(); ++i) {
		int to = adj[v][i].first;
		if (to != p)
			dfs(to, v);
	}
	tout[v] = ++timer;
}

void lca_init(){ // After reading n
	l = 1;
	while ((1 << l) <= n)  ++l;
	for (int i = 0; i <= n; ++i)  up[i].resize(l + 1);
	dfs(0);
}

bool upper(int a, int b) {
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b) {
	if (upper(a, b))  return a;
	if (upper(b, a))  return b;
	for (int i = l; i >= 0; --i)
		if (!upper(up[a][i], b))
			a = up[a][i];
	return up[a][0];
}
// end lca code





int di(int u, int v){
	return d[u] + d[v] - 2 * d[lca(u, v)];
}



int main(){
    freopen("uva.txt","rt",stdin);
	#pragma comment(linker, "/STACK:1000000000")
	scanf("%d", &n);
	int u, v, w;
	for (int i = 0; i + 1 < n; i++){
		scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back({ v, w });
		adj[v].push_back({ u, w });
	}
	memset(d, -1, sizeof(d));
	queue<int> q;	q.push(0);
	d[0] = 0;
	while (!q.empty()){
		u = q.front(); q.pop();
		for (auto ad : adj[u])
			if (d[ad.first] == -1)
				d[ad.first] = d[u] + ad.second;
	}
	lca_init();
	int m; scanf("%d", &m);
	for (int i = 0; i < m; i++){
		scanf("%d%d", &u, &v);
		printf("%d\n", di(u, v));
	}
}
