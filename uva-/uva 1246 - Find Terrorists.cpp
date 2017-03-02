/*
count number of divisor for range of number with siever
we know if we have prime p, then go for all q(q:multiples of p) and add to numberOfDivisor[q] *= i(i:p^i=q)
*/

#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 100500;
typedef long long ll;

int cnt[maxn], pr[maxn];

bool isPrime(ll n){ // O( sqrt(n) )
	if (n < maxn) return pr[n];
	if (n == 2)
		return 1;
	if (n<2 || n % 2 == 0)
		return 0;
	for (ll i = 3; i*i <= n; i += 2)
		if (n % i == 0)
			return 0;
	return 1;
}

int ans[maxn];

int main(){
    freopen("uva.txt","rt",stdin);
	for (int i = 2; i < maxn; i++) cnt[i] = 1, pr[i] = 1;
	for (int i = 2; i < maxn; i++) if (pr[i]){
		for (int j = i; j < maxn; j += i){
			int cntJ = 1, tj = j;
			while (tj && tj%i == 0) cntJ++, tj /= i;
			cnt[j] *= cntJ, pr[j] = 0;
		}
		pr[i] = 1;
	}
	int T; scanf("%d", &T);
	while (T--){
		int l, h; scanf("%d%d", &l, &h);
		int ansCnt = 0;
		for (int i = l; i <= h; i++) if (isPrime(cnt[i]))
			ans[ansCnt++] = i;
		if (ansCnt == 0) puts("-1");
		else{
			for (int i = 0; i < ansCnt; i++)
				printf("%d%s", ans[i], (i + 1 == ansCnt) ? "\n" : " ");
		}
	}
}
