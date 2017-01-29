#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;

const int maxn = 105;



typedef pair<int, int> pii;
vector<pii> adj[maxn];
vector<int> ssp, ssb;
bool out[maxn], can[maxn], vis[maxn];
int n, m, e, b, p;


vector<int> dijkstra(int s){
	vector<int> di(maxn, 123456789);
	priority_queue < pii, vector<pii>, greater<pii> > pq;
	pq.push({ 0, s });
	di[s] = 0;
	while (pq.empty() == false){
		int u = pq.top().second;	int du = pq.top().first; pq.pop();
		for (pii v : adj[u])
			if (di[v.first] > du + v.second)
				pq.push({ du + v.second, v.first }), di[v.first] = du + v.second;
	}
	return di;
}

bool test(){
	queue<int> q;
	memset(vis, 0, sizeof(vis));
	q.push(b);	vis[b] = 1;
	while (q.empty() == false){
		int u = q.front(); q.pop();
		for (pii v : adj[u])
			if (can[v.first] && vis[v.first] == false){
				if (out[v.first]) return true;
				vis[v.first] = true;
				q.push(v.first);
			}
	}
	return false;
}

double solve(){
	if (out[b]) return 0.;
	if (e == 1 && out[p]) return -1.;
	double l = 0.000001, r = double(1e10), m, tp, tb;
	for (int it = 0; it < 300; it++){
		memset(can, 0, sizeof(can));
		m = (l + r) / 2.;
		for (int i = 1; i <= n; i++){
			tp = double(ssp[i]) / 160.;
			tb = double(ssb[i]) / m;
			if (tb < tp) can[i] = 1;
		}
		if (test()) r = m;
		else l = m;
	}
	return (l < double(1e10)-10.) ? l:-1.;
}

int main(){
    //freopen("uva.txt","rt",stdin);
	int T;
	scanf("%d", &T);
	int u, v, l;
	while (T--){
		for (int i = 0; i < maxn; i++) 
			out[i] = false, adj[i].clear();
		scanf("%d%d%d", &n, &m, &e);
		for (int i = 0; i < m; i++){
			scanf("%d%d%d", &u, &v, &l);
			adj[u].push_back({ v, l });
			adj[v].push_back({ u, l });
		}
		for (int i = 0; i < e; i++){
			scanf("%d", &u);
			out[u] = true;
		}
		scanf("%d%d", &b, &p);
		ssp = dijkstra(p); ssb = dijkstra(b);
		double ret = solve();
		if (ret < 0.) puts("IMPOSSIBLE");
		else printf("%.9f\n", ret);
	}
}
