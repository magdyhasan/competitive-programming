#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<cmath>
using namespace std;

int v;
int k1, k2;



double calc(double angle){
	double h = (v*v*sin(angle)*sin(angle))/20.;
	double r = (v*v*sin(angle*2.)) / 10.;
	return k1*r + h*k2;
}

int main(){
    freopen("uva.txt","rt",stdin);
	int T;	scanf("%d", &T);
	while (T--){
		scanf("%d%d%d", &v, &k1, &k2);

		double l = 0, r = 0.5*acos(-1.0), ret = 0.;
		while(fabs(l-r) > 1e-4 ){
			double m1 = l + (r - l) / 3.;
			double m2 = r - (r - l) / 3.;
			if (calc(m1) < calc(m2)) l = m1;
			else r = m2;
		}
		printf("%.3lf %.3lf\n", l, calc(l));
	}
}
