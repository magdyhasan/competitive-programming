#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

ll sqr(ll x) { return x*x; }

int main(){
	freopen("test.txt", "r", stdin);
	int T; scanf("%d", &T);
	while (T--){
		ll d, k; scanf("%lld%lld", &d, &k);
		ll r = 0;
		for (ll i = 1; i*i <= d; i++) if (i*i + sqr(sqrt(d - i*i)) == d)
			r++;
		if (k >= 4LL * r) puts("possible");
		else puts("impossible");
	}
}