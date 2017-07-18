#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 1000500;

typedef long long ll;

ll f[maxn], cf[maxn];

int main(){
    freopen("uva.txt","rt",stdin);
	ll cnt = 0;
	for (int i = 4; i < maxn; i++){
		f[i] = ++cnt + f[i - 2];
		cf[i] = cf[i - 1] + f[i];
	}
	int T; scanf("%d", &T);
	while (T--){
		int n; scanf("%d", &n);
		printf("%lld\n", cf[n]);
	}
}

