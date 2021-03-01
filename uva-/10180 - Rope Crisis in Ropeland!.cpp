/*
	First, check if segment doesn't intersect circle
	if intertsect,
	find area of sector using cos rule
	and find remaining area from the 2 points using hyp theorm
*/

#include<bits/stdc++.h>
#include <ext/numeric>
using namespace std;


#define lp(i, n)         for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define sci(a)	scanf("%d",&a)
#define scll(a)	scanf("%lld",&a)
#define scii(a, b)	scanf("%d%d",&a, &b)
#define pri(a)	printf("%d\n",a)
#define prll(a)	printf("%lld\n",a)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)




const double eps = 1e-8;

typedef  long long ll;

const ll mod = 1e9+7;

const int inf = 1<<28;
const int maxn = 1000500;//2e5+5;

typedef complex<double> point;
#define EPS 1e-9
#define OO 1e9
#define X real()
#define Y imag()
#define vec(a,b) 	((b) - (a))
#define polar(r,t) 	((r) * exp(point(0, (t))))
#define angle(v) 	(atan2((v).Y, (v).X))
#define length(v) 	((double)hypot((v).Y, (v).X))
#define lengthSqr(v) 	(dot(v, v))
#define dot(a,b) 	((conj(a) * (b)).real())
#define cross(a,b) 	((conj(a) * (b)).imag())
#define rotate(v,t) 	(polar(v, t))
#define rotateabout(v,t,a)  (rotate(vec(a, v), t) + (a))
#define reflect(p,m) 	((conj((p) / (m))) * (m))
#define normalize(p) 	((p) / length(p))
#define same(a,b) 	(lengthSqr(vec(a, b)) < EPS)
#define mid(a,b)	(((a) + (b)) / point(2, 0))


void err(int x = -1){
    pri(x);
    exit(0);
}

bool operator < ( const point& a, const point& b ) {
    return make_pair(a.X, a.Y) < make_pair(b.X, b.Y);
}

double pointLineDist(const point& a, const point& b, const point& p) {
  // handle degenrate case: (a,b) is point
  return fabs(cross(vec(a,b),vec(a,p)) / length(vec(a,b)));
}

double pointSegmentDist(const point &a, const point &b,const point &p){
        if (dot(vec(a,b),vec(a,p)) < EPS)
                return length(vec(a,p));
        if (dot(vec(b,a),vec(b,p)) < EPS)
                return length(vec(b,p));
        return pointLineDist(a, b, p);
}

//get angle opposite to side a
double cosRule(double a, double b, double c) {
        // Handle denom = 0
        double res = (b * b + c * c - a * a) / (2 * b * c);
        if (res > 1)
                res = 1;
        if (res < -1)
                res = -1;
        //dbg(a,b,c,res);
        return acos(res);
}



void solve() {
    double x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
    double r; cin >> r;
    point origin(0, 0), p1(x1, y1), p2(x2, y2);
    double segmentLn = length(vec(p1, p2));
    cout << setprecision(3) << fixed;
    if(pointSegmentDist(p1, p2, origin)+EPS > r){
        cout << segmentLn << "\n";
    }else{
        double d1 = length(p1), d2 = length(p2);
        //dbg(d1,d2,r,d1/r,d2/r,acos(d1/r), acos(d2/r));
        double arcLn = (cosRule(segmentLn, d1, d2) - acos(r/d1) - acos(r/d2)) * r;
        double rmLn = sqrt(d1*d1-r*r) + sqrt(d2*d2-r*r);
        //cout << "ELSE\n"; cout << rmLn << "\n"; cout << arcLn << "\n";
        cout << arcLn + rmLn << "\n";
    }
}



int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

    int tc = 1;
    //sci(tc);
    fast_cin();
    cin >> tc;
    lp(tt,tc){
        //      printf("Case #%d: ",tt+1);
        solve();
    }
}
