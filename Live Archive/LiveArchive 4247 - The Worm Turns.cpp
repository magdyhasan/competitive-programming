/*
	just try all possible starting location and all options when you hit wall or visited cell
*/
#include<bits/stdc++.h>
using namespace std;

int g[630][630], d[630][630];
int n, m;

int di[] = {0,-1,1,0};
int dj[] = {1,0,0,-1};



int rec(int i,int j){
	int ret = 0;
	for (int k = 0; k < 4; k++) {
		int ni = i + di[k];
		int nj = j + dj[k];
		if (ni < 0 || nj < 0 || ni >= n || nj >= m || g[ni][nj]) continue;
		int cur = 1;
		bool mov = 0;
		while (true){
			g[ni][nj] = 1;
			ni += di[k]; nj += dj[k];
			if (ni < 0 || nj < 0 || ni >= n || nj >= m || g[ni][nj]) break;
			cur++;
		}
		ni -= di[k]; nj -= dj[k];
		cur = cur + rec(ni, nj);
		if (cur > ret){
			ret = cur;
			d[i][j] = k;
		}
		while (ni != i || nj != j){
			g[ni][nj] = 0;
			ni -= di[k]; nj -= dj[k];
			cur--;
		}
	}
	return ret;
}

char *dir = "ENSW";

int main(){
    freopen("uva.txt","rt",stdin);
	int tc = 0;
	while (scanf("%d%d", &n, &m)){
		if (!n) break;
		memset(g, 0, sizeof g);
		int r; scanf("%d", &r);
		int pi, pj;
		for (int i = 0; i < r; i++){
			scanf("%d%d", &pi, &pj);
			g[pi][pj] = 1;
		}
		int ret = 0, si = 0, sj = 0, dr = 0;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (!g[i][j]){
			g[i][j] = 1;
			int cur = rec(i, j) + 1;
			g[i][j] = 0;
			if (cur > ret){
				ret = cur;
				si = i, sj = j;
				dr = d[i][j];
			}
		}
		printf("Case %d: %d %d %d %c\n", ++tc, ret, si, sj, dir[dr]);
	}
}
