#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;

typedef long long ll;

bool notPrime[10000005];
int primes[10000005];
int primes_cnt, n;

int main(){
	for (ll i = 2; i < 10000005; i++) // find all primes up to 1e7
		if (notPrime[i] == false)
			for (ll j = i*i; j < 10000005; j += i)
				notPrime[j] = true;
	for (int i = 2; i < 10000005; i++)
		if (notPrime[i] == false)
			primes[primes_cnt++] = i;
	while (scanf("%d",&n) != EOF) {
		if (n < 8) // if n is less than 8 then we can't make it from 4 primes summation 
			puts("Impossible.");
		else {
			if (n % 2) // if n is odd we turn it into even positive integer  
				printf("2 3"), n -= 5; 
			else // we subtract 2 primes 2,2 to make it a positive integer so we can apply Goldbach's Conjecture
				printf("2 2"), n -= 4;
			for (int i = 0;;i++) // we try to find 2 primes sum of them is equal to new n from primes number
				if (notPrime[n - primes[i]] == false) {
					printf(" %d %d\n", primes[i], n - primes[i]);
					break;
				}
		}
	}
}
