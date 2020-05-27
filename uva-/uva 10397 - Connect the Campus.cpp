#include<bits/stdc++.h>
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

const int inf = 1<<30;
const int maxn = 2000500;//2e5+5;




void err(int x){
    pri(x);
    exit(0);
}

int n;
char c[505][5];


int p[maxn];
int par(int x){
    return (x == p[x] ? x:p[x] = par(p[x]));
}

void init(){
    lp(i,n+1) p[i] = i;
}

struct edg{
    int u,v;
    double c;
    bool operator < (const edg & ot) const {
        return c < ot.c+eps;
    }
} ed[maxn];
int e;

int x[maxn], y[maxn];

inline int sq(int x){
    return x*x;
}
inline double di(int i,int j){
    return sqrt(sq(x[i]-x[j])+sq(y[i]-y[j]));
}

void solve() {
    while(sci(n) == 1){
        init();
        lp(i,n){
            scii(x[i],y[i]);
        }
        e = 0;
        lp(i,n) lpi(j,i+1,n)
                ed[e++] = {i,j,di(i,j)};
        sort(ed,ed+e);
        int m;
        sci(m);
        lp(i,m){
            int u,v; scii(u,v);
            --u; --v;
            u = par(u); v = par(v);
            if(u!=v)
                p[v] = u;
        }
        double ret = 0;
        lp(j,e){
            int u = ed[j].u, v = ed[j].v;
            double c = ed[j].c;
            //printf("%d %d %.2lf\n",u,v,c);
            u = par(u); v = par(v);
            if(u != v){
                p[v] = u;
                ret += c;
            }
        }
        printf("%.2lf\n",ret);
    }
}



int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif

    int tc = 1;
    //sci(tc);
    lp(tt,tc){
        //      printf("Case #%d: ",tt+1);
        solve();
    }
}
