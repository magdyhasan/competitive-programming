#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;

const double PI = acos(-1);

int main(){
    freopen("uva.txt","rt",stdin);
	int T;	scanf("%d", &T);
	while (T--){
		int L; scanf("%d", &L);
		double width = (double(L)*6.) / 10.;
		double r = double(L) / 5.;
		printf("%.2lf %.2lf\n", r*r*PI, width*double(L) - r*r*PI);
	}
}
