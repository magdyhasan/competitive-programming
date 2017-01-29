#include<stdlib.h>
#include<stdio.h>
#include<cstring>
using namespace std;


char pat[1000010], txt[1000010];
int lgs[1000010];

int main(){
    freopen("uva.txt","rt",stdin);
	int m, n;
	while (scanf("%d\n",&m) != EOF) {
		scanf("%s%s", pat, txt);
		n = strlen(txt);
		lgs[0] = 0;
		for (int i = 1, k = 0; i < m; i++) {
			while (k && pat[k] != pat[i]) k = pat[k - 1];
			if (pat[k] == pat[i]) lgs[i] = ++k;
			else lgs[i] = k;
		}
		for (int i = 0, k = 0; i < n; i++) {
			while (k && pat[k] != txt[i]) k = pat[k - 1];
			if (pat[k] == txt[i]) k++;
			if (k == m) {
				printf("%d\n", i - m + 1);
				k = lgs[k - 1];
			}
		}
		puts("");
	}
}
