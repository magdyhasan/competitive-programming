#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


struct edge{
	int to, roadId;
	edge(int a = 0, int b = 0) :to(a), roadId(b)	{}
	bool operator < (const edge &a) const{
		return roadId < a.roadId;
	}
};


vector<edge> adj[55];
bool vis[2000];
int e;
vector<int> path;

void dfs(int u){
	for (auto v : adj[u])
		if (!vis[v.roadId]) {
			vis[v.roadId] = true;
			dfs(v.to);
			path.push_back(v.roadId);
		}
	return;
}


int main(){
    freopen("uva.txt","rt",stdin);
	while (true) {
		for (int i = 0; i < 55; i++)	adj[i].clear();
		e = 0;
		int a, b, c, st;
		while (scanf("%d%d",&a,&b) == 2) {
			if (!a && !b)	break;
			if (e == 0)	st = min(a, b);
			scanf("%d", &c);
			adj[a].push_back(edge{ b, c });
			adj[b].push_back(edge{ a, c });
			e++;
		}
		if (!e)	break;
		bool f = true;
		for (int i = 0; i < 55; i++)// euler cycle all junction must have even degree
			sort(adj[i].begin(), adj[i].end()), f &= (adj[i].size() % 2 == 0);
		if (!f)	puts("Round trip does not exist.\n");
		else {
			path.clear();
			memset(vis, 0, sizeof(vis));
			dfs(st);
			for (int i = path.size() - 1; i >= 0; i--)
				printf("%d%s", path[i], i ? " " : "\n");
			puts("");
		}
	}
}
