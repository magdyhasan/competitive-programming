#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;




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


bool intersectSegments(point a, point b, point c, point d, point & intersect) {
	double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
	if (fabs(d1) < EPS)
		return false;  // Parllel || identical

	double t1 = d2 / d1, t2 = d3 / d1;
	intersect = a + (b - a) * t1;

	if (t1 < -EPS || t2 < -EPS || t2 > 1 + EPS)
		return false;  //e.g ab is ray, cd is segment ... change to whatever
	return true;
}


// 2 points has infinite circles
// Find circle passes with 3 points, some times, there is no circle! (in case colinear)
// Draw two perpendicular lines and intersect them
// may be see https://www.topcoder.com/community/data-science/data-science-tutorials/geometry-concepts-line-intersection-and-its-applications/
point findCircle(point a, point b, point c) {
	//create median, vector, its prependicular
	point m1 = (b + a)*0.5, v1 = b - a, pv1 = point(v1.Y, -v1.X);
	point m2 = (b + c)*0.5, v2 = b - c, pv2 = point(v2.Y, -v2.X);
	point end1 = m1 + pv1, end2 = m2 + pv2, center;
	intersectSegments(m1, end1, m2, end2, center);
	return center;
}


int main(){
    freopen("uva.txt","rt",stdin);
	int tc = 0;
	int n;	
	while (scanf("%d", &n) && n){
		double x[3], y[3];
		for (int i = 0; i < 3; i++) scanf("%lf%lf", x + i, y + i);
		point center = findCircle({ x[0], y[0] }, { x[1], y[1] }, { x[2], y[2] });
		double ang = 2.*PI / n;
		point u(x[0], y[0]);
		double maxx = x[0], minx = x[0], maxy = y[0], miny = y[0];
		for (int i = 0; i+1 < n; i++){
			u = rotateA(u, ang, center);
			maxx = max(maxx, u.X); minx = min(minx, u.X);
			maxy = max(maxy, u.Y); miny = min(miny, u.Y);
		}
		printf("Polygon %d: %.3lf\n", ++tc, (maxx - minx)*(maxy - miny));
	}
}
