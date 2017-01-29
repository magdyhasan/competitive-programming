#include<stdlib.h>
#include<stdio.h>
#include<string>
using namespace std;

int a[500];

int main(){
	int n, k;
	while (scanf("%d",&n)) {
		if (n == 0)
			break;
		for (int i = 0; i < n; i++)
			scanf("%d", a + i);
		scanf("%d", &k);
		for (int j = n - 1; j >= 0; j--) // get the last row of the difference table
			for (int i = 0; i < j; i++)
				a[i] = a[i + 1] - a[i];
		for (int i = 0; i < k; i++) // from the last row calculate next term
			for (int j = 1; j < n; j++)
				a[j] += a[j - 1];
		printf("Term %d of the sequence is %d\n", n + k, a[n - 1]);
	}
}
