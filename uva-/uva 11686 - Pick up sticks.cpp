#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

vector<int> adj[1000500];
int ret[1000500], inDeg[1000500];

int main(){
    freopen("uva.txt","rt",stdin);
	int n, m, i, j, a, b;
	while (scanf("%d%d", &n, &m) == 2) {
		if (!n && !m)	break;
		for (i = 0; i <= n; i++)	adj[i].clear(), inDeg[i] = 0;
		for (i = 0; i < m; i++) {
			scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			inDeg[b]++;
		}
		queue<int> q;
		for (i = 1; i <= n; i++)
			if (!inDeg[i])
				q.push(i);
		int t = 0;
		while (!q.empty()) {
			int u = q.front();	q.pop();
			ret[t++] = u;
			for (int v : adj[u]) {
				inDeg[v]--;
				if (!inDeg[v])
					q.push(v);
			}
		}
		if (t != n)
			puts("IMPOSSIBLE");
		else
			for (i = 0; i < n; i++)
				printf("%d\n", ret[i]);
	}
}
