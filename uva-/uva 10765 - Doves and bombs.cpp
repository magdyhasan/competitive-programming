/*
 find all articulation point, and count how many nodes got affected by this node if removed
 handle root (0) as after removing it we need one less pigeons
*/

#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 10005;

int art[maxn];
int n, m;
int dfs_num[maxn], dfs_low[maxn], dfs_p[maxn], dfs_n, dfsRoot, rootChildren;

vector<int> adj[maxn];

vector<pair<int, int>> ret;

void find_art(int u){
	dfs_num[u] = dfs_low[u] = dfs_n++;
	for (int v : adj[u])
		if (dfs_num[v] == -1) { // a tree edge
			dfs_p[v] = u;
			find_art(v);
			if (dfs_low[v] >= dfs_num[u]) // if we couldn't reach u from v from another path 
				art[u] ++;
			dfs_low[u] = min(dfs_low[u], dfs_low[v]); // u can reach what it's children v can reach
		}
		else if (v != dfs_p[u]) // a back edge and not direct cycle
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
	if (u == 0) art[u]--;
	ret.push_back({ art[u] + 1, u });
}

bool cmp(pair<int, int> &a, pair<int, int>&b){
	if (a.first != b.first) return a.first > b.first;
	return a.second < b.second;
}

int main(){
    freopen("uva.txt","rt",stdin);
	while (scanf("%d%d", &n, &m) ){
		if (!n && !m) break;
		for (int i = 0; i <= n; i++)
			adj[i].clear();
		ret.clear();
		int u, v;
		while (scanf("%d%d", &u, &v)){
			if (u == -1 && v == -1) break;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		memset(dfs_num, -1, sizeof(dfs_num));
		memset(art, 0, sizeof(art));
		dfsRoot = 0;
		find_art(0);
		sort(ret.begin(), ret.end(), cmp);
		for (int i = 0; i < m; i++)
			printf("%d %d\n", ret[i].second, ret[i].first);
		puts("");
	}
}
