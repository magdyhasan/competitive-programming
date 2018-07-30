/*
	standard dp
	dp[i][j], where there's an empty cell on cell i and empty on j and whole range(i,j) is full
	so we can empty any cell on range [i,j] and recurse on [i,c-1]+[c+1,j]
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 20000001;

int a[maxn];
int dp[105][105];

int rec(int l, int r){
	if (l > r) return 0;
	if (l == r){
		return (a[l] - a[l - 1] - 1) + (a[r + 1] - a[l] - 1);
	}
	int &ret = dp[l][r];
	if (ret != -1) return ret;
	ret = 123456789;
	for (int i = l; i <= r; i++){
		ret = min(ret, rec(l, i - 1) + (a[i] - a[l - 1] - 1) + rec(i + 1, r) + (a[r + 1] - a[i] - 1));
	}
	return ret;
}

int main(){
	freopen("test.txt", "rt", stdin);
	int	T; scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++){
		int n, m; scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; i++)
			scanf("%d", a + i);
		a[0] = 0;
		a[m + 1] = n + 1;
		memset(dp, -1, sizeof(dp));
		printf("Case #%d: %d\n", tc, rec(1, m));
	}
}
