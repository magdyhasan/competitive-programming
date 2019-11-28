/*
  fix one side point, now to check which other point will minimize with this point
  we can use ternary search 
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
const int maxn = 2e5+5;
const double EPS = 1e-7;

struct po{
    ll x,y;
}a[maxn], b[maxn];

ll l[maxn];

ll sq(ll x){
    return x*x;
}

double f(int i,int j){
    return sqrt(1.*(sq(a[i].x)+sq(a[i].y))) + sqrt(1.*(sq(a[i].x-b[j].x)+sq(a[i].y-b[j].y))) + l[j];
}

void solve() {
    int n,m, aa,bb;
    scii(n,m);
    scii(aa,bb);
    lp(i,n){
        a[i].x = aa;
        scll(a[i].y);
    }
    lp(i,m){
        b[i].x = bb;
        scll(b[i].y);
    }
    lp(i,m){
        scll(l[i]);
    }
    double ans = 1e17;
    int si,sj;  //printf("%lf\n",ans);
    lp(j,m){
        int s = -1, e = n - 1;
        while(s<e-5){
            int mid = (s+e)>>1;
            if(f(mid,j)>f(mid+1,j)+EPS)
                s = mid;
            else
                e = mid;
        }
        for(int i=max(0,s);i<min(n,e+1);i++)
            if(ans > f(i,j)+EPS)
                ans = f(i,j), si = i + 1, sj = j + 1;
    }
    //printf("%lf\n",f(1,1));
    //printf("%lf\n",ans);
    printf("%d %d\n",si,sj);
}


int main(){
    freopen("in.txt","r",stdin);
    int tc = 1;
    //sci(tc);
    lp(tt,tc){
        //printf("Case %d:\n",tt+1);
        solve();
    }
}

