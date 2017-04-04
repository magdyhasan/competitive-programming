#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<complex>
using namespace std;

const int maxn = 200500;

const double PI = acos(-1.0);

const double EPS = 1e-9;

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


int ccw(point a, point b, point c) {
	point v1(b - a), v2(c - a);
	double t = cp(v1, v2);
	if (t > +EPS)
		return +1;
	if (t < -EPS)
		return -1;
}

point po[maxn];

int main(){
    freopen("uva.txt","rt",stdin);
	int n;
	double x, y;
	while (scanf("%d", &n) && n){
		for (int i = 0; i < n; i++) {
			scanf("%lf%lf", &x, &y);
			po[i] = point{ x, y};
		}
		int stanScore = 0, ollieScore = 0;
		point mid = po[n / 2], 
			midVertical = mid + point{0, 1}, // 2nd point to make a vertical line from mid point
			midHorizontal = mid + point{ 1, 0 }; // 2nd point to make a horizontal line from mid point
		for (int i = 0; i < n; i++){
			if (po[i].X == mid.X || po[i].Y == mid.Y) continue;
			if (ccw(mid, midVertical, po[i]) == 1){ // on left side
				if (ccw(mid, midHorizontal, po[i]) == 1) // up
					ollieScore++;
				else // down
					stanScore++;
			}
			else{ // on right
				if (ccw(mid, midHorizontal, po[i]) == 1) // up
					stanScore++;
				else // down
					ollieScore++;
			}
		}
		printf("%d %d\n", stanScore, ollieScore);
	}
}
