#include<bits/stdc++.h>
using namespace std;

const int maxn = 300500;

int vis[35][1 << 9];
int sho[maxn];

int nho, n;

typedef pair<double, pair<int,int>> pii;

vector<pair<int, int>> adj[maxn];

double dijskstra(int s, int t){
	memset(vis, 0, sizeof(vis));
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(make_pair(0, make_pair((1 << nho) - 1, s)));
	while (!pq.empty()){
		pii u = pq.top(); pq.pop();
		if (u.second.second == t) return u.first;
		if (vis[u.second.second][u.second.first]) continue;
		vis[u.second.second][u.second.first] = 1;
		for (auto v : adj[u.second.second]) for (int ho = 0; ho < nho; ho++) 
			if ((u.second.first&(1 << ho)) && !vis[v.first][u.second.first & (~(1 << ho))]){
			pq.push(make_pair(u.first + 1.*v.second / sho[ho], make_pair(u.second.first & (~(1 << ho)), v.first)));
		}
	}
	return -1;
}


int main(){
    freopen("uva.txt","rt",stdin);
	int m, a, b;
	while (scanf("%d%d%d%d%d", &nho, &n, &m, &a, &b)){
		if (!nho&&!n) break;
		int u, v, co;
		for (int i = 0; i < maxn; i++) adj[i].clear();
		for (int i = 0; i < nho; i++) scanf("%d", &sho[i]);
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &u, &v, &co);
			adj[u].push_back(make_pair(v, co));
			adj[v].push_back(make_pair(u, co));
		}
		double ret = dijskstra(a, b);
		if (ret < 0) puts("Impossible");
		else printf("%lf\n", ret);
	}
}
