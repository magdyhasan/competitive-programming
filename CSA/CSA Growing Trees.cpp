/*
  notice that the possible behavior of diamter of the tree in number of the days,
  at first it's decrasing, then at some point it's fixed and then start increasing again
  
  so obviously we use ternary search
  
  but we can't use 2 nodes way to calculate  diamter of tree because we might have negative edges, we need to calculate it using dp
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
const int maxn = 1000500;//2e5+5;
const double EPS = 1e-7;

struct da{
    int v,a,b;
};

vector<da> adj[maxn];
ll di[maxn];
ll mxd;
int da;

void dfs(int u,int p){
    di[u] = 0;
    for(auto it:adj[u]){
        auto [v,a,b] = it;
        if(v == p) continue;
        dfs(v,u);
        mxd = max(mxd,di[u]+di[v]+a+b*da);
        di[u] = max(di[u],di[v]+a+b*da);
    }
    mxd = max(mxd,di[u]);
}

ll ge(int d){
    mxd = 0;
    da = d;
    dfs(1,0);
    return mxd;
}

void solve() {
    int n, d; scii(n,d);
    int u,v,a,b;
    lp(i,n-1){
        scii(u,v); scii(a,b);
        adj[u].push_back({v,a,b});
        adj[v].push_back({u,a,b});
    }
    int bd = d, l = 0, r = d - 1;
    while(l<=r){
        int mid = (l+r)/2;
        if(ge(mid) <= ge(mid+1))
            bd = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    printf("%d\n%lld",bd,ge(bd));
}


int main(){
  //  freopen("in.txt","r",stdin);
    int tc = 1;
    //sci(tc);
    lp(tt,tc){
//        printf("Case %d:\n",tt+1);
        solve();
    }
}
