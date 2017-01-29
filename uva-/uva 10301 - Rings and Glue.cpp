#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


#include <complex>
#include <iostream>
typedef complex<double> point;
#define sz(a) ((int)(a).size())
#define all(n) (n).begin(),(n).end()
#define EPS 1e-9
#define OO 1e9

#define X real()
#define Y imag()
#define vec(a,b) ((b)-(a))
#define polar(r,t) ((r)*exp(point(0,(t))))
#define angle(v) (atan2((v).Y,(v).X))
#define length(v) ((double)hypot((v).Y,(v).X))
#define lengthSqr(v) (dot(v,v))
#define dot(a,b) ((conj(a)*(b)).real())
#define cross(a,b) ((conj(a)*(b)).imag())
#define rotate(v,t) (polar(v,t))
#define rotateabout(v,t,a) (rotate(vec(a,v),t)+(a))
#define reflect(p,m) ((conj((p)/(m)))*(m))
#define normalize(p) ((p)/length(p))
#define same(a,b) (lengthSqr(vec(a,b))<EPS)
#define mid(a,b) (((a)+(b))/point(2,0))
#define perp(a) (point(-(a).Y,(a).X))
#define colliner pointOnLine

double cosRule(double a, double b, double c) {
	// Handle denom = 0
	double res = (b * b + c * c - a * a) / (2 * b * c);
	if (res > 1)
		res = 1;
	if (res < -1)
		res = -1;
	return acos(res);
}

int circleCircleIntersection(const point &c1, const double&r1,
	const point &c2, const double&r2) {
	if (same(c1, c2) && fabs(r1 - r2) < EPS) {
		return fabs(r1) < EPS ? 1 : OO;
	}
	double len = length(vec(c1, c2));
	if (fabs(len - (r1 + r2)) < EPS || fabs(fabs(r1 - r2) - len) < EPS) {
		point d, c;
		double r;
		if (r1 > r2)
			d = vec(c1, c2), c = c1, r = r1;
		else
			d = vec(c2, c1), c = c2, r = r2;
		return 1;
	}
	if (len > r1 + r2 || len < fabs(r1 - r2))
		return 0;
	return 2;
}

double x[105], y[105], r[105];


int main(){
	int n;
	while (scanf("%d", &n) == 1){
		if (n == -1) break;
		int ret = 0;
		for (int i = 0; i < n; i++)
			scanf("%lf %lf %lf", x + i, y + i, r + i);
		vector<int> used(n + 1, 0);
		for (int i = 0; i < n;i++)	if (!used[i]){
			queue<int> q; q.push(i);	used[i] = 1;
			int cur = 1;
			while (q.empty() == false){
				int u = q.front(); q.pop();
				for (int v = 0; v < n; v++)
					if (!used[v] && circleCircleIntersection({ x[u], y[u] }, r[u], { x[v], y[v] }, r[v]) == 2)
						used[v] = 1, q.push(v), cur ++;
			}
			ret = max(ret, cur);
		}
		printf("The largest component contains %d ring%s.\n", ret, (ret == 1) ? "" : "s");
	}
}
