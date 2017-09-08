#include<bits/stdc++.h>
using namespace std;


const int maxn = 1005;

typedef long long ll;

ll a[maxn][maxn], cc[maxn][maxn];
int n, m;


int main(){
    freopen("uva.txt","rt",stdin);
	bool f = 0;
	while (scanf("%d%d", &n, &m) == 2){
		if (f) puts("");
		f = 1;
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
			scanf("%lld", &a[i][j]);
		for (int j = 0; j < n; j++){
			cc[j][0] = a[0][j];
			for (int i = 1; i < n; i++) cc[j][i] = cc[j][i - 1] + a[i][j];
		}
		ll ret = 0;
		for (int i = 0; i+m <= n; i++) {
			ll s = 0;
			for (int j = 0; j < n; j++){
				s += cc[j][i + m - 1] - ((i > 0) ? cc[j][i - 1] : 0);
				if (j >= m) s -= cc[j - m][i + m - 1] - ((i > 0) ? cc[j - m][i - 1] : 0);
				if (j+1 >= m) printf("%lld\n", s),ret += s;
			}
		}
		printf("%lld\n", ret);
	}
}
