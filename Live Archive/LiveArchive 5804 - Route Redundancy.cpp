/*
problem is just asking for total flow / maximum flow of one path

if at first we found path that maximize  minimum edge on path(maximum flow of path),
with modified dijkstra, then minimum edge on this path
will be our maximum flow of one path

so just run max flow with modified dijkstra to find max flow on path on first run
*/
#include<bits/stdc++.h>
#include<functional> // for greater sort
using namespace std;

typedef pair<int, int> node;

const int maxn = 300500;

int vis[maxn];
int prv[maxn];
int cap[1005][1005];
int co[1005][1005];

vector<int> adj[maxn];

int dijskstra(int S, int T){
	memset(vis, 0, sizeof(vis));
	memset(prv, -1, sizeof(prv));
	priority_queue<node, vector<node>, less<node> > pq;
	pq.push(node(10500, S));
	while (pq.empty() == false) {
		node u = pq.top();
		pq.pop();
		if (u.second == T)	return u.first;
		if (vis[u.second])	continue;
		vis[u.second] = 1;
		for (int v : adj[u.second])
			if (vis[v] == false && cap[u.second][v] > 0){
			pq.push(node{ min(cap[u.second][v], u.first), v });
			prv[v] = u.second;
			}
	}
	return 0;
}

pair<int, int> maxFlow(int src, int sink){
	int total_flow = 0, maxEdge = 0;
	while (true)
	{
		int newflow = dijskstra(src, sink);
		if (!newflow) break;	// once no more paths, STOP
		int t = sink;
		while (prv[t] != -1){
			int a = prv[t], b = t;
			cap[a][b] -= newflow;
			cap[b][a] += newflow;
			t = prv[t];
		}
		if (total_flow == 0){
			maxEdge = newflow;
		}
		total_flow += newflow;
	}
	return{ total_flow, maxEdge };
}

int main(){
	int tc; scanf("%d", &tc);
	while (tc--){
		int n, m, A, B;
		int da;
		scanf("%d%d%d%d%d", &da, &n, &m, &A, &B);
		for (int i = 0; i < m; i++){
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			cap[u][v] = co[u][v] = c;
			adj[u].push_back(v);
		}
		auto ret = maxFlow(A, B);
		printf("%d %.3lf\n", da, (ret.first*1.) / double(ret.second));
	}
}

