#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<cmath>
using namespace std;

double log10(double k){
	return log(k) / log(10);
}

int main(){
	long long n, k;
	while (scanf("%lld%lld",&n,&k) != EOF){
		double sum = 0;
		/*
		#digits of n = floor(log10(n))+1
		nCk = n*(n-1)*(n-2)*....(n-k+1)/k*(k-1)*...1
		log10(nCk) = log10(n) + log10(n-1) + ... log10(n-k+1) - ( log10(k) + log10(k-1) ... log101) )
		*/
		for (int i = 0; i < k; i++)
			sum += (log10(n - i) - log10(i + 1));
		printf("%d\n", (int)sum + 1);
	}
}
