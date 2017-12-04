#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int d[1005], s[1005];



int main(){
    freopen("uva.txt","rt",stdin);
	int n, t; 
	while (scanf("%d%d", &n, &t) == 2){
		int mi = 123456789;
		for (int i = 0; i < n; i++) scanf("%d%d", d + i, s + i), mi = min(mi, s[i]);
		double l = -mi, r = 123456789;
		for (int tt = 0; tt < 500; tt++){
			double c = (l + r) / 2.;
			double ct = 0;
			for (int i = 0; i < n; i++) ct += double(d[i]) / double(s[i] + c);
			if (ct + 1e-8>double(t)) l = c;
			else r = c;
		} 
		printf("%lf\n", l);
	}
}
