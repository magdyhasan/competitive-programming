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


//distance from point p2 to segment p0-p1
double distToSegment(point p0, point p1, point p2, point &ret) {
	double d1, d2;
	point v1 = p1 - p0, v2 = p2 - p0;
	if ((d1 = dp(v1, v2)) <= 0)	{ // if p2 is left to segement
		ret = p0; // then p0 is the closest point to p2 
		return length(p2 - p0);
	}
	if ((d2 = dp(v1, v1)) <= d1) { // if p2 is right to segement
		ret = p1; // then p1 is the closest point to p2 
		return length(p2 - p1);
	}
	// else project p2 on segment
	double t = d1 / d2;
	ret = p0 + v1*t;
	return length(p2 - (p0 + v1*t));
}

int main(){
    freopen("uva.txt","rt",stdin);
	double x, y;
	while (scanf("%lf%lf", &x, &y) == 2){
		point p(x, y);
		int n;
		point prv, c, tc;
		double ret = 1234567891.;
		scanf("%d", &n);
		for (int i = 0; i < n + 1; i++){
			scanf("%lf%lfd", &x, &y);
			point t(x, y);
			if (i) {
				double td = distToSegment(prv, t, p, tc);
				if (ret > td)
					ret = td, c = tc;
			}
			prv = t;
		}
		printf("%.4f\n%.4f\n", c.X, c.Y);
	}
}
