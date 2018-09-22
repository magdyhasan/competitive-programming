/*
	given formula is: h[i] = (h[i-1]+h[i+1])/2-1

	manipulate:
	by multiplying by 2 we get: 2h[i] = h[i-1]+h[i+1]+2
	then: h[i] = 2*h[i-1] - h[i-2] + 2

	so we already know h[0] which is equal to A

	we can binary search on h[1], and with fixing h[1] we can easily get h[n-1] from this formula
*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 300500;

typedef long long ll;

double h[1005];

const double EPS = 1e-6;

int n;

bool check(){
	for (int i = 2; i < n; i++){
		h[i] = 2 * h[i - 1] - h[i - 2] + 2;
		if (h[i] < EPS) return 0;
	}
	return 1;
}

int main(){
	double a;
	while (scanf("%d%lf", &n, &a) == 2){
		h[0] = a;
		double  l = 0, r = a;
		for (int i = 0; i < 150; i++){
			h[1] = (l + r) / 2.;
			if (check()) r = h[1];
			else l = h[1];
		}
		h[1] = l;
		check();
		printf("%.2lf\n", h[n - 1]);
	}
}