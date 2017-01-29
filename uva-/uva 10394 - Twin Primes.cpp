#include<stdlib.h>
#include<stdio.h>
#include<cstring>
using namespace std;

#define MAX 20000005

int prime_pair[MAX];
bool notPrime[MAX];


int main(){
	int lastPrime = 2, cnt = 0;
	for (long long i = 2; i < MAX; i++) // generate all primes < MAX
		if (notPrime[i] == false) {
			for (long long j = i*i; j < MAX; j += i)
				notPrime[j] = 1;
			if (i - lastPrime == 2) // if the last prime was less than this one by 2 then we want this pair
				prime_pair[cnt++] = i;
			lastPrime = i; // put this prime as the last one
		}
	int n;
	while (scanf("%d",&n) != EOF) {
		printf("(%d, %d)\n", prime_pair[n - 1] - 2, prime_pair[n - 1]);
	}
}
