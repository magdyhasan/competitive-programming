#include<bits/stdc++.h>
using namespace std;


const int maxn = 8850;

int head[maxn], d[maxn], prv[maxn], record[maxn];

struct Node{
	int u, v, c;
	int nxt;
} edge[maxn];
int e;

void addEdge(int u, int v, int c){
	//forward edge
	edge[e].u = u, edge[e].v = v, edge[e].c = c;
	edge[e].nxt = head[u], head[u] = e++;
	//backward edge
	edge[e].u = v, edge[e].v = u, edge[e].c = 0;
	edge[e].nxt = head[v], head[v] = e++;
}

int maxflow(int s, int t){
	int flow = 0;
	while (true){
		memset(d, 0, sizeof(d));
		d[s] = 123456789;
		queue<int> q;
		q.push(s);
		while (!q.empty()){
			int u = q.front();	 q.pop();
			if (u == t) break;
			for (int i = head[u]; i != -1; i = edge[i].nxt)
				if (d[edge[i].v] == 0 && edge[i].c > 0){
				q.push(edge[i].v);
				d[edge[i].v] = min(d[u], edge[i].c);
				prv[edge[i].v] = u, record[edge[i].v] = i;
				}
		}
		if (d[t] == 0) break;
		flow += d[t];
		for (int u = t; u != s; u = prv[u]){
			int ed = record[u];
			edge[ed].c -= d[t];
			edge[ed ^ 1].c += d[t];
		}
	}
	return flow;
}


vector<int> adj[55];


int main(){
	freopen("uva.txt", "r", stdin);
	int n, m, k;
	while (scanf("%d%d%d", &n, &m, &k)){
		if (!n&&!m&&!k) break;
		for (int i = 0; i < 55; i++) adj[i].clear();
		for (int i = 0; i < n; i++){
			int cnt, v; scanf("%d", &cnt);
			while (cnt--){
				scanf("%d", &v); v--;
				adj[i].push_back(v);
			}
		}
		int ret = 0, s = 0, t = n + m + 1;
		int l = 0, r = k;
		while (l <= r){
			int nu = (l + r) / 2;
			memset(head, -1, sizeof(head));
			e = 0;
			for (int i = 0; i < n; i++)// add edges from source to students with how many courses they can register
				addEdge(s, i + 1, nu);
			for (int i = 0; i < n; i++) for (int j = 0; j < adj[i].size(); j++)// add edges from student to courses
				addEdge(i + 1, adj[i][j] + n + 1, 1);
			for (int i = 0; i < m; i++)// add edges from courses to sink with k cost
				addEdge(n + i + 1, t, k);
			int mx = maxflow(s, t);
			if (mx == nu*n) ret = nu, l = nu + 1;
			else r = nu - 1;
		}
		printf("%d\n", ret);
	}
}