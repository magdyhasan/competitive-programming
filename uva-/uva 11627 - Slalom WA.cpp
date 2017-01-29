#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int w, v, n;
int x[100500], y[100500];
int s[1000500];

const double EPS = 1e-9;

bool can(int sp){
	double l = x[0], r = x[0] + w;
	for (int i = 1; i < n; i++){
		double di = y[i] - y[i - 1];
		double t = di / double(sp);
		l -= v*t, r += v*t;
		l = max(l, double(x[i])); r = min(r, double(x[i] + w));
		if (l > r && fabs(l - r) > EPS) return 0;
	}
	return 1;
}

int main(){
    freopen("uva.txt","rt",stdin);
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d%d%d", &w, &v, &n);
		for (int i = 0; i < n; i++) scanf("%d%d", x + i, y + i);
		int S;	scanf("%d", &S);
		for (int i = 1; i <= S; i++)scanf("%d", s + i);
		sort(s + 1, s + S + 1);
		int l = 1, r = S;
		while (l < r){
			int m = (l + r + 1) / 2;
			if (can(s[m])) l = m;
			else r = m - 1;
		}
		if (l < S && can(l + 1)) l++;
		if (!can(s[l])) puts("IMPOSSIBLE");
		else printf("%d\n", s[l]);
	}
}
