#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


bool isPrime(ll n){ // O( sqrt(n) )
	if (n == 2)
		return 1;
	if (n<2 || n % 2 == 0)
		return 0;
	for (ll i = 3; i*i <= n; i += 2)
		if (n % i == 0)
			return 0;
	return 1;
}

int sumDigit(ll n){
	int ret = 0;
	while (n > 0){
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

bool Smith(ll n){
	if (isPrime(n)) return 0;
	int s = 0, s1 = sumDigit(n);
	for (ll i = 2; i*i <= n; i++) // if n is ll and i is int we enter infinte loop
		while (n%i == 0)
			s += sumDigit(i), n /= i;
	if (n>1)
		s += sumDigit(n);
	return s1 == s;
}

int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	while (T--){
		ll n; scanf("%lld", &n);
		n++;
		while (!Smith(n)) n++;
		printf("%lld\n", n);
	}
}

