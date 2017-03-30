/*
-If we can reach last point on polyline before him so we can cath him, otherwise we can't reach him
-Now we know we can reach it, we find minimum time of catching it
-Binary search over time, for each time find where here would be, if i can cath him here try less time otherwise try bigger time
*/

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define all(v)           ((v).begin()), ((v).end())
#define sz size()
#define clr(v,d)         memset(v,d,sizeof(v))
#define rep(i, v)        for(int i=0;i<(v).sz;++i)
#define lp(i, n)         for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define sci(a)	scanf("%d",&a)
#define scii(a, b)	scanf("%d%d",&a, &b)
#define pri(a)	printf("%d\n",a)
#define prii(a, b)	printf("%d %d\n",a, b)
#define DB1(a)          std::cout<<#a<<"="<<(a)<<endl
#define DB2(a,b)        std::cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<endl
#define DB3(a,b,c)      std::cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<endl
#define DB4(a,b,c,d)    std::cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<endl
#define DB5(a,b,c,d,e)  std::cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<endl
typedef pair<int, int> pii;
typedef long long ll;
const ll  inf = 1000000000000000000LL;
const double EPS = 1e-9;
const ll mod = 1000000007ll;
#define PI acos(-1)

const int maxn = 500500;



struct point{
	double x, y, z;
	point(){}
	point(double _x, double _y, double _z) :
		x(_x), y(_y), z(_z){}
	void read(){
		scanf("%lf%lf%lf", &x, &y, &z);
	}
	point operator-(const point&p){
		return point(x - p.x, y - p.y, z - p.z);
	}
	point operator+(const point&p){
		return point(x + p.x, y + p.y, z + p.z);
	}
	point operator*(double d){
		return point(x*d, y*d, z*d);
	}
	double abs(){
		return sqrt(x*x + y*y + z*z);
	}
};


point polyline[maxn];

double vp, vs;
int n;

point where(double ti){
	for (int i = 0; i < n; i++){
		double segTime = (polyline[i + 1] - polyline[i]).abs() / vs;
		if (segTime >= ti){
			point dir = (polyline[i + 1] - polyline[i]);
			return polyline[i] + dir*(ti / segTime);
		}
		ti -= segTime;
	}
	return polyline[n];
}

bool can(double ti){
	return (polyline[n + 1] - where(ti)).abs() / vp <= ti;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("CF.in", "rt", stdin);
#endif	
	sci(n);
	lp(i, n + 1) polyline[i].read();
	scanf("%lf%lf", &vp, &vs);
	polyline[n + 1].read();
	double ti = 0;
	for (int i = 0; i < n; i++) ti += (polyline[i + 1] - polyline[i]).abs() / vs;
	if ((polyline[n] - polyline[n + 1]).abs() / vp > ti + EPS) {
		puts("NO"); return 0;
	}
	double l = 0, r = 1e10;
	for (int st = 0; st < 100; st++){
		double mid = (l + r) / 2.;
		if (can(mid))r = mid;
		else l = mid;
	}
	point loc = where(l);
	puts("YES");
	printf("%lf\n%lf %lf %lf", (loc - polyline[n + 1]).abs() / vp, loc.x, loc.y, loc.z);
}