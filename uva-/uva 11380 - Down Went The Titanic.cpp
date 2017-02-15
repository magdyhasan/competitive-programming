#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

const int maxn = 100500;
int head[maxn], d[maxn], record[maxn], prv[maxn];
int n, m, k;

inline bool isValid(int i, int j){
	return (i >= 0 && j >= 0 && i < n && j < m);
}

int dx[] = { 1, -1, 0, 0, },
	dy[] = { 0, 0, -1, 1 };

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

int maxflow(int s,int t){
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

char gr[40][40];

int main(){
    freopen("uva.txt","rt",stdin);
	while (scanf("%d%d%d", &n, &m, &k) == 3){
		for (int i = 0; i < n; i++) scanf("%s", gr[i]);
		e = 0;
		memset(head, -1, sizeof(head));
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (gr[i][j] != '~'){
			int nodeIN = i*m + j + 1, nodeOUT = i*m + j + 1 + n*m;
			if (gr[i][j] == '@') addEdge(nodeIN, nodeOUT, 123456789);
			else if (gr[i][j] == '.') addEdge(nodeIN, nodeOUT, 1);
			else if (gr[i][j] == '#') addEdge(nodeIN, nodeOUT, 123456789), addEdge(nodeOUT, 2 * n*m + 1, k);
			else addEdge(nodeIN, nodeOUT, 1), addEdge(0, nodeIN, 1);
			for (int k = 0; k < 4; k++){
				int ni = i + dx[k], nj = j + dy[k];
				if (!isValid(ni, nj)) continue;
				addEdge(nodeOUT, ni*m + nj + 1, 123456789);
			}
		}
		int flow = maxflow(0, 2 * n*m + 1);
		printf("%d\n", flow);
	}
}
