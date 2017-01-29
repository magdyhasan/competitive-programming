#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

bool adj[205][205];
int color[205];

int main(){
    freopen("uva.txt","rt",stdin);
	int n, m , i, a, b;
	while (scanf("%d", &n)) {
		if (!n)	break;
		scanf("%d", &m);
		memset(adj, 0, sizeof(adj));
		memset(color, -1, sizeof(color));
		for (i = 0; i < m; i++)
			scanf("%d%d", &a, &b), adj[a][b] = adj[b][a] = true;
		color[0] = 0;
		queue<int> q;
		bool f = true;
		q.push(0);
		while (!q.empty()) {
			int u = q.front();	q.pop();
			for (int v = 0; v < n; v++)
				if (adj[u][v])
					if (color[v] == -1)
						color[v] = 1 - color[u], q.push(v);
					else if (color[v] == color[u])
						f = false;
			if (!f)	break;
		}
		puts(f ? "BICOLORABLE." : "NOT BICOLORABLE.");
	}
}
