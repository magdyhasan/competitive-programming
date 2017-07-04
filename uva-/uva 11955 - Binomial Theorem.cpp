#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

ll nCr[55][55];
char st[100500], a[100500], b[100500];

int main(){
	freopen("uva.txt", "rt", stdin);
	for (int i = 0; i < 55; ++i) {
		nCr[i][0] = nCr[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];
		}
	}
	int T; scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%s", st);
		int k;
		sscanf(st, "(%[^+]+%[^)])^%d", a, b, &k);
		printf("Case %d:", tc);
		for (int i = 0; i <= k; i++){
			printf("%s", i ? "+" : " ");
			bool fi = 0;
			if (nCr[k][i] > 1) printf("%lld*", nCr[k][i]);
			if (k - i == 1) printf("%s", a), fi = 1;
			if (k - i > 1) printf("%s^%d", a, k - i), fi = 1;
			if (i == 1) printf("%s%s", fi ? "*" : "", b);
			if (i > 1) printf("%s%s^%d", fi ? "*" : "", b, i);
		}
		puts("");
	}
}
