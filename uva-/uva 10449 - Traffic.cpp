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

const int inf = 1<<28;
const int maxn = 200005;//2e5+5;




void err(int x){
    pri(x);
    exit(0);
}

struct no{
    int u,v,c;
    bool operator < (const no &ot) const {
        return c < ot.c;
    }
} ed[maxn];

int a[maxn];
int n, m;
vector<int> adj[maxn];
int d[maxn];

void init(){
    lp(i,n+1) adj[i].clear(), d[i] = inf;
}

inline int cub(int x){
    return x*x*x;
}

void solve() {
    int tt = 0;
    while(sci(n) == 1){
        ++tt;
        printf("Set #%d\n",tt);
        init();
        lp(i,n) sci(a[i]);
        sci(m);
        lp(i,m)
            scii(ed[i].u,ed[i].v), ed[i].u--, ed[i].v--;
        lp(i,m)
            ed[i].c = cub(a[ed[i].v]-a[ed[i].u]);
        //lp(i,m) printf("%d %d\n",i,ed[i].c);
        d[0] = 0;
        int u,v;
        lp(st,n+1) lp(i,m){
            u = ed[i].u, v = ed[i].v;
            if (d[u] != inf && d[v] > d[u] + ed[i].c) {
                if (st == n) {
                    d[v] = -inf;
                } else
                    d[v] = d[u] + ed[i].c;
            }
        }
        int q; sci(q);
        while(q--){
            int u; sci(u); --u;
            if(d[u] < 3 || d[u] == inf) puts("?");
            else pri(d[u]);
        }
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
