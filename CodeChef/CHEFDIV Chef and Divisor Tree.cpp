/*
generate all primes with sieve < sqrt(12)
now for each i in [A,B]
factorize i as pi^qi, pi+1^qi+1...
now we have number of divisors equal (qi+1)*(q(i+1)+1).....
and then find biggest divisor and work on that till reach 1
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 20000001;


bool notPr[maxn];
int pr[maxn];
int prCnt;

vector<int> numd(ll x){
	vector<int> ret;
	for (int i = 0; i < prCnt; i++){
		if (x <= 1 || pr[i] * pr[i] > x) break;
		int p = 0;
		while (x%pr[i] == 0){
			p++;
			x /= pr[i];
		}
		if (p) ret.push_back(p);
	}
	if (x > 1)
		ret.push_back(1);
	return ret;
}

int main(){
	freopen("test.txt", "rt", stdin);
	for (int i = 2; i < maxn; i++)if (!notPr[i]){
		pr[prCnt++] = i;
		for (ll j = 1ll * i*i; j < maxn; j += i)
			notPr[j] = 1;
	}
	ll a, b, ret = 0;
	scanf("%lld%lld", &a, &b);
	for (ll i = a; i <= b; i++){
		vector<int> pf = numd(i);
		sort(pf.begin(), pf.end());
		while (!pf.empty()){
			ll cur = 1;
			for (auto i : pf) cur *= i + 1;
			ret += cur;
			pf.back()--;
			if (!pf.back()) pf.pop_back();
			sort(pf.begin(), pf.end());
		}
	}
	printf("%lld\n", ret);
}
