#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<complex>
using namespace std;


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


typedef long long ll;

const int maxn = 100500;

ll x[maxn], y[maxn], v[maxn];

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

int main(){
    freopen("uva.txt","rt",stdin);
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld%lld%lld", x+i, y+i, v+i);
	}
	ll ret = -1;
	for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++){
		ll a = 0, b = 0;
		point p1(x[i], y[i]), p2(x[j], y[j]);
		for (int k = 0; k < n; k++)
			if (ccw(p1, p2, { x[k] * 1., y[k] * 1. }) == 1) a += v[k];
			else if (ccw(p1, p2, { x[k] * 1., y[k] * 1. }) == -1) b += v[k];
		// place both points in same direction
		ret = max(ret, min(a + v[i] + v[j], b));
		ret = max(ret, min(a, b + v[i] + v[j]));
		// place both points in oposite direction
		ret = max(ret, min(a + v[i], b + v[j]));
		ret = max(ret, min(a + v[j], b + v[i]));
	}
	printf("%lld", ret);
}
