#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 300500;

int  a[maxn], pot[maxn];

int main(){
    freopen("uva.txt","rt",stdin);
	int n; 
	while (scanf("%d", &n) == 1){
		for (int i = 0; i < (1 << n); i++)
			scanf("%d", a + i), pot[i] = 0;
		for (int i = 0; i < (1 << n); i++) for (int j = 0; j < n; j++)
			pot[i] += a[i ^ (1 << j)];
		int ans = -1;
		for (int i = 0; i < (1 << n); i++) for (int j = 0; j < n; j++)
			ans = max(ans, pot[i] + pot[i ^ (1 << j)]);
		printf("%d\n", ans);
	}
}
