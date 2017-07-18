#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    freopen("uva.txt","rt",stdin);
	int n; scanf("%d", &n);
	if (n == 1) puts("1 2 3");
	else if (n == 2) puts("3 4 5");
	else puts("-1");
}

