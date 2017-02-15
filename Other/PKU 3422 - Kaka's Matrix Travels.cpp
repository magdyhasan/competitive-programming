#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

const int maxn = 1000001;

int head[maxn], d[maxn], prv[maxn], record[maxn];

struct Node{
	int u, v, c, value;
	int nxt;
} edge[maxn];
int e, s, t;

void addEdge(int u, int v, int c,int value){
	//forward edge
	edge[e].u = u, edge[e].v = v, edge[e].c = c, edge[e].value = value;
	edge[e].nxt = head[u], head[u] = e++;
	//backward edge
	edge[e].u = v, edge[e].v = u, edge[e].c = 0, edge[e].value = -value;
	edge[e].nxt = head[v], head[v] = e++;
}

int maxFlow(){
	int flow = 0;
	while (true){
		memset(d, -1, sizeof(d));
		d[0] = 0;
		queue<int> q;	q.push(0);
		while (!q.empty()){
			int u = q.front();	 q.pop();
			for (int i = head[u]; i != -1; i = edge[i].nxt){
				if (edge[i].c > 0 && d[edge[i].v] < d[u] + edge[i].value){
					q.push(edge[i].v);
					d[edge[i].v] = edge[i].value + d[u];
					prv[edge[i].v] = u, record[edge[i].v] = i;
				}
			}
		}
		if (d[t] == -1)	 break;
		for (int x = t; x != s; x = prv[x]){
			int ed = record[x];
			edge[ed].c --;
			edge[ed ^ 1].c ++;
			flow += edge[ed].value;
		}
	}
	return flow;
}


int main(){
    freopen("uva.txt","rt",stdin);
	int n, k, v;
	memset(head, -1, sizeof(head));
	scanf("%d%d", &n, &k);
	s = 0, t = n*n * 2 + 1;
	addEdge(s, 1, k, 0);
	addEdge((n - 1)*n + n - 1 + 1 + n*n, t, k, 0);
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		scanf("%d", &v);
		int nodeIN = i*n + j + 1, nodeOUT = i*n + j + 1 + n*n;
		addEdge(nodeIN, nodeOUT, 1, v);
		addEdge(nodeIN, nodeOUT, k - 1, 0);
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		int nodeOUT = i*n + j + 1 + n*n, nodeIN;
		if (i + 1 < n){
			nodeIN = (i + 1)*n + j + 1;
			addEdge(nodeOUT, nodeIN, k, 0);
		}
		if (j + 1 < n){
			nodeIN = i*n + j + 1 + 1;
			addEdge(nodeOUT, nodeIN, k, 0);
		}
	}
	printf("%d", maxFlow());
}
