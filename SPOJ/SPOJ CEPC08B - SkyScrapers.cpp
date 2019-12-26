/*
  solve it in reverse with offline queries
  at first we don't have any component, then we iterate over height in descending order and update accordingly 
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
const int maxn = 2000500;//2e5+5;
const double EPS = 1e-7;
 
struct da{
    int he,id,q;
    bool operator < (const da & ot) const {
        if(he != ot.he) return he > ot.he;
        return q > ot.q;
    }
} a[maxn];
 
 
int co;
 
bool in[maxn];
int ans[maxn];
 
 
void solve() {
    int n; sci(n);
    int d; sci(d);
    memset(in,0,sizeof in);
    lp(i,n){
        sci(a[i].he);
        a[i].id = i;
        a[i].q = 0;
    }
    lp(i,d){
        sci(a[i+n].he);
        a[i+n].id = i;
        a[i+n].q = 1;
    }
    sort(a,a+n+d);
    co = 0;
    lp(i,n+d){
        if(a[i].q){
            ans[a[i].id] = co;
            //printf(" qq %d\n",co);
        }else{
            ///printf("before %d %d\n",a[i].id,co);
            in[a[i].id] = 1;
            if(a[i].id && in[a[i].id-1] && in[a[i].id+1]) -- co;
            else if((a[i].id == 0 || !in[a[i].id-1]) && !in[a[i].id+1]) ++ co;
            //printf("after %d %d\n",a[i].id,co);
        }
    }
    lp(i,d){
        printf("%d ",ans[i]);
    }
    puts("");
}
 
 
int main(){
   // freopen("in.txt","r",stdin);
    int tc = 1;
    sci(tc);
    lp(tt,tc){
//        printf("Case %d:\n",tt+1);
        solve();
    }
} 
