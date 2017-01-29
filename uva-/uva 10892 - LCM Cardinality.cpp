#include<stdlib.h>
#include<stdio.h>
#include<cstring>
using namespace std;


int pr[45500], nuOfPrimes;
bool notPrime[45500];

int main(){
	for (long long i = 2; i*i < 45000; i++) // sieve to generate all primes 
		if (notPrime[i] == false)
			for (long long j = i*i; j < 45000; j += i)
				notPrime[j] = 1;
	for (int i = 2; i < 45000; i++)
		if (notPrime[i] == false)
			pr[nuOfPrimes++] = i;
	long long n, tn;
	while (scanf("%lld",&n) && n) {
		long long sum = 1;
		tn = n;
		for (int i = 0; i < nuOfPrimes; i++) { // get prime factoriaztion of n
			if (n <= 1 || pr[i] > n)
				break;
			long long cnt = 0;
			while (n % pr[i] == 0)
				n /= pr[i], cnt++;
			if (cnt)
				sum *= 2 * cnt + 1; // we can use 2*power of pr[i] + 1 
		}

		if (n > 1)
			sum *= 3;
		printf("%lld %lld\n", tn, (sum + 1) / 2); // add 1 and divide by 2 because we overcounted
	}
}
