#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 10500;

int n, m;
int dp[10500][1050];

int lgp[10500];
char a[10500], b[10500];

int rec(int i, int j){
	if (j == m) return 12345678;
	if (i == n) return 0;
	int &ret = dp[i][j];
	if (ret != -1) return ret;
	while (j && a[i] != b[j]) j = lgp[j - 1];
	if (a[i] != b[j]) ret = rec(i + 1, 0);
	else ret = min(rec(i + 1, j) + 1, rec(i + 1, j + 1));
	int t1 = rec(i + 1, j) + 1;
	int t2 = rec(i + 1, j + 1);
	return ret;
}


int main(){
	while (scanf("%s%s", a, b) != EOF){
		n = strlen(a), m = strlen(b);
		for (int i = 1, k = 0; i < m; i++) {
			while (k && b[k] != b[i]) k = lgp[k - 1];
			if (b[k] == b[i]) lgp[i] = ++k;
			else lgp[i] = k;
		}
		memset(dp, -1, sizeof(dp));
		printf("%d\n", rec(0, 0));
	}
}
