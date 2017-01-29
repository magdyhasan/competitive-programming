#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

double x[3],y[3];
const double PI = acos(-1.0);

inline double square(double x){
    return x*x;
}

int main(){
    while(scanf("%lf%lf%lf%lf%lf%lf",&x[0],&y[0],&x[1],&y[1],&x[2],&y[2]) != EOF){
        // get lengths of three lengths of triangle formed by this 3 points inside the circle
        double a = sqrt(square(x[0]-x[1]) + square(y[0]-y[1]));
        double b = sqrt(square(x[1]-x[2]) + square(y[1]-y[2]));
        double c = sqrt(square(x[2]-x[0]) + square(y[2]-y[0]));
        // calculate distance from three sides of the triangle
        double s = (a+b+c)/2.0;
        s = sqrt(s*(s-a)*(s-b)*(s-c));
        // calculate radius of the circle from three sides of triangles and it's area
        double r = (a*b*c)/(4.0*s);
        // print circumference
        printf("%.2f\n",r*2*PI);
    }
}
