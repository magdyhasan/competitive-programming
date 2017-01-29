#include<stdlib.h>
#include<stdio.h>
#include<cstring>
using namespace std;

int n, x, y;
int adj[122][122];
int seen[122], mr[122], mc[122];

bool dfs(int u){
	for (int v = 0; v < 122;v++)
		if (adj[u][v] && seen[v] == 0) { // if there's an edge to v and we havn't tried it yet
			seen[v] = 1;
			if (mc[v] == -1 || dfs(mc[v])) { // if v is not matched yet or we can matched to another one
				mr[u] = v;
				mc[v] = u;
				return true;
			}
		}
	return false;
}

int match(){
	memset(mr, -1, sizeof(mr));
	memset(mc, -1, sizeof(mc));
	int matched = 0;
	for (int i = 0; i < 122; i++) 
		if(mr[i] == -1){ // if this row hasn't been mathced to anything yet
			memset(seen, 0, sizeof(seen));
			if (dfs(i)) // try to match it
				matched++;
		}
	return matched;
}

int main(){
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		memset(adj, 0, sizeof(adj));
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d%d", &x, &y), adj[x][y] = 1; // add edge between x,y
		printf("%d\n", match());
	}
}
