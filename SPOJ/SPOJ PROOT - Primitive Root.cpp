#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<vector>
using namespace std;


typedef long long ll;

ll pow_mod(ll base, ll power, ll mod){
	long long res = 1;
	while (power){
		if (power & 1)res = res * base % mod;
		base = base * base % mod;
		power >>= 1;
	}
	return res;
}

vector<int> fct(int x){
	vector<int> ret;
	for (ll i = 2; i*i <= x; i++)	if (x%i == 0){
		while (x%i == 0) x /= i;
		ret.push_back(i);
	}
	if (x > 1) ret.push_back(x);
	return ret;
}

int main(){
    freopen("uva.txt","rt",stdin);
	int p, n, tp, r;
	while (scanf("%d%d", &p, &n)){
		if (!p && !n) break;
		vector<int> fc = fct(p - 1);
		for (int i = 0; i < n; i++){
			scanf("%d", &r);
			bool f = true;
			for (int fac:fc) 
				if (pow_mod(r, (p - 1) / fac, p) == 1){
					f = false;
					break;
				}
			if (f) puts("YES");
			else puts("NO");
		}
	}
}
