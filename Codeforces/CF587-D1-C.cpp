/*
  same idea as LCA with sparse table, but using another array beside par to keep top ten values from level to level
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


struct no{
    int a[11];
    no(){
        memset(a,63,sizeof a);
    }
    void add(int v){
        a[10] = v;
        sort(a,a+11);
    }
} a[19][maxn];

no merge(no x,no y){
    no r = x;
    lp(i,11){
        r.add(y.a[i]);
    }
    return r;
}

int p[19][maxn], h[maxn];
vector<int> adj[maxn];

void dfs(int u,int pa){
    p[0][u] = pa;
    lpi(i,1,19){
        p[i][u] = p[i-1][p[i-1][u]];
        a[i][u] = merge(a[i-1][u],a[i-1][p[i-1][u]]);
    }
    for(int v:adj[u]) if(v != pa){
        h[v]= h[u] + 1;
        dfs(v,u);
    }
}

int lca(int u,int v){
    if(h[u] < h[v]) swap(u,v);
    for (int i = 18; i >= 0; i--) if (h[u] - (1 << i) >= h[v])
            u = p[i][u];
    if (u == v) return u;
    for (int i = 18; i >= 0; i--) if (p[i][u] != p[i][v])
            u = p[i][u], v = p[i][v];
    return p[0][u];
}

no get(int u, int di){
    no ret;
    lp(i,19)if(di&(1<<i)){
        ret = merge(ret,a[i][u]);
        u = p[i][u];
    }
    return ret;
}

void solve() {
    int n,m,q; scii(n,m); sci(q);
    lp(i,n-1){
        int u,v; scii(u,v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    lp(i,m){
        int c; sci(c);
        a[0][c].add(i+1);
    }
    dfs(1,1);
    lp(i,q){
        int u,v,k; scii(u,v); sci(k);
        int lc = lca(u,v);
        no r = get(u,h[u]-h[lc]);
        r = merge(r,get(v,h[v]-h[lc]+1));
        vector<int> ret;
        lp(j,11) if(r.a[j] <= m)
            ret.push_back(r.a[j]);
        printf("%d",min(k,(int)ret.size()));
        lp(j,min(k,(int)ret.size()))
            printf(" %d",ret[j]);
        puts("");
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
