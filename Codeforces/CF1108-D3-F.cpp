/*
  let's iterate on edges by their weights
  if we have now k edges of weight w
  find how many of them can we use to build MST usign DSU, call this good edges
  now see how many of them we need in building MST
  the remaining of good minus used will be added to our answer because those edges can be used in bulding another MST
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



typedef long long ll;

const ll mod = 1e6+3;

const int maxn = 300500;


int pa[maxn];
int par(int x){
    return (pa[x] == x ? x:pa[x] = par(pa[x]));
}

map<int,vector<pair<int,int>>> ed;



void solve(){
    int n,m; scii(n,m);
    lp(i,m){
        int u,v,c; scii(u,v); sci(c);
        ed[c].emplace_back(u,v);
    }
    lp(i,n+1) pa[i] = i;
    int ret = 0;
    for(auto v:ed){
        int good = 0;
        for(auto e:v.second) {
            if(par(e.first) != par(e.second)) ++good;
        }
        int us = 0;
        for(auto e:v.second){
            if(par(e.first)!=par(e.second)){
                pa[par(e.second)] = pa[par(e.first)];
                --good;
            }
        }
        ret += good;
    }
    pri(ret);
}


int main() {
    freopen("in.txt","r",stdin);
    solve();
}
















