#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

const int maxn = 1550;

int head[maxn], d[maxn], record[maxn], prv[maxn];

struct Node{
	int u, v, c;
	int nxt;
} edge[maxn];
int e;

void addEdge(int u, int v, int c)	{
	//forward edge
	edge[e].u = u, edge[e].v = v, edge[e].c = c;
	edge[e].nxt = head[u], head[u] = e++;
	//backward edge
	edge[e].u = v, edge[e].v = u, edge[e].c = c;
	edge[e].nxt = head[v], head[v] = e++;
}

void maxflow(){
	while (true){
		memset(d, 0, sizeof(d));
		d[1] = 123456789;
		queue<int> q;
		q.push(1);
		while (!q.empty()){
			int u = q.front();	 q.pop();
			for (int i = head[u]; i != -1; i = edge[i].nxt) if( d[edge[i].v] == 0 && edge[i].c > 0 ) {
				d[edge[i].v] = min(d[u], edge[i].c);
				prv[edge[i].v] = u, record[edge[i].v] = i;
				q.push(edge[i].v);
			}
		}
		if (d[2] == 0) return;
		for (int u = 2; u != 1; u = prv[u]){
			int ed = record[u];
			edge[ed].c -= d[2];
			edge[ed ^ 1].c += d[2];
		}
	}
}

bool vis[maxn];

void floodFill(int u){
	if (vis[u]) return;
	vis[u] = true;
	for (int i = head[u]; i != -1; i = edge[i].nxt)
		if (!vis[edge[i].v] && edge[i].c > 0)
			floodFill(edge[i].v);
}


int main(){
    freopen("uva.txt","rt",stdin);
	int n, m;
	while (scanf("%d%d", &n, &m) == 2){
		if (!n && !m) break;
		memset(head, -1, sizeof(head));
		e = 0;
		int u, v, c;
		for (int i = 0; i < m; i++){
			scanf("%d%d%d", &u, &v, &c);
			addEdge(u, v, c);
		}
		maxflow();
		memset(vis, 0, sizeof(vis));
		floodFill(1);
		for (int i = 0; i < e; i++)
			if (vis[edge[i].u] && !vis[edge[i].v]) printf("%d %d\n", edge[i].u, edge[i].v);

		puts("");
	}
}
