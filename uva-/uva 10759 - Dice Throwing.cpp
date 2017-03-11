/*
	Let dp[i][j] repesent number of ways to rech sum j after i throws
	dp[i][j] = dp[i-1][j-d] where d where 1<=d<=6 ( the value we got in the i-th throw )
	to get probability fraction it's dp[n][j]/6^n for all j>=x
	get GCD(s(dp[n][j], j>=x),6^n) to be improper fraction
*/

#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;


ll dp[32][1024], p6[32];

ll _gcd(ll a, ll b){
	return !b ? a : _gcd(b, a%b);
}

int main(){
	freopen("uva.txt", "r", stdin);
	int n, x;
	for (int i = 1; i <= 6; i++) dp[1][i] = 1;
	p6[0] = 1;
	for (int d = 1; d < 26; d++){
		for (int s = 0; s < 1024; s++)
			for (int diN = 1; diN <= 6; diN++)
				dp[d + 1][diN + s] += dp[d][s];
		p6[d] = p6[d - 1] * 6LL;
	}
	while (scanf("%d%d", &n, &x)){
		if (!n && !x) break;
		ll s = 0, p6n = p6[n];
		for (int i = x; i < 1024; i++) s += dp[n][i];
		ll g = _gcd(p6n, s);
		s /= g, p6n /= g;
		if (p6n == 1) printf("%lld\n", s);
		else printf("%lld/%lld\n", s, p6n);
	}
}
