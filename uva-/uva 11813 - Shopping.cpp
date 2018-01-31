/*
	since number of houses to visit <= 10
	find all distances between houses to visits using normal dijkstra

	now notice this just TSP problem where we need to visit <= 10 houses and return to home
	so just dp with bitmasking will work
*/
#include<bits/stdc++.h>
#include<functional>
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;


const int maxn = 300500;

int n, m;
vpii adj[maxn];

vi dijkstra(int s){
	vi vis(n+1, 123456789);
	priority_queue<pii, vpii, greater<pii>> pq;
	pq.push({ 0, s });
	while (!pq.empty()){
		pii u = pq.top(); pq.pop();
		if (vis[u.second] != 123456789) continue;
		vis[u.second] = u.first;
		for (auto v : adj[u.second]) if (vis[v.second] == 123456789){
			pq.push({ v.first + u.first, v.second });
		}
	}
	return vis;
}
int nvis;
int no[12];
int co[12][12];

int dp[12][(1 << 12)];

int rec(int u, int msk){
	if (msk == (1 << nvis)-1) return co[u][0];
	int &ret = dp[u][msk];
	if (ret != -1)return ret;
	ret = 123456789;
	for (int v = 0; v < nvis; v++) if (!(msk&(1 << v))){
		ret = min(ret, rec(v, msk | (1 << v)) + co[u][v]);
	}
	return ret;
}

int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	while (T--){
		for (int i = 0; i < maxn; i++) adj[i].clear();
		scanf("%d%d", &n, &m);
		int u, v, c;
		while (m--){
			scanf("%d%d%d", &u, &v, &c);
			adj[u].push_back({ c, v });
			adj[v].push_back({ c, u });
		}
		scanf("%d", &nvis);
		bool f = 0;
		for (int i = 0; i < nvis; i++) {
			scanf("%d", no + i);
			if (no[i] == 0) f = 1;
		}
		if (!f){
			nvis++;
			for (int i = nvis - 1; i > 0; i--) no[i] = no[i - 1];
			no[0] = 0;
		}
		else if(no[0] != 0){
			for (int i = 0; i < nvis; i++) if (no[i] == 0) swap(no[i], no[0]);
		}
		for (int i = 0; i < nvis; i++){
			vi di = dijkstra(no[i]);
			for (int j = 0; j < nvis; j++) {
				co[i][j] = di[no[j]];
			}
		}
		memset(dp, -1, sizeof(dp));
		printf("%d\n", rec(0, 1));
	}
}
