/*
	We know phi(a*b*c) =  phi(a)*phi(b)*phi(c)
	also phi(p^k) = p^k-1 * (p-1)	where p is a prime number and k > 0

	each number can be repesneted as some primes p1^q1 p2^q2 ..
	so run sive and for each prime(p) go to all it's muiltple(q) ( i.e numbers that will have p in it's prime factorization)
	calculate k where p^k <= q
	Multiply phi(q) by (p^k-1 * (p-1))

	Use suffix sum of all phi's to avoid TLE
*/
#include<bits/stdc++.h>
using namespace std;


const int maxn = 3000500;

typedef long long ll;


int phi[maxn];
ll sphi[maxn];
bool notPrime[maxn];


int main(){
	for (int i = 2; i < maxn; i++) phi[i] = 1;
	for (int i = 2; i < maxn; i++) {
		if (!notPrime[i]){
			phi[i] = i - 1;
			for (int j = i * 2; j < maxn; j += i){
				notPrime[j] = true;
				int iToK = 1;
				int n = j;
				while (n%i == 0) n /= i, iToK *= i;
				phi[j] *= iToK / i*(i - 1);
			}
		}
		sphi[i] = phi[i] + sphi[i - 1];
	}
	int a, b;
	while (scanf("%d%d", &a, &b) == 2){
		printf("%lld\n", sphi[b]- sphi[a-1]);
	}
}