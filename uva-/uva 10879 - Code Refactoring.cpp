#include<stdlib.h>
#include<stdio.h>
#include<string>
using namespace std;

int main(){
	int tc,	n;
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		scanf("%d", &n);
		printf("Case #%d: %d =", t, n);
		int out = 0;
		for (int i = 2; i*i <= n;i++) // go up to sqrt(n)
			if (n%i == 0) { // if i is a factor of n
				printf(" %d * %d", i, n / i);
				++out;
				if (out == 2)
					break;
				printf(" =");
			}
		puts("");
	}
}
