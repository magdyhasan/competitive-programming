#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

ll nc4[10050];
ll primes[10000];
ll cnt[100005];
bool notPrime[10050];
int pr_cnt, n, t, mx;

ll rec(int num, int idx){
	ll occur = 0;
	for (int i = num; i <= mx; i += num) // find all multiples of num
		occur += cnt[i];
	ll next;
	ll ret = nc4[occur]; // how many ways to choose them
	if (occur > 3) { // if multiples of num > 3 then we have them in our choosen pairs
		for (int i = idx; i < pr_cnt; i++) { // find a prime that will make multiples with num and exclude it's multiples
			next = num * primes[i];
			if (next > (mx>>2LL))
				break;
			ret -= rec(num*primes[i], i + 1);
		}
	}
	return ret;
}

int main(){
    freopen("uva.txt","rt",stdin);
	for (ll i = 2; i < 10050;i++) // generate primes.
		if (notPrime[i] == false) {
			primes[pr_cnt++] = i;	
			for (ll j = i*i; j < 10050; j += i)
				notPrime[j] = 1;
		}
	nc4[4] = 1;
	for (ll i = 5; i < 10050; i++) // build n choose 4
		nc4[i] = (nc4[i - 1] * i) / (i - 4);
	while (scanf("%d",&n) != EOF) {
		memset(cnt, 0, sizeof(cnt));
		mx = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &t);
			cnt[t]++; // cnt occurrence of this number
			mx = max(mx, t); // get max number of all numbers
		}
		printf("%lld\n", rec(1, 0));
	}
}
