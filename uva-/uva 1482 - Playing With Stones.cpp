#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

ll grundy(ll x){
	return x & 1LL ? grundy(x / 2LL) : x / 2LL;
}

int main(){
    freopen("uva.txt","rt",stdin);
	int T;	scanf("%d", &T);
	while (T--){
		int n;	 scanf("%d", &n);
		ll xorSum = 0, tv;
		for (int i = 0; i < n; i++){
			scanf("%lld", &tv);
			xorSum ^= grundy(tv);
		}
		puts(xorSum ? "YES" : "NO");
	}
}
