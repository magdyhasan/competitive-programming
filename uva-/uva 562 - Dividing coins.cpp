#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;




int dp[105][50005], co[105];
int n, allSum;

int rec(int idx, int sum){// current index of coins, current sum of one person
	if (idx == n) {
		return abs((allSum - sum)-sum);
	}
	int &ret = dp[idx][sum];
	if (ret != -1) return ret;
	return ret = min(rec(idx + 1, sum + co[idx]), rec(idx + 1, sum));
}

int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	while (T--){
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &co[i]);
		allSum = 0;
		for (int i = 0; i < n; i++)
			allSum += co[i];
		memset(dp, -1, sizeof(dp));
		printf("%d\n", rec(0, 0));
	}
}
