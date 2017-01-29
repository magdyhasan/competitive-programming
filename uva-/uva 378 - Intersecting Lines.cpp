#include<stdlib.h>
#include<stdio.h>
#include<complex>
#include<cmath>
using namespace std;

// geometry libary
typedef complex <double> point;
#define X real();
#define Y imag();
#define polar(r,t) ((r)*exp(point(0,(t))))
#define length(a) hypot((a).X,(a).Y)
#define angle(a) atan2((a).Y,(a).X)
#define vec(a,b) ((b)-(a))
#define dot(a,b) ((conj(a)*(b)).real())
#define cross(a,b) ((conj(a)*(b)).imag())
#define lengthSqr(a) dot(a,a)
#define rotate(v,t) ((v)*exp(point(0,t)))
#define rotateAbout(v,t,a) (rotate(vex(a,v),t)+(a))
#define reflect(V,M) (conj((V)/(M))*(M))
#define EPS 1.0e-8



bool pointOnLine(point &a, point b, point &p) {
	return fabs(cross(vec(a, b), vec(a, p))) < EPS;
}

bool intersect(point &a, point &b, point &p, point &q) {
	double d1 = cross(p - a, b - a);
	double d2 = cross(q - a, b - a);
	point ret = (d1 * q - d2 * p) / (d1 - d2);
	if (fabs(d1 - d2) > EPS) {
		printf("POINT %.2f %.2f\n", ret.real(), ret.imag());
		return true;
	}
	return false;
}

int main(){
	int tc;
	scanf("%d", &tc);
	puts("INTERSECTING LINES OUTPUT");
	while (tc--) {
		double x1, y1, x2, y2, x3, y3, x4, y4;
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
		point p11(x1, y1);
		point p12(x2, y2);
		point p21(x3, y3);
		point p22(x4, y4);
		if (intersect(p11, p12, p21, p22) == false) { // check if the're not intersecting
			if (pointOnLine(p11, p12, p21)) // if a point from the second line is on the first line then they're the same line
				puts("LINE");
			else // if not the same line and they don't intersect then they're parallel
				puts("NONE"); 
		}
	}
	puts("END OF OUTPUT");
}
