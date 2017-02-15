#include<stdlib.h>
#include<stdio.h>
#include<cstring>
using namespace std;

int longestP[1000500];

int main(){
    freopen("uva.txt","rt",stdin);
	int k;	
	char st[1000500];
	while (scanf("%d%s", &k, st)){
		if (k == -1) break;
		int n = strlen(st);
		for (int i = 1, k = 0; i < n; i++){
			while (k > 0 && st[i] != st[k]) k = longestP[k - 1];
			if (st[i] == st[k]) longestP[i] = ++k;
			else longestP[i] = k;
		}
		if (k < n) puts("0");
		else printf("%d\n", 1 + (k - n) / (n - longestP[n-1]));
	}
}
