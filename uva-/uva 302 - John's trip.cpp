#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<vector>
#include<algorithm>
#include<utility>
#include<deque>
using namespace std;

#define mp(a,b) make_pair(a,b)
#define to second
#define id first

vector< vector< pair<int, int> > > adj(45);
int vis[2005];
int degree[45];

int a, b, _id, start, n;

void add_street(){
	adj[a].push_back(mp(_id, b));
	adj[b].push_back(mp(_id, a));
	degree[a]++;
	degree[b]++;
	return;
}

vector<int> path;

void dfs(int u){
	for (auto v : adj[u])
		if (vis[v.id] == 0) {
		vis[v.id] = 1;
		dfs(v.to);
		path.push_back(v.id);
		}
	return;
}


void solve(){
	path = vector<int>();
	for (int i = 0; i < 45; i++) {
		if (degree[i] % 2) { // if any junctions degree is odd then we can't have euler tour
			puts("Round trip does not exist.\n");
			return;
		}
		sort(adj[i].begin(), adj[i].end()); // sort edges because we want them lexigrophicaly smallest
	}
	memset(vis, 0, sizeof(vis));
	dfs(start); // find euler tour
	reverse(path.begin(), path.end()); // revese the path
	for (int i = 0; i < path.size(); i++)
		printf("%d%s", path[i], (i == path.size() - 1) ? "\n\n" : " ");
	return;
}

int main(){
	while (scanf("%d%d", &a, &b) && a && b) {
		adj = vector< vector< pair<int, int> > >(45);
		memset(degree, 0, sizeof(degree));
		start = min(a, b); // start is the minimum of a,b
		scanf("%d", &_id);
		add_street();
		while (scanf("%d%d", &a, &b) && a && b) {
			scanf("%d", &_id);
			add_street();
		}
		solve();
	}
}
