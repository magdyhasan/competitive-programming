#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int cnt[28];
char st[1000500];
int pr[1000500];

void rec(int x, int add){
	for (int i = 1; i <= x; i++){
		int n = i;
		for (int j = 2; j*j <= n; j++) {
			while (n%j == 0) n /= j, pr[j] += add;
		}
		if (n > 1) pr[n] += add;
	}
}

int main(){
    freopen("uva.txt","rt",stdin);
	while (scanf("%s", st) == 1){
		int n = strlen(st);
		for (int i = 0; i < 26; i++) cnt[i] = 0;
		for (int i = 0; i < n; i++) cnt[st[i] - 'a']++;
		memset(pr, 0, sizeof(pr));
		rec(n, 1);
		for (int i = 0; i < 26; i++) if (cnt[i] > 1) rec(cnt[i], -1);
		pr[2] -= pr[5], pr[5] = 0;
		int ret = 1;
		for (int i = 2; i <= n; i++) {
			while (pr[i] > 0) ret = (ret*i) % 10, pr[i]--;
		}
		printf("%d\n", ret);
	}
}

