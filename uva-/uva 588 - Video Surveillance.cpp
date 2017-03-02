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

bool intersectSegments(point a, point b, point c, point d, point & intersect)
{
	double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
	if (fabs(d1) < EPS) return false; // Parllel || identical
	double t1 = d2 / d1, t2 = d3 / d1;
	intersect = a + (b - a)*t1;
	if (t2 < -EPS || t2 > 1 + EPS)
		return false;
	return true;
}

// P need to be counterclockwise convex polygon
pair<vector<point>, vector<point> > polygonCut(vector<point> &p,
	point A, point B) {

	vector<point> left, right;
	point intersect;

	for (int i = 0; i < p.size(); ++i) {
		point cur = p[i], nxt = p[(i + 1) % p.size()];

		if (cp(B - A, cur - A) >= 0)
			right.push_back(cur);

		if (intersectSegments(A, B, cur, nxt, intersect)) {
			right.push_back(intersect);
			left.push_back(intersect);
		}

		if (cp(B - A, cur - A) <= 0)
			left.push_back(cur);
	}
	return make_pair(left, right);
}

int main(){
    freopen("uva.txt","rt",stdin);
	int n, tc = 0;
	while (scanf("%d", &n)){
		if (!n) break;
		vector<point> p;
		int x, y;
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &x, &y);
			p.push_back({ double(x), double(y) });
		}
		printf("Floor #%d\n", ++tc);
		vector<point> possible = p;
		for (int i = 0; i < n; i++) possible = polygonCut(possible, p[i], p[(i + 1) % n]).first;
		if (possible.empty()) puts("Surveillance is impossible.\n");
		else puts("Surveillance is possible.\n");
 	}
}
