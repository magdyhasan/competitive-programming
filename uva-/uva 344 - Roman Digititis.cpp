#include<bits/stdc++.h>
using namespace std;



enum RomanDigit { I = 0, V = 1, X = 2, L = 3, C = 4 };

int dp[105][5];


void make(int x){
	int dig[] = { x % 10, (x / 10) % 10, (x / 100) % 10 };
	if (dig[0] == 4) dp[x][I]++, dp[x][V]++;
	else if (dig[0] == 9) dp[x][I]++, dp[x][X]++;
	else dp[x][I] += dig[0] % 5, dp[x][V] += dig[0] / 5;

	if (dig[1] == 4) dp[x][X]++, dp[x][L]++;
	else if (dig[1] == 9) dp[x][X]++, dp[x][C]++;
	else dp[x][X] += dig[1] % 5, dp[x][L] += dig[1] / 5;

	dp[x][C] += dig[2] == 1;
}

char rd[] = { 'i', 'v', 'x', 'l', 'c' };

int main(){
	freopen("uva.txt", "r", stdin);
	for (int i = 1; i <= 100; i++){
		make(i);
		for (int j = 0; j < 5; j++)
			dp[i][j] += dp[i - 1][j];
	}
	int n;
	while (scanf("%d", &n) && n){
		printf("%d:", n);
		for (int i = 0; i < 5; i++)
			printf("%s %d %c", i ? "," : "", dp[n][i], rd[i]);
		puts("");
	}
}