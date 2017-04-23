#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int inc[100][100];
bool adj[100][100], vis[100];
int n, m;



int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	while (T--){
		memset(inc, 0, sizeof(inc));
		memset(adj, 0, sizeof(adj));
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
			scanf("%d", &inc[i][j]);
		bool f = 1;
		for (int i = 0; i < m; i++){
			vector<int> no;
			for (int j = 0; j < n; j++) if (inc[j][i])
				no.push_back(j);
			if (no.size()>2 || no.size()<2){
				f = 0;
				break;
			}
			int a = no[0], b = no[1];
			if (adj[a][b]) {
				f = 0;
				break;
			}
			adj[a][b] = adj[b][a] = 1;
		}
		
		if (f) puts("Yes");
		else puts("No");
	}
}

