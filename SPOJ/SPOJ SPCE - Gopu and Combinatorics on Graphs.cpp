/*
  From Cayley's formula and some observations
  let number of connected components = cc
  answer = multipication of each component size * (n^(cc-2))
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
const int maxn = 800500;



int cn;
bool vis[maxn];
vector<int> adj[maxn];

void dfs(int u){
    vis[u] = 1;
    ++cn;
    for(int v:adj[u]){
        if(!vis[v])
            dfs(v);
    }
}


long long pow_mod(long long base, long long power){
    long long res = 1;
    while (power){
        if (power & 1)res = res * base % mod;
        base = base * base % mod;
        power >>= 1;
    }
    return res;
}

void solve() {
    int n,m; scii(n,m);
    lp(i,n+1) vis[i] = 0, adj[i].clear();
    int ret = 1, cc = 0;
    lp(i,m){
        int u,v; scii(u,v);
        adj[u].push_back(v); adj[v].push_back(u);
    }
    lpi(i,1,n+1) if(!vis[i]){
        cn = 0;
        dfs(i);
        ++cc;
        ret = (ret*1LL*cn)%mod;
    }
    if(cc == 1){
        puts("-1"); return;
    }
    ret = (ret*1LL*pow_mod(n,cc-2))%mod;
    pri(ret);
}


int main(){
    freopen("in.txt","r",stdin);
    int tc = 1;
    sci(tc);
    lp(tt,tc){
       // printf("Case %d:\n",tt+1);
        solve();
    }
}

