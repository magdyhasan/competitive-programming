#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional> // for greater sort
using namespace std;

int d[105][11], vis[105];
vector<pair<int,int>> adj[105];

void dijkstra(int s, int t, int k){
	memset(d, -1, sizeof(d));
	priority_queue<pair<int, int> ,vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, s });
	while (!pq.empty()){
		int u = pq.top().second, co = pq.top().first;
		pq.pop();
		if (vis[u] > k) continue;
		d[u][vis[u]] = co;
		vis[u]++;
		for (pair<int, int> v : adj[u])
			pq.push({ co + v.second, v.first });
	}
}

int main(){
    freopen("uva.txt","rt",stdin);
	int n, m;
	while (scanf("%d%d", &n, &m)){
		if (!n && !m) break;
		int s, t, k;	
		scanf("%d%d%d", &s, &t, &k);
		for (int i = 0; i < 105; i++)
			adj[i].clear(), vis[i] = 0;
		for (int i = 0; i < m; i++){
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			adj[u].push_back({ v, c });
		}
		dijkstra(s, t, k);
		printf("%d\n", d[t][k - 1]);
	}
}
