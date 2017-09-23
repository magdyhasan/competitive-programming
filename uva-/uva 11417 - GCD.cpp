#include<bits/stdc++.h>
using namespace std;

int dp[512][512];


int gcd(int a, int b){
	if (b == 0)
		return a;
	int &ret = dp[a][b];
	if (ret != -1) return ret;
	return ret = gcd(b, a%b);
}



int main(){
    freopen("uva.txt","rt",stdin);
	memset(dp, -1, sizeof(dp));
	int n; 
	while (scanf("%d", &n)){
		if (!n) break;
		int ret = 0;
		for (int i = 1; i < n; i++) for (int j = i + 1; j <= n; j++)
			ret += gcd(i, j);
		printf("%d\n", ret);
	}
}
