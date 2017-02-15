#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<utility>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

const int maxn = 105;

int head[maxn];

struct edge{
	int u, v, l, t;
	int nxt;
} edge[10500];
int e;


void addEdge(int u, int v, int l, int t){
	edge[e].u = u, edge[e].v = v, edge[e].l = l, edge[e].t = t;
	edge[e].nxt = head[u], head[u] = e++;
}

struct state{
	int u, l, t;
	state(int a, int b, int c) : u(a), l(b), t(c){}
	bool operator <(const state &a) const {
		return l > a.l;
	}
};

int d[105][10500];
int n, m, k;
int ans = 1061109567;

void dijkstra(){
	memset(d, 63, sizeof(d));
    priority_queue< state > pq;
	pq.push({ 1, 0, 0 });
	d[1][0] = 0;
	while (!pq.empty()){
		state u = pq.top();	pq.pop();
		if (u.u == n) {
			ans = u.l;
			break;
		}
		if (d[u.u][u.t] != u.l) continue;
		for (int i = head[u.u]; i != -1; i = edge[i].nxt){
			int v = edge[i].v, nl = u.l + edge[i].l, nt = u.t + edge[i].t;
			if (nt <= k && d[v][nt] > nl)
				pq.push({ v, nl, nt }), d[v][nt] = nl;
		}
	}
}

int main(){
    freopen("uva.txt","rt",stdin);
    int tc;
    scanf("%d",&tc);
    while(tc--){
		e = 0;
		memset(head, -1, sizeof(head));
		ans = 1061109567;
        scanf("%d%d%d",&k,&n,&m);
        while(m--){
			int u, v, l, t;
			scanf("%d%d%d%d", &u, &v, &l, &t);
			addEdge(u, v, l, t);
        }
		dijkstra();
		if (ans != 1061109567) printf("%d\n", ans);
		else puts("-1");
    }
}
