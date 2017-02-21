#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

ll dp[(1 << 12)];


ll rec(int mask){
	ll &ret = dp[mask];
	if (ret != -1) return ret;
	ret = 1;
	for (int smask = mask; smask; smask = (smask - 1)&mask)
		ret += rec(smask);
	return ret;
}

int main(){
    freopen("uva.txt","rt",stdin);
	int T;	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++){
		memset(dp, -1, sizeof(dp));
		int B; scanf("%d", &B);
		printf("%d %d %lld\n", tc, B, rec((1 << B) - 1)-1);
	}
}
