#include<stdlib.h>
#include<stdio.h>
#include<cmath>
using namespace std;

double area(double x, double y, double z){ // // area of a triangle by Heron's formula ( from 3 sides of the triangle )
	double s = (x + y + z) / 2.0; // perimeter of triangle
	return sqrt(s*(s - x)*(s - y)*(s - z)); // area of the triangle
}


double sq(double x) { return x*x; }

int a, b, c, d, e, f;
double s, vol;

int main(){
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
	    s = area(1.0*a, 1.0*d, 1.0*b); // s is the surface of the tetrahedron ( sum of 4 triangles area )
		s += area(1.0*b, 1.0*f, 1.0*c);
		s += area(1.0*c, 1.0*e, 1.0*a);
		s += area(1.0*d, 1.0*f, 1.0*e);
		vol = sqrt(4 * sq(a)*sq(b)*sq(c) - sq(a)*sq(sq(b) + sq(c) - sq(f)) - sq(b)*sq(sq(a) + sq(c) - sq(e)) - sq(c)*sq(sq(a) + sq(b) - sq(d)) + (sq(b) + sq(c) - sq(f))*(sq(c) + sq(a) - sq(e))*(sq(a) + sq(b) - sq(d))) / 12.0; // v is the volume of the tetrahedron
		printf("%.4lf\n", vol*3.0 / s); // insphere radius of the tetrahedron = vol*3.0/s;
	}
}
