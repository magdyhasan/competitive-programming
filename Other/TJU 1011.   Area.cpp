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


inline int gcd(int a, int b){ int t; while (b){ a = a%b; t = a; a = b; b = t; }return a; }

double polygonArea(vector<point>& points) {
	long double a = 0;
	for (int i = 0; i<points.size(); i++)  a += cp(points[i], points[(i + 1) % points.size()]);
	return fabs(a / 2.0);    // If area > 0 then points ordered ccw
}


// for polygon iterate over all edges, initialize sum = numberOfPoints, and add each segment
int IntegerPointsOnSegment(const point &P1, const point &P2){
	point seg = P1 - P2;
	if (seg.Y == 0) return abs(seg.X) - 1;
	if (seg.X == 0) return abs(seg.Y) - 1;
	return (gcd(abs(seg.X), abs(seg.Y))) - 1;
}


int main(){
	freopen("uva.txt", "r", stdin);
	int T; scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++){
		int m; scanf("%d", &m);
		vector<point> pol;
		double x = 0, y = 0;
		pol.push_back({ x, y });
		for (int i = 0; i < m; i++) {
			int dx, dy;	scanf("%d%d", &dx, &dy);
			x += dx;	y += dy;
			pol.push_back({ x, y });
		}
		m++;
		double area = polygonArea(pol);
		int b = m;
		for (int i = 0; i < m; i++)
			b += IntegerPointsOnSegment(pol[i], pol[(i + 1) % m]);
		printf("Scenario #%d:\n", tc);
		printf("%d %d %.1lf\n", int((2.*area - b + 2.) / 2.), b, area);
		puts("");
	}
}