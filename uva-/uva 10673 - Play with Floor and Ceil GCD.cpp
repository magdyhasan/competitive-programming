#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;


ll extendedGCD(ll a, ll b, ll &x, ll &y){
	if (b == 0){
		x = 1, y = 0;
		return a;
	}
	ll g = extendedGCD(b, a%b, y, x);
	y -= (a / b)*x;
	return g;
}

int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	while (T--){
		ll a, b, x, y;
		scanf("%lld%lld", &a, &b);
		ll g = extendedGCD(a/b, (a+b-1)/b, x, y);
		x *= a / g;
		y *= a / g;
		printf("%lld %lld\n", x, y);
	}
}
