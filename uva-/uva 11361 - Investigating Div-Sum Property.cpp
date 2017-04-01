/*
	idea: calculate number of numbers ending at idx, with reminder rem, sum of digits, whether it's smaller than nu
	answer is just dp(b) - dp(a-1)
*/

#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

int a, b, k;

int dp[10][100][91][2];
string nu;
int n;


int rec(int idx, int rem,int sum, int f){
	if (idx == n) return (rem == 0 && sum == 0);
	int &ret = dp[idx][rem][sum][f];
	if (ret != -1) return ret;
	ret = 0;
	int up = f ? 9 : (nu[idx] - '0');
	for (int i = 0; i <= up; i++){
		int nf = f | (i != (nu[idx] - '0'));
		ret += rec(idx + 1, (rem * 10 + i) % k, (sum + i) % k, nf);
	}
	return ret;
}

int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	while (T--){
		scanf("%d%d%d", &a, &b, &k);
		if (k > 99){
			puts("0");
			continue;
		}
		nu = to_string(b);
		n = nu.size();
		memset(dp, -1, sizeof(dp));
		int ub = rec(0, 0, 0, 0);
		nu = to_string(a - 1);
		n = nu.size();
		memset(dp, -1, sizeof(dp));
		int ua = (rec(0, 0, 0, 0));
		printf("%d\n", ub - ua);
	}
}
