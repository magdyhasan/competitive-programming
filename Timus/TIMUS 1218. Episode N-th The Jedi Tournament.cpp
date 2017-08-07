#include<bits/stdc++.h>
using namespace std;

char st[205][10000];

int pa[205][3];
bool vis[205];

vector<int> adj[205];


int main(){
    freopen("uva.txt","rt",stdin);
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%s%d%d%d", st[i], &pa[i][0], &pa[i][1], &pa[i][2]);
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		int cnt = 0;
		for (int k = 0; k < 3; k++) if (pa[i][k] > pa[j][k]) cnt++;
		if (cnt > 1) adj[i].push_back(j);
	}
	for (int i = 0; i < n; i++){
		queue<int> q;
		q.push(i);
		memset(vis, 0, sizeof(vis));
		vis[i] = 1;
		int cnt = 0;
		while (!q.empty()){
			int u = q.front(); q.pop();
			cnt++;
			for (int v : adj[u]) if (!vis[v])
				vis[v] = 1, q.push(v);
		}
		if (cnt == n) printf("%s\n", st[i]);
	}
}

