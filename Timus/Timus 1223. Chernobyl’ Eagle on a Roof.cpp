/*
	dp state[number of floors][number of eggs]
	notice that for given i,j 
	we can choose any floor to drop from, the answer will be minimum floor answer
	if we drop from floor c, then we have answer 1+max([i-c][j],[c-1][j-1])
	either egg broke, in which we try all smaller floors
	or egg don't broke we try all remaining floors with same number of egg

	finally because this will get TLE, notice that if we n floors,
	answer will always be same for any number of eggs >= ceil(log_2(n)) + 1
*/
#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 1005;

int dp[maxn][maxn]; // i'th floor, j'th eggs

int main(){
    //freopen("uva.txt","rt",stdin);
	memset(dp, 63, sizeof dp);
	for (int i = 1; i < maxn; i++)
		dp[0][i] = 0, dp[1][i] = 1, dp[i][1] = i;
	for (int j = 2; j < 105; j++) for (int i = 2; i < maxn; i++){
		for (int x = 1; x <= i; x++)
			dp[i][j] = min(dp[i][j], 1 + max(dp[i - x][j], dp[x - 1][j - 1]));
	}
	int ng, nf;
	while (scanf("%d%d", &ng, &nf)){
		if (!ng && !nf) break;
		printf("%d\n", dp[nf][min(ng,104)]);
	}
}
