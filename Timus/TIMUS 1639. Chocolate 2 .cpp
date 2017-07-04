#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    freopen("uva.txt","rt",stdin);
	int n, m; scanf("%d%d", &n, &m);
	if ((n*m) % 2 == 0) puts("[:=[first]");
	else puts("[second]=:]");
}

