/*
  consider a graph between nodes 1,2,3,4
  a bloack is an edge between them
  we can find answer with euler path
  if number of vertices with odd #edges > 2, then we need to remove at least an edge
  we can try to remove all edges and get max
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

struct edg{
    int a,b,c;
}e[maxn];
int m;

set<int> adj[maxn];
int su[8][8], vis[8], deg[8];

int dfs(int u){
    vis[u] = 1;
    int ret = 0;
    for(int v:adj[u]) {
        ret += su[u][v];
        if(!vis[v])
            ret +=  dfs(v);
    }
    return ret;
}

int get(int skip){
    lp(i,5) adj[i].clear(), vis[i] = 0;
    lp(i,8) lp(j,8) su[i][j] = 0;
    lpi(i,1,m+1) if(i!=skip){
        int u = min(e[i].a,e[i].b), v=  max(e[i].a,e[i].b);
        adj[u].insert(v); adj[v].insert(u);
        su[u][v] += e[i].c; su[v][u] += e[i].c;
    }
    int ret = 0;
    lpi(i,1,5)
        ret = max(ret,dfs(i)/2);
    return ret;
}


void solve() {
    sci(m);
    lpi(i,1,m+1){
        sci(e[i].a); scii(e[i].c,e[i].b);
        ++deg[e[i].a]; ++deg[e[i].b];
    }
    int odd = 0;
    lpi(i,1,5) odd += deg[i]&1;
    int ret = 0;
    lpi(i,(odd < 3 ? 0:1),m+1) if(i == 0 || e[i].a != e[i].b)
        ret = max(ret,get(i));
    pri(ret);
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

