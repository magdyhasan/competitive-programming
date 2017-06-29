#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


int p[402];
int par(int x){
	return x == p[x] ? x : p[x] = par(p[x]);
}
int gro;
int a[402], b[402];
bool dp[402][115][115], vis[402][115][115];

bool rec(int idx, int fi, int se){
	if (idx == gro) return fi == 0 && se == 0;
	bool &ret = dp[idx][fi][se];
	if (vis[idx][fi][se]) return ret;
	ret = rec(idx + 1, fi, se);
	if (fi >= a[idx] && se >= b[idx]) ret |= rec(idx + 1, fi - a[idx], se - b[idx]);
	vis[idx][fi][se] = 1;
	return ret;
}

int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	while (T--){
		int n, m; scanf("%d%d", &n, &m);
		for (int i = 0; i <= 2 * n; i++) p[i] = i, a[i] = 0, b[i] = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = 0,u, v; i < m; i++){
			scanf("%d%d", &u, &v);
			u = par(u), v = par(v + n);
			p[v] = u;
		}
		gro = 0;
		for (int i = 1; i <= 2 * n; i++) if(par(i) == i){
			for (int j = 1; j <= 2 * n; j++) if (par(j) == i)
				if (j > n) b[gro]++;
				else a[gro]++;
			gro++;
		}
		for (int i = n / 2; i >= 0; i--) if(rec(0,i,i)){
			printf("%d\n", i);
			break;
		}
	}
}

