/*
  if we want to place i bricks into c columns
  we have nck(i+c-1,c-1)
  we want to sum this nck from i=0 to i=n, this just nck(n+c,c)
  and subtract 1 because case i = 0
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
const ll mod = 1e6+3;
 
long long pow_mod(long long base, long long power){
    long long res = 1;
    while (power) {
        if (power & 1)res = res * base % mod;
        base = base * base % mod;
        power >>= 1;
    }
    return res;
}
 
 
ll nCk(ll n, ll k)
{
    if (k > n) return 0;
    if (k * 2 > n) k = n - k;
    if (k == 0) return 1;
 
    ll result = n;
    for (int i = 2; i <= k; ++i) {
        result = (result*(n - i + 1)) % mod;
        result = (result*pow_mod(i, mod - 2)) % mod;
    }
    return result;
}
 
int main() {
//    freopen("in.txt","r",stdin);
    int n,c; scii(n,c);
    ll ret = 0;
//    lpi(i,1,n+1)
//        ret = (ret+countWays(i+c-1,c-1))%mod;
//    prll(ret);
    prll((nCk(n+c,c)-1+mod)%mod);
}
