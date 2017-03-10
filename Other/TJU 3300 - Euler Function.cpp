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