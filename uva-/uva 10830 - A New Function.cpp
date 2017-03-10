#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

ll sumN(ll x){
	return (x*(x + 1)) >> 1LL;
}

int main(){
	freopen("uva.txt", "rt", stdin);
	int n, t = 0;
	while (scanf("%d", &n)){
		if (n == 0) break;
		ll ret = 0, l, r, i;
		ll x, y, z;
		for (i = 2; i*i < n; i++){
			ll cntI = (n / i - 1)*i;
			ret += cntI;
			l = n / (i + 1);
			r = n / i;
			ll t = ll(i - 1)*(sumN(r) - sumN(l));
			if (l >= i)
				ret += ll(i - 1)*(sumN(r) - sumN(l));
		}
		if (i*i == n) ret += (n / i - 1)*i;
		printf("Case %d: %lld\n", ++t, ret);
	}
}
