#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<set>
using namespace std;

typedef long long ll;

ll nuc[15000];
set<ll> us, good;

int nc;


void gen(){
	for (ll i = 1;; i++){
		ll cu = i*i*i;
		if (cu > 1000500000LL) break;
		nuc[nc++] = cu;
		//us.insert(cu);
	}
}

int main(){
    freopen("uva.txt","rt",stdin);
	gen();
	for (int i = 0; i < nc; i++) for (int j = i + 1; j < nc; j++) {
		if (us.find(nuc[i] + nuc[j]) != us.end()) good.insert(nuc[i] + nuc[j]);
		us.insert(nuc[i] + nuc[j]);
	}
	ll n, r;
	while (scanf("%lld%lld", &n ,&r) != EOF){
		bool f = 0;
		auto it = good.lower_bound(n);
		while (it != good.end() && *it <= n+r){
			printf("%lld\n", *it);
			f = 1;
			it++;
		}
		if (f == 0) puts("None");
	}
}
