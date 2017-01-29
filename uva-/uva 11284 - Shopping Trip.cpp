#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int dp[55][(1 << 13)];
int p[15], P, save[15];
int Vmsk;
int d[55][55];
int n, m;

int rec(int idx, int msk){
	if ((msk&Vmsk) == Vmsk) return d[idx][0];
	int &ret = dp[idx][msk];
	if (ret != -1) return ret;
	ret = 123456789;
	for (int i = 0; i < P; i++)
		if (Vmsk & (1 << i))
			ret = min(ret, rec(p[i], msk | (1 << i)) + d[idx][p[i]]);
	return ret;
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &m);
		memset(d, 63, sizeof(d));
		for (int i = 0; i < m; i++){
			int u, v, c, cc;
			scanf("%d%d%d.%d", &u, &v, &c, &cc);
			c = c * 100 + cc;
			d[u][v] = d[v][u] = min(c,d[u][v]);
		}
		scanf("%d", &P);
		int c, cc;
		int ans = -1;
		for (int i = 0; i < P; i++) scanf("%d%d.%d", p + i, &c, &cc), save[i] = c*100+cc;
		for (int k = 0; k <= n; k++)
			for (int i = 0; i <= n; i++)
				for (int j = 0; j <= n; j++)
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
		for (Vmsk = 0; Vmsk < (1 << P); Vmsk++){
			memset(dp, -1, sizeof(dp));
			int dif = 0;
			for (int i = 0; i < P; i++) if (Vmsk&(1 << i)) dif += save[i];
			int ret = rec(0, 0);
			if (ret == 123456789) continue;
			if (ret >= dif) continue;
			ans = max(ans, dif - ret);
		}
		if (ans == -1) puts("Don't leave the house");
		else printf("Daniel can save $%.2lf\n", ans/100.);
	}
}
