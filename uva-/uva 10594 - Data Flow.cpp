#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000500;

typedef long long ll;

int head[maxn], d[maxn], prv[maxn], record[maxn];


struct Node{
	int u, v, c, t;
	int nxt;
} edge[maxn];
int e;

void addEdge(int u, int v, int c, int t){
	edge[e].u = u, edge[e].v = v, edge[e].c = c, edge[e].t = t;
	edge[e].nxt = head[u], head[u] = e++;
	edge[e].u = v, edge[e].v = u, edge[e].c = 0, edge[e].t = -t;
	edge[e].nxt = head[v], head[v] = e++;
}

//1061109567
ll maxFlow(int s, int t,int D){
	ll flow = 0, ti = 0;
	while (D > 0){
		memset(d, 63, sizeof(d));
		queue<int> q;	 q.push(s);
		d[s] = 0;
		while (!q.empty())	{
			int u = q.front();	 q.pop();
			for (int i = head[u]; i != -1; i = edge[i].nxt) if(edge[i].c > 0 && d[edge[i].v] > d[u]+edge[i].t) {
				q.push(edge[i].v);
				prv[edge[i].v] = u, record[edge[i].v] = i;
				d[edge[i].v] = d[u] + edge[i].t;
			}
		}
		if (d[t] == 1061109567) break;
		int miFlow = D;
		for (int x = t; x != s; x = prv[x]) miFlow = min(miFlow, edge[record[x]].c);
		D -= miFlow;
		ti += ll(miFlow) * ll(d[t]);
		for (int x = t; x != s; x = prv[x]){
			int ed = record[x];
			edge[ed].c -= miFlow;
			edge[ed ^ 1].c += miFlow;
		}
	}
	if (D > 0) return -1;
	return ti;
}

int to[10500], from[10500], tt[10500];

int main(){
    freopen("uva.txt","rt",stdin);
	int n, m;
	while (scanf("%d%d", &n, &m) == 2){
		memset(head, -1, sizeof(head));
		e = 0;
		for (int i = 0; i < m; i++) scanf("%d%d%d", &from[i], &to[i], &tt[i]);
		int D, K; scanf("%d%d", &D, &K);
		for (int i = 0; i < m; i++) {
			addEdge(from[i], to[i], K, tt[i]);
			addEdge(to[i], from[i], K, tt[i]);
		}
		ll mxF = maxFlow(1, n, D);
		if (mxF == -1) puts("Impossible.");
		else printf("%lld\n", mxF);
	}
}
