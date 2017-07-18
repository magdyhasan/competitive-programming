#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

const int maxn = 100500;

vector<int> adj[maxn], radj[maxn];

int d[maxn][2];

int main(){
    freopen("uva.txt","rt",stdin);
	int n, m; scanf("%d%d", &n, &m);
	int u, v, dir;
	for (int i = 0; i < m; i++){
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		radj[v].push_back(u);
	}
	scanf("%d%d", &u, &v);
	memset(d, 63, sizeof(d));
	queue<int> q; 
	q.push(u); q.push(0);
	q.push(u); q.push(1);
	d[u][0] = d[u][1] = 0;
	while (!q.empty()){
		u = q.front(); q.pop();
		dir = q.front(); q.pop();
		for (int v : adj[u]) if (d[v][0] > d[u][dir] + (dir == 1)){
			d[v][0] = d[u][dir] + (dir == 1);
			q.push(v); q.push(0);
		}
		for (int v : radj[u]) if (d[v][1] > d[u][dir] + (dir == 0)){
			d[v][1] = d[u][dir] + (dir == 0);
			q.push(v); q.push(1);
		}
	}
	printf("%d\n", min(d[v][0], d[v][1]));
}
