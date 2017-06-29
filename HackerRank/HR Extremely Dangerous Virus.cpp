#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
const ll mod = 1000000007LL;

long long pow_mod(long long base, long long power){
	long long res = 1;
	while (power){
		if (power & 1)res = res * base % mod;
		base = base * base % mod;
		power >>= 1;
	}
	return res;
}

int main(){
    freopen("uva.txt","rt",stdin);
	ll a, b, t; scanf("%lld%lld%lld", &a, &b, &t);
	printf("%lld", pow_mod((a + b) / 2, t));
}
