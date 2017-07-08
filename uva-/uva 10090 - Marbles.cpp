#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

ll extended_gcd(ll a, ll b, ll &x, ll &y){
	if (a == 0) {
		x = 0;	y = 1;
		return b;
	}
	ll tx, ty;
	ll g = extended_gcd(b%a, a, tx, ty);
	y = tx;
	x = ty - (b / a)*tx;
	return g;
}


int main(){
    freopen("uva.txt","rt",stdin);
	ll n, n1, n2, c1, c2;
	while (scanf("%lld", &n)){
		if (n == 0)break;
		scanf("%lld%lld%lld%lld", &c1, &n1, &c2, &n2);	
		ll x, y;
		ll g = extended_gcd(n1, n2, x, y);
		if (n%g) puts("failed");
		else{
			ll l = (ll)ceil(-(double)x*n / n2);
			ll r = (ll)floor((double)y*n / n1);
			if (l > r) puts("failed");
			else{
				ll lc = (n / g)*(c1*x + c2*y) + l*(c1*n2 - c2*n1) / g;
				ll rc = (n / g)*(c1*x + c2*y) + r*(c1*n2 - c2*n1) / g;
				ll be;
				if (lc < rc) be = l;
				else be = r;
				printf("%lld %lld\n", (x*n + n2*be) / g, (y*n - n1*be) / g);
			}
		}
	}
}
