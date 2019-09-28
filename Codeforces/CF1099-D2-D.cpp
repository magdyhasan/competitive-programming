/*
  for a fixed node u with s[u] = -1
  it's optimal to put maximum value here while making into consideriation s[v]
*/
#include <bits/stdc++.h>
using namespace std;
 
#define lp(i, n)         for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define sci(a)	scanf("%d",&a)
#define scii(a, b)	scanf("%d%d",&a, &b)
#define pri(a)	printf("%d\n",a)
#define prll(a)	printf("%lld\n",a)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
 
 
const int maxn = 1e7+50;
 
typedef long long ll;
const ll mod = 1e9+7;
 
vector<int> adj[maxn];
int s[maxn];
int a[maxn];
 
void dfs(int u,int p = -1){
    if(adj[u].empty()) {
        a[u] = (s[u] == -1 ? 0:s[u]-s[p]);
        return;
    }
    if(s[u] == -1){
        int mi = 123456789;
        for(int v:adj[u])
            mi = min(mi,s[v]-s[p]);
        s[u] = s[p]+mi;
        a[u] = mi;
        for(int v:adj[u])
            a[v] = s[v]-s[u];
    } else{
        if(p == -1)
            a[u] = s[u];
        else
            a[u] = s[u] - s[p];
    }
    for(auto v:adj[u])
        dfs(v,u);
}
 
int main() {
    int n;  sci(n);
    lpi(i,2,n+1){
        int p; sci(p);
        adj[p].push_back(i);
    }
//    lpi(i,1,n+1) {
//        for(auto v:adj[i])
//            printf("%d %d\n",i,v);
//    }
    lpi(i,1,n+1) sci(s[i]);
    dfs(1);
    ll ret = 0;
    lpi(i,1,n+1) ret += 1LL*a[i];
    lpi(i,1,n+1) if(a[i] < 0) ret = -1;
    prll(ret);
    return 0;
}
