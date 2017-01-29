#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;

vector<int> primes;

void gen(){ // sieve
	vector<int> isPrime(100500, 1);
	for (long long i = 2; i*i < 100500; i++)
		if (isPrime[i])
			for (long long j = i*i; j < 100500; j += i)
				isPrime[j] = 0;
	
	for (int i = 2; i < 100500; i++)
		if (isPrime[i])
			primes.push_back(i);
	return;
}

int L, U;

int numberOfDivisors(int n){
	int ret = 1;
	for (int i = 0; i < (int)primes.size(); i++) {
		if (n <= 1 || primes[i] > n) // if we are at a prime > n .. then we can never have next prime divide n
			break;
		int cnt = 1; // find #appearnce of primes[i] in n
		while (n % primes[i] == 0) {
			n /= primes[i];
			cnt++;
		}
		ret *= cnt;
	}
	if (n > 1)
		ret *= 2;
	return ret;
}

int main(){
	gen(); // generate all primes in range 1e5
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &L, &U);
		int mx = 0, mxi;
		for (int i = L; i <= U; i++) { // go over all the range
			int t = numberOfDivisors(i);
			if (t > mx) // mazimize on number of divisors
				mx = t, mxi = i;
		}
		printf("Between %d and %d, %d has a maximum of %d divisors.\n", L, U, mxi, mx);
	}
}
