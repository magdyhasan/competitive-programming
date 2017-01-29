#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

double p[30], pp[30];

int main(){
    freopen("uva.txt","rt",stdin);
	int n, r, t = 0;
	while (scanf("%d%d", &n, &r)) {
		if (!n && !r) break;
		for (int i = 0; i < n; i++) scanf("%lf", &p[i]), pp[i] = 0.;
		double allM = 0.;
		for (int mask = (1 << r) - 1; mask < (1 << n);) { // all masks with n bits and k ones, add yout code before if
			double curP = 1.;
			for (int i = 0; i < n; i++)
				if (mask&(1 << i)) curP *= p[i];
				else curP *= (1. - p[i]);
			allM += curP;
			for (int i = 0; i < n; i++)
				if (mask&(1 << i))
					pp[i] += curP;
			if (mask == 0) break;
			int x = mask & -mask, y = mask + x;
			mask = (((mask & ~y) / x) >> 1) | y;
		}
		printf("Case %d:\n", ++t);
		for (int i = 0; i < n; i++)
			printf("%.6lf\n", pp[i] / allM);
	}
}
