
/*
	represent n! and k as their prime fackorization
	say n!: p^x p1^y p2^z
	say k : p^b p1^n p2^m
	if(b > x || n > y || m > z) answer is 0 because k can't divide n! 
	else find min(x/b,y/n,z/m) becuase when we power k we power each prime and each prime of k must be <= this prime in n!


	Note: 
	to find prime factorization of n!
	we can use get_powers(n,p) which for a given prime(p) count how many times this prime appear in n!
*/

#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;



typedef long long ll;

ll get_powers(ll n, ll p){
	ll res = 0;
	for (ll power = p; power <= n; power *= p){
		res += n / power;
		if (power > n / p) break;
	}
	return res;
}


int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	while (T--){
		ll n, k;	scanf("%lld%lld", &n, &k);
		ll ret = 8223372036854775807LL;
		for (ll i = 2; i*i <= k; i++) if (k%i == 0){
			ll cntI = 0;
			while (k%i == 0) cntI++, k /= i;
			ret = min(ret, get_powers(n, i) / cntI);
		}
		if (k > 1) ret = min(ret, get_powers(n, k));
		printf("%lld\n", ret);
	}
}
