#include<stdlib.h>
#include<stdio.h>
#include<cstring>
using namespace std;

long long n, m, tm;
long long pr[100500], nuOfPrimes;
bool notPrime[100500];


int get_powers(long long prime){ // find prime^ret in n! prime factorization
	long long ret = 0;
	for (long long power = prime; power <= n; power *= prime) 
		ret += n / power;
	return ret;
}



int main(){
	for (long long i = 2; i*i < 100500; i++) // sieve to generate primes 
		if (notPrime[i] == false)
			for (long long j = i*i; j < 100500; j += i)
				notPrime[j] = 1;
	for (int i = 2; i < 100500; i++)
		if (notPrime[i] == false)
			pr[nuOfPrimes++] = i; // put all prime in pr
	while (scanf("%lld%lld",&n,&m) != EOF) {
		tm = m; 
		bool div = 1; // keep wheter we can divide by m or not
		int i;
		for ( i = 0; i < nuOfPrimes; i++) { // factorize m
			if (m <= 1 || pr[i] > m) 
				break;
			int cnt = 0;
			while (m % pr[i] == 0) // pr[i] is from the prime factorization of m
				m /= pr[i], cnt++;
			if (cnt > 0 && get_powers(pr[i]) < cnt) { // see pr[i] power in the n! if it < cnt ( power of pr[i] in m )
				div = 0;
				break;
			}
		}
		if (m > 1) // m is prime
			if (get_powers(m) < 1)
				div = 0;
		if (div)
			printf("%lld divides %lld!\n", tm, n);
		else
			printf("%lld does not divide %lld!\n", tm, n);
	}
}
