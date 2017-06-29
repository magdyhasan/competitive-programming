#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
const ll mod = 10007;


ll dp[mod];
ll cyc = mod - 1;


int main(){
    freopen("uva.txt","rt",stdin);
	dp[0] = 1, dp[1] = 2;
	for (int i = 2; i < mod; i++) dp[i] = (dp[i - 1] * 2 + dp[i - 2] * 2) % mod;
	ll n; 
	while (scanf("%lld", &n)){
		if (n == -1) break;
		if (n < cyc) {
			ll ret = 0;
			for (ll k = 0; k <= n; k++) {
				ret = (ret + dp[k%cyc] * dp[(n - k) % cyc]) % mod;
			}
			printf("%lld\n", ret);
			continue;
		}
		ll cycnum = n / cyc, ret = 0;
		for (int i = 0; i < cyc; i++)
			ret = (ret + dp[i] * dp[(n - i) % cyc]) % mod;
		ret = ret*cycnum%mod;
		for (ll i = cycnum*cyc; i <= n; i++)
			ret = (ret + dp[i % cyc] * dp[(n - i) % cyc]) % mod;
		printf("%lld\n", ret);
	}
}

