#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;

const int maxn = 550;

struct state{
	int pre, u, speed;
};

vector<pair<int,int>> adj[maxn];

map<string, int> id;
int n;
char st1[100], st2[100];
string cities[maxn];

int getId(string  name){
	if (id.find(name) == id.end()) id[name] = ++n, cities[n] = name;
	return id[name];
}

int vis[maxn][maxn], prv[maxn];

bool BFS(int s, int t){
	memset(vis, 0, sizeof(vis));
	queue<state> q;
	q.push({ s, s, 0 });
	while (!q.empty()){
		state u = q.front(); q.pop();
		if (u.u == t) return true;
		for (auto v : adj[u.u])	if (!vis[u.u][v.first] && v.second >= u.speed){
			prv[u.u] = u.pre;
			prv[v.first] = u.u;
			vis[u.u][v.first] = vis[v.first][u.u] = true;
			q.push({ u.u, v.first, v.second });
			if (v.first == t) return true;
		}
	}
	return false;
}

int main(){
    freopen("uva.txt","rt",stdin);
	int m, sp;
	bool first = true;
	while (scanf("%d", &m) == 1){
		if (!first) puts("");
		first = false;
		for (int i = 0; i < maxn; i++) adj[i].clear();
		id.clear();
		n = 0;
		for (int i = 0; i < m; i++){
			scanf("%s%s%d", st1, st2, &sp);
			int u = getId(string(st1));
			int v = getId(string(st2));
			adj[u].push_back({ v, sp });
			adj[v].push_back({ u, sp });
		}
		scanf("%s%s", st1, st2);
		if (id.find(string(st1)) == id.end() || id.find(string(st2)) == id.end()){
			puts("No valid route.");
			continue;
		}
		for (int i = 0; i <= n; i++)
			sort(adj[i].begin(), adj[i].end());
		int S = id[st1], T = id[st2];
		if (!BFS(S, T)) puts("No valid route.");
		else{
			vector<int> path;
			for (int cur = T;; cur = prv[cur]){
				path.push_back(cur);
				if (cur == S) break;
			}
			for (int i = path.size() - 1; i >= 0;i--)
				printf("%s%s", (i == path.size()-1) ? "":" ", cities[path[i]].c_str());
			puts("");
		}
	}
}
