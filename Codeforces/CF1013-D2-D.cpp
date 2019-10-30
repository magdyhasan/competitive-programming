/*

*/
/*
  Think of the table as graph, connecting rows and columns
  answer is just number of compoments - 1
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

int n,m;

vector<int> adj[maxn];
bool vis[maxn];

void dfs(int u){
    vis[u] = 1;
    for(int v:adj[u]) if(!vis[v])
        dfs(v);
}

void solve() {
    int n,m,k; scii(n,m); sci(k);
    lp(i,k){
        int x,y; scii(x,y);
        adj[x].push_back(y+n);
        adj[y+n].push_back(x);
    }
    int cc=  0;
    lpi(i,1,n+m+1) if(!vis[i]){
        ++cc;
        dfs(i)  ;
    }
    pri(cc-1);
}

int main(){
    freopen("in.txt","r",stdin);
    int tc = 1;
    //sci(tc);
    while(tc--){
        solve();
    }
}
