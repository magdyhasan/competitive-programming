#include<stdlib.h>
#include<stdio.h>
#include<cstring>
using namespace std;

const long long MAX = 1000050;
int ans[MAX];
bool notPrime[MAX];
int primes[MAX], primes_cnt;
int n;


int cnt_factors(int x){ // get sum of powers of primes factors of number x
	int ret = 0;
	for (int i = 0; i < primes_cnt; i++) {
		if (x <= 1 || primes[i] * primes[i] > x)
			break;
		while (x % primes[i] == 0) {
			x /= primes[i];
			ret++;
		}
	}
	if (x > 1)
		ret++;
	return ret;
}

int main(){
	for (long long i = 2; i < MAX; i++) // generate prime numbers
		if (notPrime[i] == false) {
			primes[primes_cnt++] = i;
			for (long long j = i*i; j < MAX; j += i)
				notPrime[j] = 1;
		}
	for (int i = 2; i < MAX; i++) // build all answers for all numers < MAX to answer all test cases in O(1) to avoid TLE
		ans[i] = ans[i - 1] + cnt_factors(i);

	while (scanf("%d", &n) != EOF) {
		printf("%d\n", ans[n]);
	}
}
