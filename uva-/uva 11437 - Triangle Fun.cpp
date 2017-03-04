#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000500;

typedef long long ll;


#include<complex>
const double PI = acos(-1.0);

typedef complex<double> point;

#define X real()
#define Y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
//#define polar(r,ang)            ((r)*exp(point(0,ang)))  ==> Already added in c++11
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

const double EPS = 1e-8;

point intersectSegments(point a, point b, point c, point d){
	point intersect;
	double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
	double t1 = d2 / d1, t2 = d3 / d1;
	intersect = a + (b - a)*t1;
	return intersect;
}

double x[10], y[10];
// 1 2 3 4 5 6
// A B C F D E

double polygonArea(vector<point> points) {
	long double a = 0;
	for (int i = 0; i<points.size(); i++)  a += cp(points[i], points[(i + 1) % points.size()]);
	return fabs(a / 2.0);   
}

int main(){
	freopen("test.txt", "r", stdin);
	int T; scanf("%d", &T);
	while (T--){
		for (int i = 1; i <= 3; i++) scanf("%lf%lf", x + i, y + i);
		//F
		x[4] = 2 / 3.*x[1] + 1 / 3.*x[2];
		y[4] = 2 / 3.*y[1] + 1 / 3.*y[2];
		//D
		x[5] = 2 / 3.*x[2] + 1 / 3.*x[3];
		y[5] = 2 / 3.*y[2] + 1 / 3.*y[3];
		//E
		x[6] = 2 / 3.*x[3] + 1 / 3.*x[1];
		y[6] = 2 / 3.*y[3] + 1 / 3.*y[1];
		point R = intersectSegments(point(x[1], y[1]), point(x[5], y[5]), point(x[3], y[3]), point(x[4], y[4]));
		point P = intersectSegments(point(x[2], y[2]), point(x[6], y[6]), point(x[1], y[1]), point(x[5], y[5]));
		point Q = intersectSegments(point(x[2], y[2]), point(x[6], y[6]), point(x[3], y[3]), point(x[4], y[4]));
		printf("%.0lf\n", round(polygonArea({ R, P, Q })));
	}
}

