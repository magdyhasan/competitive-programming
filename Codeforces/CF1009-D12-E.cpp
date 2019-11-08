/*
  problem is just sum of a[i]*k[i]
  to find k[i] we make bruteforce, find sequence on oeis 
  sequence is 1 3 8 20 48 112 
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

const ll mod = 998244353;

const int maxn = 500500;



long long pow_mod(long long base, long long power){
    long long res = 1;
    while (power){
        if (power & 1)res = res * base % mod;
        base = base * base % mod;
        power >>= 1;
    }
    return res;
}

map<int,int> m;
int n;

vector<int> v;

void rec(int i,int j){
    v.push_back(j);
    if(i == n){
        for(auto p:v) m[p]++;
        v.pop_back();
        return;
    }
    rec(i+1,j+1);
    rec(i+1,1);
    v.pop_back();
}

void solve(){
    int n; sci(n);
    int ret = 0;
    int va;
    lp(i,n){
        sci(va);
        int cur = ((i+1 == n) ? 1:((n-i-1+2)*1LL*pow_mod(2LL,n-i-2))%mod);
        //printf("%d %d\n",n-i-1,cur);
        cur = (cur*1LL*va)%mod;
        ret = (ret+cur)%mod;
    }
    pri(ret);
}

int main() {
   //freopen("in.txt","r",stdin);
    int tc;
    //sci(tc);
    tc = 1;
    lp(tt,tc){
        //printf("Case #%d: ",tt+1);
        solve();
    }
}
