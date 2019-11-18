/*
  question is to count number of numbers in range divisable by any of numbers of arary a
  
  standard task of inclusion-exclusion
*/
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


const int maxn = 500500;
const double eps = 1e-8;

typedef  long long ll;

const ll mod = 1e9+7;

const ll inf = 1LL<<55;

ll a[maxn];


inline ll gcd(ll a,ll b){
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

inline ll lcm(ll a,ll b){
    return (a>inf/b) ? inf:(a*b / gcd(a, b));
}

ll lc[maxn];
int cn[maxn];
int n;

void pre(){
    lpi(m,1,(1<<n)){
        lc[m] = 1;
        int c = 0;
        lp(i,n) if(m&(1<<i)){
            lc[m] = lcm(lc[m],a[i]);
            ++c;
        }
        cn[m] = (c&1) ? 1:-1;
    }
}

ll ra(ll r, ll di){
    return r/di;
}

void solve() {
    sci(n);
    lp(i,n) scll(a[i]);
    pre();
    int d; sci(d);
    lp(dd,d){
        ll l,r, ans = 0;
        scll(l); scll(r);
        lpi(m,1,(1<<n)){
            ans += cn[m] * (ra(r,lc[m])-ra(l-1,lc[m]));
        }
        prll(ans);
    }
}


int main(){
    freopen("in.txt","r",stdin);
    int tc = 1;
    //sci(tc);
    while(tc--){
        solve();
    }
}

