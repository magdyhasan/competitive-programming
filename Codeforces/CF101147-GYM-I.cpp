/*
  let's move circle from left to right by sorting events
  for each circle we need to know when it touch our circle first time and when it touch it before being not completely inside it
  
  main circle radius: r, x-coordinate: x
  other circle radius: tr, coordinates: x1,y1
  this equation repesent intersection of the 2 circles: 
  r = tr+sqrt((x-x1)^2+y1^2)
  r^2 = tr^2+(x-x1)^2+y1^2
  r^2-tr^2-y1^2 = (x-x1)^2
  
  now x have 2 possible values for entering and exiting
*/
#include <bits/stdc++.h>
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



typedef long long ll;

const ll mod = 1e6+3;

const int maxn = 300500;


struct eve{
    double x;
    ll r;
    bool operator < (const eve &ot) const {
        if(x != ot.x) return x < ot.x;
        return r > ot.r;
    }
};
vector<eve> ve;

ll r;
ll x,y,tr;



int main() {
    freopen("in.txt","r",stdin);
    int tc; sci(tc);
    while(tc--){
        int n; sci(n);
        scll(r);
        ve.clear();
        lp(i,n){
            scll(x); scll(y); scll(tr);
            if(tr<=r){
                ll d = (r-tr)*(r-tr)-y*y;
                if(d>=0){
                    double tx = sqrt(d*1.0);
                    ve.push_back({x+tx,-tr});
                    ve.push_back({x-tx,tr});
                }
            }
        }
        sort(ve.begin(),ve.end()) ;
        ll ret = 0, cur = 0;
        for(auto i:ve){
            cur += i.r;
            ret = max(ret,cur);
        }
        prll(ret);
    }
}
















