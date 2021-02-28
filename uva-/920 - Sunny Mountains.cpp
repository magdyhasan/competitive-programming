/*
  keep lastY as last highest Y
  for each odd point, find distance bigger than last Y
  this can be easily solved using similar triangles
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

bool pcmp ( const point& a, const point& b ) {
    return make_pair(a.X, a.Y) < make_pair(b.X, b.Y);
}

point gr[maxn];


void solve() {
    int n; cin >> n;
    int x,y;
    lp(i,n){
        cin >> x >> y;
        gr[i] = {x,y};
    }
    sort(gr, gr+n, pcmp);
    reverse(gr, gr+n);
    //lp(i,n)
    //    cout << gr[i].X << " " << gr[i].Y << "\n" ;
    double lastY = gr[1].Y;
    double ln = length(vec(gr[0], gr[1]));
    for(int i=3;i<n;i+=2){
        if(gr[i].Y > lastY){
            double dy1 = gr[i].Y - gr[i-1].Y;
            double dy2 = lastY - gr[i-1].Y;
            double ds1 = length(vec(gr[i-1], gr[i]));
            //dbg(i,gr[i].X, gr[i].Y, dy1, dy2, ds1, (ds1*dy2)/dy1);
            ln += ds1 - (ds1*dy2)/dy1;
            lastY = gr[i].Y;
        }
    }
    cout << setprecision(2) << fixed << ln << "\n";
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
