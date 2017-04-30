#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int get(int n) { return n*(n + 1) / 2; }

int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++){
		int n, k, x;
		scanf("%d%d%d", &n, &k, &x);
		int s = n*(n + 1) / 2;
		s -= get(x + k - 1) - get(x - 1);
		printf("Case %d: %d\n", tc, s);
	}
}

