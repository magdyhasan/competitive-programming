#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

bool is_prime(ll n){
	if (n <= 1)	return false;
	else if (n <= 3) return true;
	else if (n % 2 == 0 || n % 3 == 0) return false;
	ll i = 5;
	while (i * i <= n){
		if (n % i == 0 || n % (i + 2) == 0)
			return false;
		i += 6;
	}
	return true;
}



ll pow_fast(ll base, ll power){
	ll res = 1;
	while (power) {
		if (power & 1)res = res * base;
		base = base * base;
		power >>= 1;
	}
	return res;
}
int main(){
    freopen("uva.txt","rt",stdin);
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++){
		int n;
		scanf("%d", &n);
		ll n2 = pow_fast(2, n) - 1LL;
		if (is_prime(n) && is_prime(n2)) puts("Yes");
		else puts("No");
		char co;
		if (i + 1 < t) scanf("%c",&co);
	}
}
