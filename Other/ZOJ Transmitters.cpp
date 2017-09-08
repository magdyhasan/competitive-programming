#include<bits/stdc++.h>
using namespace std;
const int maxn = 300500;




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



// Where is P2 relative to segment p0-p1?
// ccw = +1 => angle > 0 or collinear after p1
// cw = -1 => angle < 0 or collinear after p0
// Undefined = 0 => Collinar in range [a, b]. Be careful here
int ccw(point a, point b, point c) {
	point v1(b - a), v2(c - a);
	double t = cp(v1, v2);

	if (t > +EPS)
		return +1;
	if (t < -EPS)
		return -1;
	if (v1.X * v2.X < -EPS || v1.Y * v2.Y < -EPS)
		return -1;
	if (norm(v1) < norm(v2) - EPS)
		return +1;
	return 0;
}

double di(point a, point b){
	double dx = a.X - b.X, dy = a.Y - b.Y;
	return dx*dx + dy*dy;
}


int main(){
    freopen("uva.txt","rt",stdin);
	double x, y, r, xx, yy;
	while (scanf("%lf%lf%lf", &x, &y, &r)){
		if (r < 0.) break;
		int n; scanf("%d", &n);
		int ret = 0;
		vector<point> po;
		for (int i = 0; i < n; i++){
			scanf("%lf%lf", &xx, &yy);
			po.push_back(point{ xx, yy });
		}
		point ori = point{ x, y };
		for (int i = 0; i < n; i++){
			int cnt = 0;
			for (int j = 0; j < n; j++) {

				if (ccw(ori, po[i], po[j]) < 1 && di(ori, po[j]) <= r*r)
					cnt++;
			}
			ret = max(ret, cnt);
		}
		printf("%d\n", ret);
	}
}

