/*
	just do semi-dijkstra and keep a vector of your current path
*/
#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<functional> // for greater sort
#include<queue>
using namespace std;

int n, m;


vector<pair<int, int>> adj[105];
bool any;

void dijkstra(int s, int t, int k){
	priority_queue<pair<int, pair<int, vector<int>>>, vector<pair<int, pair<int, vector<int>>>>, greater<pair<int, pair<int, vector<int>>>>> pq;
	pq.push({ 0, { s, { s } } });
	while (!pq.empty()){
		int u = pq.top().second.first, co = pq.top().first;
		vector<int> p = pq.top().second.second;
		pq.pop();
		if (co > k) break;
		if (u == t){
			printf(" %d:", co);
			for (int i : p) printf(" %d", i);
			puts("");
			any = true;
			continue;
		}
		for (pair<int, int> v : adj[u]) if (count(p.begin(), p.end(), v.first) == 0){
			p.push_back(v.first);
			pq.push({ co + v.second, { v.first, p } });
			p.pop_back();
		}
	}
}


int main(){
    freopen("uva.txt","rt",stdin);
	int tc = 0;
	while (scanf("%d", &n)){
		if (n == -1) break;
		if (tc) puts("");
		scanf("%d", &m);
		printf("Case %d:\n",++tc);
		int u, v, c;
		for (int i = 0; i < n; i++) adj[i].clear();
		for (int i = 0; i < m; i++){
			scanf("%d%d%d", &u, &v, &c);
			adj[u].push_back({ v, c });
			adj[v].push_back({ u, c });
		}
		for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());
		int s, t, k;
		scanf("%d%d%d", &s, &t, &k);
		any = false;
		dijkstra(s, t, k);
		if (!any) puts(" NO ACCEPTABLE TOURS");
	}
}
