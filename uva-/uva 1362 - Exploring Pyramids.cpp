#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
const ll mod = 1e9;

ll dp[305][305];
char st[305];

ll rec(int i, int j){
	if (i+1 == j) return 1;
	ll &ret = dp[i][j];
	if (ret != -1) return ret;
	ret = 0;
	for (int it = i + 1; it < j; it++) if (st[i] == st[it])
		ret = (ret + rec(i + 1, it)*rec(it, j)) % mod;
	return ret;
}


int main(){
    freopen("uva.txt","rt",stdin);
	while (scanf("%s", st) == 1){
		memset(dp, -1, sizeof(dp));
		printf("%lld\n", rec(0, strlen(st)));
	}
}
