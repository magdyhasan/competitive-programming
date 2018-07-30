/*
	make a cumlative array to store area of polygon ending at edge i
	now given query(a,b) find cs[b]-cs[a]+cp(b,a)
*/
#include<bits/stdc++.h>
using namespace std;


#include<complex>
const double PI = acos(-1.0);

typedef complex<double> point;

const double EPS = 1e-8;
#define X real()
#define Y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel

double cs[60000];

int main(){
	freopen("test.in", "rt", stdin);
	int n, q, tc = 0;
	while (scanf("%d%d", &n, &q)){
		if (!n) break;
		if (tc) puts("");
		++tc;
		vector<point> po;
		memset(cs, 0, sizeof cs);
		for (int i = 0; i < n; i++){
			int x, y; scanf("%d%d", &x, &y);
			po.push_back({ 1.*x, 1.*y });
			if (i) cs[i] = cs[i - 1] + cp(po[i], po[i - 1]);
		}
		cs[n] = cs[n - 1] + cp(po[0], po[n - 1]);
		while (q--){
			int a, b; scanf("%d%d", &a, &b);
			double fa = cs[b] - cs[a] + cp(po[a], po[b]);
			printf("%.1lf\n", min(fa, cs[n] - fa)*0.5);
		}
	}
}
