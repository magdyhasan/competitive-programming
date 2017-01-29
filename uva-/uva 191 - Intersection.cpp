#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <complex>
using namespace std;



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


bool pointOnRay(const point &a, const point b, const point &p)
{
	return fabs(cross(vec(a, b), vec(a, p))) < EPS && dot(vec(a, b), vec(a, p)) > -EPS;
}


bool pointOnSegment(const point &a, const point b, const point &p)
{
	if (lengthSqr(vec(a, b)) < EPS) return lengthSqr(vec(a, p)) < EPS;
	return pointOnRay(a, b, p) && pointOnRay(b, a, p);
}


bool intersectSeg(const point &a, const point &b, const point &p, const point &q)
{
	point  ret;
	double d1 = cross(p - a, b - a); //  vector(a,p) X vector(a,b)
	double d2 = cross(q - a, b - a); //  vector(a,q) X vector(a,b)
	ret = (d1 * q - d2 * p) / (d1 - d2);
	if (pointOnSegment(a, b, p) || pointOnSegment(a, b, q) // check if point of one segment is on the other segment
		|| pointOnSegment(p, q, a) || pointOnSegment(p, q, b))
		return true;
	return fabs(d1 - d2) > EPS && pointOnSegment(a, b, ret) && pointOnSegment(p, q, ret);
}


int main(){
	int tc;
	scanf("%d", &tc);
	int xStart, yStart, xEnd, yEnd, xLeft, yTop, xRight, yBottom;
	while (tc--) {
		scanf("%d%d%d%d%d%d%d%d", &xStart, &yStart, &xEnd, &yEnd, &xLeft, &yTop, &xRight, &yBottom);
		if (yTop < yBottom) // get y bottom(minimum) in yBottem
			swap(yTop, yBottom);
		if (xRight < xLeft) // get x left(minimum) in x left
			swap(xRight, xLeft);
		point lineS(xStart, yStart), lineE(xEnd,yEnd);
		point topLeft(xLeft, yTop), topright(xRight, yTop);
		point bottomLeft(xLeft, yBottom), bottomRight(xRight, yBottom);
		if (intersectSeg(topLeft, topright, lineS, lineE) || intersectSeg(topright, bottomRight, lineS, lineE) // check if line intersect with any of the rectanle 4 segments
			|| intersectSeg(bottomRight, bottomLeft, lineS, lineE) || intersectSeg(bottomLeft, topLeft, lineS, lineE) ||
			lineS.X > bottomLeft.X && lineS.X < topright.X && lineS.Y > bottomLeft.Y && lineS.Y < topLeft.Y) // check if segment is inside the rectangle
			puts("T");
		else
			puts("F");
	}
}
