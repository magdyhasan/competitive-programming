/*
	this problem can be solved using dp

	our state can be [i][k][u][r][d][l]
	repesent we are in current row i, with reminder k to place 
	u,r,d,l repesent whether our up/right/down/left is covered 

	when we move from state to state, up can be covered only in i == 0 and down in i+1 == n
	take care we can place in corners and might cover two sides
*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 800500;

typedef long long ll;

const ll mod = 1000007;

int n, m;

int binomial_memo[2005][2005];

int nCk(int n, int k) {
	if (k > n) return 0;
	int &res = binomial_memo[n][k];
	if (res >= 0) return res;
	return res = (k == 0) ? 1LL : (k == n) ? 1LL : (nCk(n - 1, k - 1) + nCk(n - 1, k)) % mod; // with mod
}

int dp[22][505][2][2][2][2];

int rec(int i, int k, bool u, bool r, bool d, bool l){
	if (i == n) return (k == 0 && u && r && d && l);
	int &ret = dp[i][k][u][r][d][l];
	if (ret != -1) return ret;
	ret = rec(i + 1, k, u, r, d, l);
	for (int p = 1; p <= min(k, m); p++){// we will place p cheerleader here
		for (int ul = 0; ul < 2; ul++){ // whether we place one in first column of current row or not
			for (int ur = 0; ur < 2; ur++){// whether we place one in last column of current row or not
				if (ur + ul > p || (p - ur - ul) > m - 2) continue;
				bool nu = u || ((p - ul - ur) > 0 && i == 0) || (ul && i == 0) || (ur && i == 0);
				bool nd = d || ((p - ul - ur) > 0 && i + 1 == n) || (ul && i + 1 == n) || (ur && i + 1 == n);
				//once we decide what to place in first and last columns, we have m-2 cells to fill 
				ret = (ret + rec(i + 1, k - p, nu, r || ur, nd, l || ul) * 1LL * nCk(m - 2, p - ur - ul)) % mod;
			}
		}
	}
	return ret;
}

int main(){
	freopen("in.in", "r", stdin);
	int T, k; scanf("%d", &T);
	memset(binomial_memo, -1, sizeof(binomial_memo));
	for (int tc = 1; tc <= T; tc++){
		scanf("%d%d%d", &m, &n, &k);
		memset(dp, -1, sizeof(dp));
		printf("Case %d: %d\n", tc, rec(0, k, 0, 0, 0, 0));
	}
}