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
const int maxn = 2000500;//2e5+5;




void err(int x){
    pri(x);
    exit(0);
}

int n,m;


int par(int x,vector<int> &p){
    return (x == p[x] ? x:p[x] = par(p[x], p));
}

struct edg{
    int u,v,c;
    bool operator < (const edg & ot) const {
        return c < ot.c;
    }
} ed[maxn];
int e;

int ret;
int re;
int cn;
const int lim = 400000;

void rec(int i, int co,int fo1,int fo2, vector<int> &p1, vector<int> &p2){
    if(fo1 == 1 && fo2 == 1){
        ret = min(ret,co);
        return;
    }
    if(i == e) return;
    ++cn;
    if(cn > lim) return;
    re = fo1 + fo2 - 2;
    if(ret <= co+re*ed[i].c || re > m-i) return;
    vector<int> np1 = p1, np2 = p2;
    int nco = co, nfo1 = fo1, nfo2 = fo2;
    if(fo1 != 1){
        int u = ed[i].u, v = ed[i].v;
        u = par(u,p1); v = par(v,p1);
        if(u != v){
            nco += ed[i].c;
            nfo1--;
            np1[v]= u;
        }
        rec(i+1,nco,nfo1,nfo2,np1,np2);
    }
    np1 = p1; np2 = p2;
    nco = co, nfo1 = fo1, nfo2 = fo2;
    int u = ed[i].u, v = ed[i].v;
    u = par(u,p2); v = par(v,p2);
    if(u != v){
        nco += ed[i].c;
        nfo2--;
        np2[v] = u;
    }
    rec(i+1,nco,nfo1,nfo2,np1,np2);
}

void solve() {
    while(sci(n)){
        if(!n) break;
        sci(m);
        e = 0;
        lp(i,m){
            int u,v,c;
            scii(u,v); sci(c);
            --u; --v;
            ed[e++] = {u,v,c};
        }
        sort(ed,ed+e);
        ret = inf;
        vector<int> p1(n), p2(n);
        lp(i,n) p1[i] = p2[i] = i;
        cn = 0;
        rec(0,0,n,n,p1,p2);
        if(ret >= inf) puts("No way!");
        else pri(ret);
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
