#include<bits/stdc++.h>
using namespace std;

int s[32][32];

char st[32];

int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	while (T--){
		int n, m, k, ret = -1; scanf("%d%d%d", &n, &m, &k);
		for (int i = 1; i <= n; i++){
			scanf("%s", st);
			for (int j = 1; j <= m;j++)
				s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (st[j - 1] == 'C');
		}
		for (int r = 1; r <= n; r++) for (int c = 1; c <= m; c++){
			for (int r2 = r + 1; r2 <= n; r2++) for (int c2 = c + 1; c2 <= m; c2++){
				int cntk = s[r2][c2] - s[r - 1][c2] - s[r2][c - 1] + s[r - 1][c - 1];
				if (cntk != k) continue;
				int si = (r2 - r + 1)*(c2 - c + 1);
				if (ret == -1 || ret > si){
					ret = si;
				}
			}
		}
		printf("%d\n", ret);
	}
}
