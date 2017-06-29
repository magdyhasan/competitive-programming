#include<bits/stdc++.h>
#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 300500;

int a[maxn];
int dp[maxn][2], d[maxn];

int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	while (T--){
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", a + i), d[i+1] = INT_MAX;
		int ret = 0;
		for (int i = 0; i < n; i++){
			dp[i][0] = dp[i][1] = 1;
			if (i){
				dp[i][0] = 1 + (a[i] > a[i - 1]) * dp[i - 1][0];
				dp[i][1] = 1 + (a[i] > a[i - 1]) * dp[i - 1][1];
			}
			dp[i][1] = max(dp[i][1], (int)(lower_bound(d, d + n, a[i]) - d));
			d[dp[i][0]] = min(d[dp[i][0]], a[i]);
			ret = max(ret, dp[i][1]);
		}
		printf("%d\n", ret);
	}
}
