/*
	first notice typical n^3 normal dp[i][j],
	mean we in position i, and last player took j coins
	this n^2, and we need extra loop inside dp to decide how much current player take from 0 to 2*j


	idea is to reduct this to n^2 by playing with second parameter

	instead of j meaning last player took j coins
	make it dp[i][av], meaning we are allowed to take up to av coins

	with this parameter we can get rid of inside loop:
	as we have two option:
	1- recduce number of aviable coins we take, this just call to do[i][j-1] without loop
	2- take av number of coins from current position i, this just dp[i+av][av*2]
	this an n^2 dp that will pass
*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 300500;

int a[maxn];

typedef pair<int, int> pii;

int dp[2005][2005];
bool vis[2005][2005];
int suf[2005];
int n;

int rec(int i, int av){
	if (i == n) return 0;
	if (av == 1) return suf[i] - rec(i + 1, 2);
	if (n - i < av) return rec(i, n - i);
	int &ret = dp[i][av];
	if (vis[i][av]) return ret;
	vis[i][av] = 1;
	return ret = max(rec(i, av - 1), suf[i] - rec(i + av, av * 2));
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	for (int i = n; i >= 0; i--) suf[i] = suf[i + 1] + a[i];
	printf("%d\n", rec(0, 2));
}