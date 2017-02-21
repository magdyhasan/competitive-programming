#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 1000500;

typedef long long ll;

bool notPrime[maxn];
int pr[maxn], prCnt;

void pre(){
	for (ll i = 2; i < maxn; i++) if (!notPrime[i]){
		pr[prCnt++] = i;
		for (ll j = i*i; j < maxn; j += i) notPrime[j] = true;
	}
}

int main(){
    freopen("uva.txt","rt",stdin);
	pre();
	int m, n, p, tc = 0;
	while (scanf("%d%d%d", &m, &n, &p)){
		if (!n&&!m&&!p) break;
		ll mnpp = ll(p)*p*m*n;
		if (mnpp < 0) mnpp = -mnpp;
		ll ret = 1;
		for (int i = 0; i < prCnt; i++){
			if (pr[i] * pr[i] > mnpp) break;
			ll cnt = 1;
			while (mnpp%pr[i] == 0) cnt++, mnpp /= pr[i];
			ret *= cnt;
		}
		if (mnpp > 1) ret *= 2LL;
		printf("Case %d: %lld\n", ++tc, 2LL*ret-1LL);
	}
}
