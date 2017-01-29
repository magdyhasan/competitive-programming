#include<stdlib.h>
#include<stdio.h>
#include<cmath>
#include<string>
using namespace std;

double sq(double x){
	return x*x;
}

int main(){
	int tc;
	double a, b, c, d, e, f;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &c, &d, &e, &f);
		printf("%.4lf\n", sqrt(4.0 * sq(a)*sq(b)*sq(c) - sq(a)*sq(sq(b) + sq(c) - sq(f)) - sq(b)*sq(sq(a) + sq(c) - sq(e)) - sq(c)*sq(sq(a) + sq(b) - sq(d)) + (sq(b) + sq(c) - sq(f))*(sq(c) + sq(a) - sq(e))*(sq(a) + sq(b) - sq(d))) / 12.0);
	}
}