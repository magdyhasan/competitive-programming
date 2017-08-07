#include<bits/stdc++.h>
using namespace std;


const int maxn = 100500;

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


int fromChar(char x){
	if (isupper(x)) return x - 'A' + 26;
	return x - 'a';
}

int main(){
    freopen("uva.txt","rt",stdin);
	memset(head, -1, sizeof(head));
	e = 0;
	int n; scanf("%d", &n);
	char a[3], b[3];
	int flow;
	while (n--){
		scanf("%s%s%d", a, b, &flow);
		addEdge(fromChar(a[0]), fromChar(b[0]), flow);
	}
	printf("%d", maxflow(fromChar('A'), fromChar('Z')));
}
