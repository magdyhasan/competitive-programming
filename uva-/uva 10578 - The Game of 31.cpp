#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int dp[5][5][5][5][5][5];


bool rec(int c1, int c2, int c3, int c4, int c5, int c6,int a){
	if (c1 + c2 * 2 + c3 * 3 + c4 * 4 + c5 * 5 + c6 * 6 > 31) return a;
	int &f = dp[c1][c2][c3][c4][c5][c6];
	if (f != -1) return f;
	f = a ^ 1;
	if (c1 < 4 && rec(c1 + 1, c2, c3, c4, c5, c6, a ^ 1) == a) return f = a;
	if (c2 < 4 && rec(c1, c2 + 1, c3, c4, c5, c6, a ^ 1) == a) return f = a;
	if (c3 < 4 && rec(c1, c2, c3 + 1, c4, c5, c6, a ^ 1) == a) return f = a;
	if (c4 < 4 && rec(c1, c2, c3, c4 + 1, c5, c6, a ^ 1) == a) return f = a;
	if (c5 < 4 && rec(c1, c2, c3, c4, c5 + 1, c6, a ^ 1) == a) return f = a;
	if (c6 < 4 && rec(c1, c2, c3, c4, c5, c6 + 1, a ^ 1) == a) return f = a;
	return f;
}

int main(){
    freopen("uva.txt","rt",stdin);
	memset(dp, -1, sizeof dp);
	int t;
	while (scanf("%d", &t) == 1){
		vector<int> c(7,0);
		int moves = 0, tt = t, sum = 0;
		while (t > 0){
			moves++;
			c[t % 10]++;
			t /= 10;
		}
		bool ret = rec(c[1], c[2], c[3], c[4], c[5], c[6], moves%2);
		printf("%d %c\n", tt, ret + 'A');
	}
}
