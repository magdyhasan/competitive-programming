#include<bits/stdc++.h>
using namespace std;


const int maxn = 800500;

typedef pair<int, int> pii;

vector<pii> adj[2][maxn];

int d[maxn], vis[maxn];



vector<int> dijkstra(int S, vector<pii> adj[]){
	vector<int> di(maxn, 123456789);
	priority_queue < pii, vector<pii>, greater<pii> > pq;
	pq.push({ 0, S });
	di[S] = 0;
	while (pq.empty() == false){
		int u = pq.top().second;	int du = pq.top().first; pq.pop();
		for (pii v : adj[u])
			if (di[v.first] > du + v.second)
				pq.push({ du + v.second, v.first }), di[v.first] = du + v.second;
	}
	return di;
}


int n, m, s, t, p;

int main(){
    freopen("uva.txt","rt",stdin);
	int u, v, c;
	int T; scanf("%d", &T);
	while (T--){
		scanf("%d%d%d%d%d", &n, &m, &s, &t, &p);
		for (int i = 0; i <= n; i++) adj[0][i].clear(), adj[1][i].clear();
		for (int i = 0; i < m; i++){
			scanf("%d%d%d", &u, &v, &c);
			adj[0][u].push_back(make_pair(v, c));
			adj[1][v].push_back(make_pair(u, c));
		}
		vector<int> d1 = dijkstra(s, adj[0]);
		vector<int> d2 = dijkstra(t, adj[1]);
		int mx = -1;
		for (int i = 1; i <= n; i++) for (pii v : adj[0][i])
			if (d1[i] + v.second + d2[v.first] <= p)
				mx = max(mx, v.second);
		printf("%d\n", mx);
	}
}
