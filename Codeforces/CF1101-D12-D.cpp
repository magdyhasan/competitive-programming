/*
  dfs the tree, for each node get it's prime factors, there're at most logMAXV factors
  for all children of node u, find which prime factors appear on u and v and try to build path from both of them
*/
#include <bits/stdc++.h>
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



const int maxn = 300500;

typedef long long ll;
const ll mod = 1e9+7;


int a[maxn];
vector<int> adj[maxn];

vector<int> prf[maxn];

void getpr(int x, vector<int> &vr){
    for(int i=2;i*i<=x;i++){
        if(x%i == 0) vr.push_back(i);
        while(x%i==0) x/=i;
    }
    if(x>1) vr.push_back(x);
}

vector<pair<int,int>> dp[maxn];
int ret;

void dfs(int u, int p = -1){
    map<int,vector<int>> ma;
    for(int i:prf[a[u]])
        ma[i].emplace_back(0);
    for(int v:adj[u]) if(v!=p){
        dfs(v,u);
        for(auto i:dp[v]) if(ma.count(i.first))
            ma[i.first].emplace_back(i.second);
    }
    for(auto &i:ma){
        sort(i.second.begin(),i.second.end());
        reverse(i.second.begin(),i.second.end());
        if(i.second.size()>1){
            ret = max(ret,i.second[0]+i.second[1]+1);
        }
        dp[u].emplace_back(i.first,i.second[0]+1);
    }
}

int main() {
    freopen("in.txt","r",stdin);
    lp(i,maxn) getpr(i,prf[i]);
    int n; sci(n);
    lpi(i,1,n+1) sci(a[i]) ;
    lpi(i,1,n+1) if(a[i]>1) ret = 1;
    lp(i,n-1){
        int u,v; scii(u,v);
        adj[u].push_back(v);
        adj[v].push_back(u) ;
    }
    dfs(1);
    pri(ret);
}
