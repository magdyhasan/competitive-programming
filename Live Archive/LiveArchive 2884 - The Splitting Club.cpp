/*
	Just sort the pairs by N and group as much as you can while max/min < R
*/
#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const double EPS = 1e-9;

int a[10500], b[10500];

int main(){
    freopen("uva.txt","rt",stdin);
	int n;
	double R;
	while (scanf("%d%lf", &n, &R)){
		if (n == 0 && R < EPS) break;
		for (int i = 0; i < n; i++) scanf("%d%d", a + i, b + i);
		sort(a, a + n);
		int l = 0, r = 0, ret = 0;
		while (l < n){
			while (r + 1 < n && double(a[r + 1]) / double(a[l]) < R + EPS) r++;
			ret++;
			l = r + 1, r = l;
		}
		printf("%d\n", ret);
	}
}
