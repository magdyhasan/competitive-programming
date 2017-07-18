#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	while (T--){
		int n; scanf("%d", &n);
		int a = n / 2, b = n - a;
		printf("%d\n", a*(a - 1) / 2 + b*(b - 1) / 2);
	}
}

