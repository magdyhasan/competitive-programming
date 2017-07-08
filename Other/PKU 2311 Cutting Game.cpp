#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


const int maxn = 3000500;

typedef long long ll;

int dp[205][205];



int rec(int w, int h){
	if (w == 1 && h == 1) return 0;
	int &ret = dp[w][h];
	if (ret != -1) return ret;
	int sub_nimbers[1005] = {};
	for (int i = 2; i <= w - i; i++)
		sub_nimbers[rec(w - i, h) ^ rec(i, h)] = 1;
	for (int i = 2; i <= h - i; i++)
		sub_nimbers[rec(w, h - i) ^ rec(w, i)] = 1;
	for (int i = 0;; i++) if (sub_nimbers[i] == 0)
	return ret = i;
}

int main(){
	freopen("uva.txt", "r", stdin);
	int w, h;
	memset(dp, -1, sizeof(dp));
	while (scanf("%d%d", &w, &h) == 2){
		puts(rec(w, h) ? "WIN" : "LOSE");
	}
}