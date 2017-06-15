#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool vis[105][105];
int n, m;
int a[105][105];
int co;

void dfs(int i, int j, int cur,int mx){
	if (i >= n || j >= m || i < 0 || j < 0 || vis[i][j] || a[i][j] != cur) return;
	if (cur == mx) cur = 0, mx++;
	if (i + 1 == n){// if we reached last row
		if (co == -1 || j < co) co = j;// find minimum column in last row
		return;
	}
	vis[i][j] = 1;
	// try all adjacent cells
	dfs(i + 1, j, cur + 1, mx);
	dfs(i - 1, j, cur + 1, mx);
	dfs(i, j + 1, cur + 1, mx);
	dfs(i, j - 1, cur + 1, mx);
	vis[i][j] = 0;
}

int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	while (T--){
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
			scanf("%d", a[i] + j);
		int j;
		for (j = 0; j < m; j++){
			co = -1;
			dfs(0, j, 1, 1);
			if (co != -1) break;
		}
		printf("%d %d\n%d %d\n%s", 1, j + 1, n, co + 1, T ? "\n" : "");
	}
}
