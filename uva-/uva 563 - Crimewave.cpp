#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

const int maxn = 100500;

int n, m;
int nxt[maxn], head[maxn], prv[maxn], d[maxn], record[maxn];
int dx[] = { 1, -1, 0, 0 },
	dy[] = { 0, 0, -1, 1 };

bool isVaild(int i, int j){
	return (i >= 0 && j >= 0 && i < n && j < m);
}

struct Node{
	int u, v, c;
	int nxt;
} edge[maxn];
int e;

void addEdge(int u, int v, int c){
	// forward
	edge[e].u = u, edge[e].v = v, edge[e].c = c;
	edge[e].nxt = head[u], head[u] = e++;
	//backward
	edge[e].u = v, edge[e].v = u, edge[e].c = 0;
	edge[e].nxt = head[v], head[v] = e++;
}

int maxflow(){
	int flow = 0;
	while (true){
		memset(d, 0, sizeof(d));
		d[0] = 12345678;
		queue < int > q; q.push(0);
		int t = 2 * n*m + 1;
		while (!q.empty()){
			int u = q.front();	 q.pop();
			if (u == t) break;
			for (int i = head[u]; i != -1; i = edge[i].nxt)
				if (d[edge[i].v] == 0 && edge[i].c > 0){
					q.push(edge[i].v);
					record[edge[i].v] = i, prv[edge[i].v] = u;
					d[edge[i].v] = min(d[u], edge[i].c);
				}
		}
		if (d[t] == 0) break;
		int f = d[t];
		flow += f;
		for (int u = t; u; u = prv[u]){
			int ed = record[u];
			edge[ed].c -= f;
			edge[ed ^ 1].c += f;
		}
	}
	return flow;
}


int main(){
    freopen("uva.txt","rt",stdin);
	int T;
	scanf("%d", &T);
	while (T--){
		int b;
		e = 0;
		memset(head, -1, sizeof(head));
		scanf("%d%d%d", &n, &m, &b);
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++){
			int nodeIN = i*m + j + 1, nodeOUT = i*m + j + 1 + n*m;
			addEdge(nodeIN, nodeOUT, 1);
			for (int k = 0; k < 4; k++){
				int ni = i + dx[k], nj = j + dy[k];
				if (!isVaild(ni, nj)) continue;
				addEdge(nodeOUT, ni*m + nj + 1, 12345);
			}
		}
		for (int i = 0; i < n; i++){
			int nodeOUT = i*m + 1 + n*m;
			addEdge(nodeOUT, 2 * n*m + 1, 1);
			nodeOUT = i*m + m - 1 + 1 + n*m;
			addEdge(nodeOUT, 2 * n*m + 1, 1);
		}
		for (int i = 1; i < m - 1; i++){
			int nodeOUT = i + 1 + n*m;	
			addEdge(nodeOUT, 2 * n*m + 1, 1);
			nodeOUT = (n - 1)*m + i + 1 + n*m;
			addEdge(nodeOUT, 2 * n*m + 1, 1);
		}
		for (int i = 0; i < b; i++){
			int u, v;
			scanf("%d%d", &u, &v);
			u--;	v--;
			addEdge(0, u*m + v + 1, 1);
		}
		int flow = maxflow();
		if (flow == b) puts("possible");
		else puts("not possible");
	}
}
