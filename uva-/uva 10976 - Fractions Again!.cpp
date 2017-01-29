/*
	1/x + 1/y = 1/n
	x,y > n so we make x = n+a, y = n + b
	1/(n+a) + 1/(n+b) = 1/n
	(n+a+n+b)/(n+a)(n+b) = 1/n
	n(n+a+n+b) = (n+a)(n+b)
	n^2 + na + n^2 + nb = n^2 + nb + na + ab
	n^2 = ab
	so find all a,b such that n^2 = a*b 
*/


#include<stdlib.h>
#include<stdio.h>
#include<string>
using namespace std;

int divisors[200000];
int n, div_nu, n_square;


int main(){
	while (scanf("%d",&n) != EOF) {
		div_nu = 0;
		n_square = n*n; // get n^2
		for (int i = 1; i*i <= n_square; i++) // find all divisors of n^2
			if (n_square % i == 0)
				divisors[div_nu++] = n_square / i, divisors[div_nu++] = i;
		printf("%d\n", div_nu/2);
		for (int i = 0; i < div_nu; i += 2)
			printf("1/%d = 1/%d + 1/%d\n", n, divisors[i] + n, divisors[i + 1] + n);
	}
}
