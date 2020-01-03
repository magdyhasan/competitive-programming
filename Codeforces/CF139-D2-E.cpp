/*
  for each position we need to know current probability of this segment
  we can do this using event sorting, by adding probability of tree to it's left and it's right
  and instead of using multipication of probability we sum log of probability to avoid precision problems
  and we handle probability 0 alone, because log(0) = -inf
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



const double eps = 1e-8;

typedef  long long ll;

const ll mod = 1e9+7;

const int inf = 1<<30;
const int maxn = 900500;//2e5+5;
const double EPS = 1e-7;


struct da{
    int x,ty;
    double p;
    bool operator < (const da & ot) const {
        return (make_pair(x,make_pair(ty,p))<make_pair(ot.x,make_pair(ot.ty,ot.p)));
    }
};


vector<da> ev;

void solve() {
    int n,m; scii(n,m);
    lp(i,n){
        int ai, hi, li, ri;
        scii(ai,hi); scii(li,ri);
        double lp = 1.0 - li/100., rp = 1.0 - ri/100.;
        ev.push_back({ai-hi,-1,lp});
        ev.push_back({ai-1,1,lp});
        ev.push_back({ai+1,-1,rp});
        ev.push_back({ai+hi,1,rp});
    }
    lp(i,m){
        int bj, zj; scii(bj,zj);
        ev.push_back({bj,0,1.*zj});
    }
    sort(ev.begin(),ev.end());
    int ze = 0;
    double pr = 0, ret = 0;
    for(auto e:ev){
        if(e.ty == 0){
            if(!ze)
                ret += exp(pr)*e.p;
        }else if(e.ty == -1){
            if(abs(e.p) < 1e-7) ++ze;
            else pr += log(e.p);
        }else{
            if(abs(e.p) < 1e-7) --ze;
            else pr -= log(e.p);
        }
    }
    printf("%lf\n",ret);
}


int main(){
    freopen("in.txt","r",stdin);
    int tc = 1;
    //sci(tc);
    lp(tt,tc){
//        printf("Case %d:\n",tt+1);
        solve();
    }
}
