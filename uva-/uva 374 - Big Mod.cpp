#include<stdlib.h>
#include<stdio.h>
#include<cstring>
using namespace std;

typedef long long ll;

ll mod;

long long pow_mod(long long base, long long power){ 
	long long res = 1;
	while (power) {
		if (power & 1)res = res * base % mod;
		base = base * base % mod;
		power >>= 1;
	}
	return res;
}



int main(){
	ll B, P;
	while (scanf("%lld%lld%lld", &B, &P, &mod) != EOF) printf("%lld\n", pow_mod(B, P));
}