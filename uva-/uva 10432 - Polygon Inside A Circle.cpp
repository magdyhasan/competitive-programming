/*
	generate all triangles by keeping 2 vectos and add it's area
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
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
//#define polar(r,ang)            ((r)*exp(point(0,ang)))  ==> Already added in c++11
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))


double polygonArea(vector<point>& points) {
	long double a = 0;
	for (int i = 0; i<points.size(); i++)  a += cp(points[i], points[(i + 1) % points.size()]);
	return fabs(a / 2.0);    // If area > 0 then points ordered ccw
}

int main(){
	freopen("uva.txt", "r", stdin);
	int n;	
	double r;
	while (scanf("%lf%d", &r, &n) == 2){
		point u(0, r), v;
		double angle = 2 * PI / double(n);
		double area = 0.;
		for (int i = 0; i < n; i++){
			v = rotateO(u, angle);
			area += cp(u, v) / 2.;
			u = v;
		}
		printf("%.3lf\n", area);
	}
}