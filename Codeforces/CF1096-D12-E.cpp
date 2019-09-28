/*
  fix first player score [to], and fix how many players have this score[sa]
  now we need to answer how many ways players can have score s-to*sa
  this same as number of ways to solve x1+x2+...xp-sa-1 = s-to*sa, such that xi < to
  We can do this using inclusion-exclusion and combinatorics
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


const int maxn = 1<<20;

typedef long long ll;
const ll mod = 998244353;



ll binomial_memo[5550][5550];


ll nck(int n, int k) {
    ll &res = binomial_memo[n][k];
    if (res>=0) return res;
    return res = (k==0) ? 1 : (k==n) ? 1 : (nck(n-1,k-1) + nck(n-1,k)) % mod; // with mod
}

int wy(int n, int k){ 
    if(k == 0) return n == 0;
    return nck(n+k-1,k-1);
}


ll pow_mod(ll base, ll power){
    ll res = 1;
    while (power){
        if (power & 1)res = res * base % mod;
        base = base * base % mod;
        power >>= 1;
    }
    return res;
}

ll inv(ll x){
    return pow_mod(x,mod-2);
}

int main() {
    freopen("in.txt","r",stdin);
    memset(binomial_memo,-1,sizeof binomial_memo);
    int p,s,r; scii(p,s); sci(r);
    ll a=0,b=wy(s-r,p);
    lpi(to,r,s+1) lpi(sa,1,p+1)if(sa*to<=s){
        int np = p - sa;
        int ns = s - sa * to;
        ll cur = 0;
        lp(k,np+1) if(k*to<=ns){
            ll ways = (wy(ns-k*to,np)*nck(np,k))%mod;
            if(k%2) cur = (cur-ways+mod)%mod;
            else cur = (cur+ways)%mod;
        }
        a = (a+((cur*nck(p-1,sa-1))%mod*inv(sa))%mod)%mod;
    }
    prll((a*inv(b))%mod);
    return 0;
}
