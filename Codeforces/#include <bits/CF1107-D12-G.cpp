/*
  let's iterate on differences on increasing order
  if cur diff is with index i, then we need to merege it with segment i-1
  because this the max diff in merge of segment i and segment i-1 because we are iterating on order
  
  mergeing can be done easily with DSU
  we need to keep suffix,prefix,sum of each segment so we can merege
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


ll pa[maxn], su[maxn], suf[maxn], pre[maxn];

ll par(int x){
    return (x == pa[x]?x:pa[x]=par(pa[x]));
}

ll d[maxn], c[maxn], res[maxn];


void solve(){
    int n;sci(n);
    ll x; scll(x);
    ll ret = 0;
    lp(i,n){
        pa[i] = i;
        scll(d[i]);
        scll(c[i]);
        c[i] = x - c[i];
        suf[i]=pre[i] = res[i] = max(0LL,c[i]);
        su[i] = c[i];
        ret = max(ret,c[i]);
    }
    vector<pair<ll,int>> v;
    lpi(i,1,n){
        v.push_back({(d[i]-d[i-1])*1LL*(d[i]-d[i-1]),i});
    }
    sort(v.begin(),v.end());
    for(auto it:v){
        int i = it.second - 1, j = it.second;
        i = par(i); j = par(j);
        if(i != j){
            pa[j] = i;
            res[i] = max({res[i],res[j],suf[i]+pre[j]});
            suf[i] = max(suf[j],suf[i]+su[j]);
            pre[i] = max(pre[i],su[i]+pre[j]);
            su[i] += su[j];
        }
        ret = max(ret,res[i]-it.first);
    }
    prll(ret);
}


int main() {
    freopen("in.txt","r",stdin);
    solve();
}










