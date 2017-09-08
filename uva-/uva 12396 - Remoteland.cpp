#include<bits/stdc++.h>
using namespace std;


const int maxn = 7000500;
typedef long long ll;

const ll mod = 1000000007;

int pr[maxn];
bool notPr[maxn];
int prCnt;

int get_powers(ll n, ll p){
	int res = 0;
	for (ll power = p; power <= n; power *= p){
		res += n / power;
		if (power > n / p) break;
	}
	return res;
}


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
	pr[prCnt++] = 2;
	for (ll i = 3; i < maxn; i += 2)if (!notPr[i]) {
		pr[prCnt++] = i;
		for (ll j = i*i; j < maxn; j += i) notPr[j] = 1;
	}
	int n; 
	while (scanf("%d", &n)){
		if (!n)break;
		ll ret = 1;
		for (int i = 0; i < prCnt&&pr[i] <= n; i++){
			ll cnt = get_powers(n, pr[i]);
			ret = (ret*pow_mod(pr[i], get_powers(n, pr[i]) / 2 * 2)) % mod;
		}
		printf("%lld\n", ret);
	}

}
