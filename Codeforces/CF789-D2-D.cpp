/*
  after chossing two edges to use them only once, remaining is check whether we have euler path
  if we choose two non adjacent edges to use them only once, it means we have 4 vertices with odd degree so we can't have euler path
  so we just have three cases
  -choose one loop and one edge
  -choose two loops
  -choose two adjacent edges
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
const int maxn = 1<<22;//2e5+5;
const double EPS = 1e-7;

int lo[maxn];
vector<int> adj[maxn];

inline ll f(int x){
    return x*1LL*(x-1)/2;
}

int vis[maxn];
void dfs(int u){
    vis[u]  = 1;
    for(int v:adj[u]) if(!vis[v])
       dfs(v);
}

void solve() {
    int n,m; scii(n,m);
    ll los = 0;
    lp(i,m){
        int u,v; scii(u,v);
        if(u == v) los++, lo[u] = 1;
        else adj[u].push_back(v), adj[v].push_back(u);
    }
    lpi(i,1,n+1) if(adj[i].size() || lo[i]){
        dfs(i); break;
    }
    lpi(i,1,n+1)    if(!vis[i] && (adj[i].size()|| lo[i])){
        puts("0"); return;
    }
    ll ret = 0;
    lpi(i,1,n+1){
        ret += f(adj[i].size());
    }
    ret += los * 1LL * (m - los);
    ret += f(los);
    prll(ret);
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

