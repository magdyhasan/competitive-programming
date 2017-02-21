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
	ll a, b, x, y;
	while (scanf("%lld%lld", &a, &b) == 2){
		ll g = extendedGCD(a, b, x, y);
		printf("%lld %lld %lld\n", x, y, g);
	}
}
