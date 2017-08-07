#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 100000000 + 9;
char prime[MAX / 16 + 2];
int pr[15000500];
int prCnt;
// each 8 bit represent 8 odd numbers

inline bool isprime_bitMasking(int n) {
	if (n == 2)				return true;
	if (n < 1 || n % 2 == 0)	return 0;
	return (prime[n >> 4] & (1 << ((n >> 1) & 7))) != 0;
}

void sieve_bitMasking() {
	memset(prime, -1, sizeof(prime));

	prime[0] = -2; // 1 is not prime number
	for (ll i = 1; 4 * i * i <= MAX; i++)
		if (prime[i >> 3] & (1 << (i & 7)))
			for (int j = 3 * i + 1; 2 * j < MAX; j += 2 * i + 1)
				prime[j >> 3] &= ~(1 << (j & 7));

	pr[0] = 2; prCnt = 1;
	for (ll i = 1; 2 * i <= MAX; i++)
		if (prime[i >> 3] & (1 << (i & 7)))
			pr[prCnt++] = 2 * i + 1;
}


bool isPrime(ll n) {
	for (int i = 0; i < prCnt && pr[i] * pr[i] <= n; i++)
		if (n % pr[i] == 0)
			return false;
	return true;
}


int main(){
    freopen("uva.txt","rt",stdin);
	sieve_bitMasking();
	int T; scanf("%d", &T);
	while (T--){
		ll n; scanf("%lld", &n);
		if (n < 5) {
			printf("2\n");
			continue;
		}
		if (n > 4294967291LL) {
			printf("4294967291\n");
			continue;
		}
		if (n & 1) n -= 2;
		else n -= 1;
		if (n < MAX) {
			for (;; n -= 2) if (isprime_bitMasking(n)) {
				printf("%lld\n", n);
				break;
			}
		}
		else {
			for (;; n -= 2) if (isPrime(n)) 	{
				printf("%lld\n", n);
				break;
			}
		}
	}
}
