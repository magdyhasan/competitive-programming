/*
hint: try to play with order of available operation and see how they effect each other

hint2: notice that we don't delete operation after add operation
or more than one delete operation after double operation
since we can move delete operation before double and have less opertion
so now it's just incermental dp

if we are at a state i,
we can add character with cost x to go to state i+1
or double operation with cost y to go to state i*2
or double operation with cost y and then remove opertion with cost x to go to state i*2-1
*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 300500;

typedef long long ll;

ll dp[30000005];

int main(){
	int n, x, y;
	scanf("%d%d%d", &n, &x, &y);
	fill(dp, dp + 30000005, 1LL << 52);
	dp[0] = 0;
	for (int i = 0; i <= n; i++){
		//add character with cost x
		dp[i + 1] = min(dp[i + 1], dp[i] + x);
		//double operation
		dp[i * 2] = min(dp[i * 2], dp[i] + y);
		//double operation and then remove operation
		dp[i * 2 - 1] = min(dp[i * 2 - 1], dp[i] + y + x);
	}
	printf("%lld\n", dp[n]);
}