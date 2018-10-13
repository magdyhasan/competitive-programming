/*
	notice we can solve with MaxFlow

	first we make source give edges to all teams with edge cost = 1
	becuase each team can belong to one career only

	now for team we connect to each career with constraint as stated in problem

	now we make edges between sink and careers with edge cost = k, 
	because each career can have up to k teams

	now just runs max flow
*/
#include<bits/stdc++.h>
using namespace std;


const int maxn = 1000500;

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

char st[100500];

int main(){
	memset(head, -1, sizeof(head));
	e = 0;
	// s is 0
	// teams are [1,n]
	// carrers are [n+1,n+28]
	// target is[n+50]
	int n, K; scanf("%d", &n);
	int s = 0, t = n + 250;
	for (int i = 1; i <= n; i++) addEdge(s, i, 1); // between source and teams
	for (int i = 1; i <= n; i++){
		map<char, int> cnt;
		for (int j = 0; j < 3; j++){
			scanf("%s", st);
			for (int k = 0; st[k]; k++){
				cnt[st[k]]++;
			}
		}
		int mx = -1;
		for (auto it : cnt) mx = max(mx, it.second);
		for (auto it : cnt) if (it.second == mx){// between teams and careers
			addEdge(i, (it.first - 'A') + 1 + n, 1);
		}
	}
	scanf("%d", &K);
	for (char c = 'A'; c <= 'Z'; c++)// between careers and sink
		addEdge((c - 'A') + 1 + n, t, K);
	printf("%d\n", maxflow(s, t));
}