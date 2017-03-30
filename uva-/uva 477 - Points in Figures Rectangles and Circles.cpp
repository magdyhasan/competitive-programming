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

int type[100], n;
double x[12], y[12], xx[12], yy[12];
double r[12];

double di(double x2, double y2, double x3, double y3){
	double dx = x3 - x2;
	double dy = y3 - y2;
	return sqrt(dx*dx + dy*dy);
}

int main(){
	freopen("test.txt", "r", stdin);
	char st[10];
	while (scanf("%s", st)){
		if (st[0] == '*') break;
		type[n] = st[0] == 'r';
		if (st[0] == 'c') scanf("%lf%lf%lf", x + n, y + n, r + n);
		else scanf("%lf%lf%lf%lf", x + n, y + n, xx + n, yy + n);
		n++;
	}
	double px, py;
	int np = 1;
	while (scanf("%lf%lf", &px, &py)){
		if (fabs(px - 9999.9) < EPS && fabs(py - 9999.9) < EPS) break;
		bool f = false;
		for (int i = 0; i < n; i++){
			if (type[i] == 0){
				if (di(x[i], y[i], px, py) - EPS < r[i]) {
					f = true;
					printf("Point %d is contained in figure %d\n", np, i + 1);
				}
			}
			else{
				if (px > x[i] && px < xx[i] && py > yy[i] && py < y[i]){
					f = true;
					printf("Point %d is contained in figure %d\n", np, i + 1);
				}
			}
		}
		if (!f) printf("Point %d is not contained in any figure\n", np);
		np++;
	}
}