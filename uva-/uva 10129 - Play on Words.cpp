#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool vis[26];
int n, indeg[26], outdeg[26];
bool adj[26][26];

void dfs(int u){
	vis[u] = true;
	for (int v = 0; v < 26; v++)
		if (adj[u][v] && !vis[v])
			dfs(v);
	return;
}

int main(){
    freopen("uva.txt","rt",stdin);
	char st[1001];
	int tc;	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		memset(vis, 0, sizeof(vis));
		memset(indeg, 0, sizeof(indeg));
		memset(outdeg, 0, sizeof(outdeg));
		memset(adj, 0, sizeof(adj));
		for (int i = 0; i < n; i++) {
			scanf("%s", st);
			int x = st[0] - 'a';	int y = st[strlen(st) - 1] - 'a';
			indeg[x]++;	outdeg[y]++;
			adj[x][y] = true;
		}
		int st = -1, ed = -1, sn = 0, en = 0, c = 0;
		for (int i = 0; i < 26; i++)
			if (indeg[i] == outdeg[i] + 1)
				st = i, sn++;
			else if (indeg[i] + 1 == outdeg[i] )
				ed = i, en++;
			else if (indeg[i] != outdeg[i])
				c++;
		if (!sn && !en)	
			for (int i = 0; i < 26;i++	)
				if (outdeg[i]) {
					st = i;
					sn++, en++;
					break;
				}
		bool f = false;
		if (sn == 1 && en == 1 && c == 0) {
			f = true;
			dfs(st);
			for (int i = 0; i < 26; i++)
				if (indeg[i] || outdeg[i])
					if (!vis[i])	f = false;
		}
		puts(f ? "Ordering is possible." : "The door cannot be opened.");
	}
}
