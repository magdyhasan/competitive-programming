/*
	Dp of current avaiable materials
	for each mask we iterate over all possible mask's of that mask
	and if there's a sauce with that submask we try making it
*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 300500;


int a[maxn];
int dp[(1 << 17)];

int rec(int mask){
	int &ret = dp[mask];
	if (ret != -1) return ret;
	ret = 0;
	for (int subMask = mask; subMask != 0; subMask = (subMask - 1)&mask) if (a[subMask]){
		ret = max(ret, rec(mask&(~subMask)) + 1);
	}
	return ret;
}


int main(){
	freopen("test.in", "r", stdin);
	int n, m;
	int k, t;
	while (scanf("%d%d", &n, &m) == 2){
		memset(a, 0, sizeof(int)*((1 << (n + 1))));
		for (int i = 0; i < m; i++){
			scanf("%d", &k);
			int ma = 0;
			while (k--){
				scanf("%d", &t);
				ma |= (1 << (t - 1));
			}
			a[ma] = 1;
		}
		memset(dp, -1, sizeof(dp));
		printf("%d\n", rec((1 << n) - 1));
	}
}