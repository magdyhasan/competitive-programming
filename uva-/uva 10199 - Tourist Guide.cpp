#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

const int maxn = 105;

bool art[maxn];
int dfs_num[maxn], dfs_low[maxn], dfs_p[maxn], dfs_n, dfsRoot, rootChildren;
vector<int> adj[maxn];

void find_art(int u){
	dfs_num[u] = dfs_low[u] = dfs_n++;
	for (int v : adj[u]){
		if (dfs_num[v] == -1){
			dfs_p[v] = u;
			if (u == dfsRoot) rootChildren++;
			find_art(v);
			if (dfs_low[v] >= dfs_num[u]) art[u] = true;
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if (dfs_p[u] != v)
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
	}
}


map<string, int> id;
string names[maxn];


int main(){
    freopen("uva.txt","rt",stdin);
	int n, T = 0;	
	while (scanf("%d", &n)){
		if (!n) break;
		if (T) puts("");
		T++;
		int i = 0;
		for (i = 0; i <= n; i++)
			adj[i].clear(), dfs_num[i] = -1, art[i] = 0;
		memset(art, 0, sizeof(art));
		id.clear();
		dfs_n = 0;
		char st[100], st1[100];
		for (i = 0; i < n; i++){
			scanf("%s", st);
			id[st];
		}
		i = 0;
		for (auto &it : id)
			it.second = i, names[i++] = it.first;
		int m;
		scanf("%d", &m);
		for (int i = 0; i < m; i++){
			int u, v;
			scanf("%s%s", st, st1);
			adj[id[st]].push_back(id[st1]);
			adj[id[st1]].push_back(id[st]);
		}
		for (int i = 0; i < n; i++) if (dfs_num[i] == -1){
			rootChildren = 0;
			dfsRoot = i;
			find_art(i);
			art[i] = rootChildren > 1; // root can only be art point if it have children > 1
		}
		int artCnt = 0;
		for (i = 0; i < n; i++)
			artCnt += art[i];
		printf("City map #%d: %d camera(s) found\n", T, artCnt);
		for (int i = 0; i < n; i++) if (art[i])
			puts(names[i].c_str());
	}
}
