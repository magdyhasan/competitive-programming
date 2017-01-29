#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int g[35], f[35];

int main(){
	f[0] = 1, f[1] = 0, g[0] = 0, g[1] = 1;
	for (int i = 2; i <= 30; i++){
		g[i] = f[i - 1] + g[i - 2];
		f[i] = f[i - 2] + g[i - 1] * 2;
	}
	while (scanf("%d", &n)){
		if (n == -1) break;
		printf("%d\n", f[n]);
	}
}
