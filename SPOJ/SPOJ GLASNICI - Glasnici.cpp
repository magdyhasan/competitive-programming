#include<bits/stdc++.h>
using namespace std;

double k;
double d[100500];
int n;

bool f(double ti){
	double cur = d[0] + ti;
	for (int i = 1; i < n; i++){
		if (d[i] - ti > cur + k) return 0;
		cur = min(d[i] + ti, cur + k);
	}
	return 1;
}


int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	while (T--){
		scanf("%lf%d", &k, &n); 
		for (int i = 0; i < n; i++) scanf("%lf", d + i);
		double l = 0, r = 123456789;
		for (int i = 0; i < 500; i++){
			double mid = (l + r) / 2.;
			if (f(mid)) r = mid;
			else l = mid;
		}
		printf("%lf\n", l);
	}
}
