/*
  build a graph with edges between couple and 2*i+1,2*i+2
  since each edge has at least a neighbour and a girlfriend, each node  has an even degree
  so there will be no odd cycle
  so we can always 2-color the graph
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


bool vis[maxn];
int cl[maxn];
int u[maxn], v[maxn];
vector<int> adj[maxn];

void dfs(int u,int c){
    vis[u] = 1;
    cl[u] = c;
    for(int v:adj[u]) if(!vis[v])
        dfs(v,!c);
}

void solve() {
    int n; sci(n);
    lp(i,n){
        adj[2*i+1].push_back(2*i+2);
        adj[2*i+2].push_back(2*i+1);
        scii(u[i],v[i]);
        adj[u[i]].push_back(v[i]);
        adj[v[i]].push_back(u[i]);
    }
    lpi(i,1,2*n+1) if(!vis[i])
        dfs(i,0);
    lp(i,n)
        printf("%d %d\n",cl[u[i]]+1,cl[v[i]]+1);
}

int main(){
    freopen("in.txt","r",stdin);
    int tc = 1;
    //sci(tc);
    while(tc--){
        solve();
    }
}
