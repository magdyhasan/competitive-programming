#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;


bool on[105][105];
const double EPS = 1e-8;



int dcmp(double a, double b) { return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1; }

#include<complex>
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
#define polar(r,ang)            ((r)*exp(point(0,ang))) 
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
bool isPointOnSegment(point a, point b, point c) {
	double acb = length(a - b), ac = length(a - c), cb = length(b - c);
	return dcmp(acb - (ac + cb), 0) == 0;
}

int isInsidePoly(vector<point> p, point p0) {
	int wn = 0;  // the winding number counter
	for (int i = 0; i < p.size(); i++) {
		point cur = p[i], nxt = p[(i + 1) % p.size()];
		if (isPointOnSegment(cur, nxt, p0))
			return true;
		if (cur.Y <= p0.Y) {    // Upward edge
			if (nxt.Y > p0.Y && cp(nxt - cur, p0 - cur) > EPS)
				++wn;
		}
		else {                // Downward edge
			if (nxt.Y <= p0.Y && cp(nxt - cur, p0 - cur) < -EPS)
				--wn;
		}
	}
	return wn != 0;
}

struct angleCMP {
	point center;
	angleCMP(point c) : center(c) {}
	bool operator () (const point &p0, const point p1) const {
		if (dcmp(cp(p0 - center, p1 - center), 0) == 0) {
			if (fabs(p0.Y - p1.Y) < EPS)
				return p0.X < p1.X;
			return p0.Y < p1.Y;
		}
		return  cp(p0 - center, p1 - center) < 0;
	}
};


void sortAntiClockWise(vector<point>& pnts) {
	for (int i = 0; i < pnts.size(); i++)
		if (make_pair(pnts[i].Y, pnts[i].X) < make_pair(pnts[0].Y, pnts[0].X))
			swap(pnts[0], pnts[i]);
	sort(pnts.begin(),pnts.end(), angleCMP(pnts[0]));
}




double di(int x1, int y1, int x2, int y2){
	double dx = x2 - x1, dy = y2 - y1;
	return sqrt(dx*dx + dy*dy);
}

int main(){
    freopen("uva.txt","rt",stdin);
	int m, n; scanf("%d%d", &m, &n);
	int xc, yc, r;		scanf("%d%d%d", &xc, &yc, &r);
	int x1, y1, x2, y2; scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	double cx = (x1 + x2) / 2., cy = (y1 + y2) / 2.;
	double vx = x1 - cx, vy = y1 - cy; // vector c->(x1,y1)
	double ux = vy, uy = -vx;          // rotate through 90 degrees
	double x3 = cx + ux, y3 = cy + uy; // one of the endpoints of other diagonal
	double x4 = cx - ux, y4 = cy - uy; // the other endpoint
	point a(x1, y1), b(x2, y2), c(x3, y3), d(x4, y4);
	vector<point> pol{ a, b, c, d };
	sortAntiClockWise(pol);
	for (int x = 0; x < m; x++) for (int y = 0; y < n; y++){
		point xy(x, y);
		if (di(x, y, xc, yc) < r + EPS || isInsidePoly(pol, xy))
			on[x][y] = 1;	
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			putchar(on[j][i] ? '#' : '.');
		puts("");
	}
}
