#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)

const double EPS = 1e-8;

int main(){
    freopen("uva.txt","rt",stdin);
	double UP, D, L, B, P, DOWN, V;
	int tc = 0;
	while (scanf("%lf", &UP)){
		if (UP - EPS < 0) break;
		scanf("%lf%lf%lf%lf%lf%lf", &D, &L, &B, &P, &DOWN, &V);
		if (tc) puts("");
		printf("Scenario %d:\n", ++tc);
		printf("     up hill         %10.2lf sec\n", UP);
		printf("     well diameter   %10.2lf in\n", D);
		printf("     water level     %10.2lf in\n", L);
		printf("     bucket volume   %10.2lf cu ft\n", B);
		printf("     bucket ascent rate%8.2lf in/sec\n", P);
		printf("     down hill       %10.2lf sec\n", DOWN);
		printf("     required volume %10.2lf cu ft\n", V);
		double ti = 0;
		D /= 12.;
		L /= 12.;
		P /= 12.;
		while (V - EPS > 0){
			ti += UP;
			ti += sqrt((2.*L) / (32.2));
			ti += L / P;
			ti += DOWN;
			L += B / (PI*(.5*D)*(.5*D));
			V -= B;
		}
		printf("     TIME REQUIRED   %10.2lf sec\n", ti);
	}

}
