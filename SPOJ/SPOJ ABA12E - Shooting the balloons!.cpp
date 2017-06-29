#include<stdlib.h>
#include<stdio.h>
#include<cstring>
using namespace std;

              
const int maxn = 300500;

typedef long long ll;

ll a[maxn];
ll n, k;

ll cnt(ll x){
	ll l = 0, r = 0, ret = 0;
	ll s = 0;
	while (r < n){
		s += a[r++];
		while (l<r && s > x)
			s -= a[l++];
		ret += r - l;
	}
	return ret;
}


int main(){
    freopen("uva.txt","rt",stdin);
	scanf("%lld%lld", &n, &k);
	ll s = 0;
	for (int i = 0; i < n; i++) scanf("%lld", a + i), s += a[i];
	ll l = 0, r = s;
	while (l < r){
		ll mid = (l + r) / 2LL;
		if (cnt(mid) >= k) r = mid;
		else l = mid + 1;
	}
	printf("%lld\n", l);
}
