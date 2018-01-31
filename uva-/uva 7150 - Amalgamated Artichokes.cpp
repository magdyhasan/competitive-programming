/*
	just eveualte the functions at all k's
	now find maximum and next minimum after this maximum
*/
#include<bits/stdc++.h>
using namespace std;

const double EPS = 1e-8;
double p, a, b, c, d;

double price(int k){
	return p  * (sin(a * k + b) + cos(c * k + d) + 2.);
}
double pr[1000500];
double spr[1000500];

int main(){
    freopen("uva.txt","rt",stdin);
	int n; 
	while (scanf("%lf%lf%lf%lf%lf%d", &p, &a, &b, &c, &d, &n) == 6){
		for (int k = 1; k <= n; k++){
			pr[k] = price(k);
		}
		spr[n] = pr[n];
		for (int i = n - 1; i > 0; i--){
			spr[i] = min(pr[i], spr[i + 1]);
		}
		double ret = 0;
		for (int i = 1; i < n; i++) if (spr[i + 1] < pr[i] + EPS) {
			ret = max(ret, pr[i] - spr[i + 1]);
		}
		printf("%lf\n", ret);
	}
}
