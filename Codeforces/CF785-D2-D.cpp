/*
  for each opening bracket, let's fix this as the last open bracket in our sequence,
  now we need sum over all length k of nck(k/2,#opening brackets till now)*nck(k/2,,#opening brackets to the right)
  we get this sum in one term using "Vandermonde's Identity"
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


const int maxn = 300500;
const double eps = 1e-8;

typedef  long long ll;

const ll mod = 1e9+7;

int n,m;
char s[maxn];
int l[maxn], r[maxn];

ll fact[maxn], invf[maxn];

long long pow_mod(long long base, long long power){
    long long res = 1;
    while (power) {
        if (power & 1)res = res * base % mod;
        base = base * base % mod;
        power >>= 1;
    }
    return res;
}

void prenCkmod(){
    fact[0] = invf[0] = 1;
    for (int i = 1; i < maxn; i++){
        fact[i] = fact[i - 1] * i % mod;
        invf[i] = pow_mod(fact[i], mod - 2);
    }
}

ll nCkMOD(ll n, ll k){
    if (k > n) return 0LL;
    return fact[n] * (invf[n - k] * invf[k] % mod) % mod;
}


void solve() {
    prenCkmod();
    scanf("%s",s+1);
    n = strlen(s+1);
    lpi(i,1,n+1){
        l[i] = (s[i] == '(') + l[i-1];
    }
    for(int i=n;i>0;i--){
        r[i] = (s[i] == ')') + r[i+1];
    }
    int ret =0;
    lpi(i,1,n+1) if(s[i] == '('){
        //printf("%d %d\n",l[i],r[i]);
        ret = (ret+nCkMOD(l[i]+r[i]-1,l[i]))%mod;
    }
    pri(ret);
}

int main(){
    freopen("in.txt","r",stdin);
    int tc = 1;
    //sci(tc);
    while(tc--){
        solve();
    }
}
