#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<sstream>
using namespace std;

bool art[105];
int n;
int dfs_num[105], dfs_low[105], dfs_p[105], dfs_n, dfsRoot, rootChildren;

vector<int> adj[105];

void find_art(int u){
	dfs_num[u] = dfs_low[u] = dfs_n++;
	for (int v : adj[u])
		if (dfs_num[v] == -1) {
			dfs_p[v] = u;
			if (u == dfsRoot) // handle special case of root 
				rootChildren++;
			find_art(v);
			if (dfs_low[v] >= dfs_num[u])
				art[u] = true;
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if (v != dfs_p[u])
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
}

int main(){
    freopen("uva.txt","rt",stdin);
	int i, a, b;
	string line;
	istringstream iss;
	while (scanf("%d",&n)) {
		if (!n)	break;
		for (i = 0; i <= n; i++)
			adj[i].clear();
		getchar();
		while (true) {
			getline(cin, line);
			iss.clear();
			iss.str(line);
			iss >> a;
			if (!a)	break;
			while (iss >> b) adj[a].push_back(b), adj[b].push_back(a);
		}
		memset(dfs_num, -1, sizeof(dfs_num));
		memset(art, 0, sizeof(art));
		for (i = 1; i <= n; i++)
			if (dfs_num[i] == -1) {
				rootChildren = 0;
				dfsRoot = i; // mark i as the current root
				find_art(i);
				art[i] = rootChildren > 1; // root can only be art point if it has children > 1
			}
		int artCnt = 0;
		for (i = 1; i <= n; i++)
			artCnt += art[i];
		printf("%d\n", artCnt);
	}
}
