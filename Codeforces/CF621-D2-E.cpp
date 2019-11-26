/*
  if b was smaller we can use dp
  since b is large and answer only depend on b-1 for current state of dp
  so we can use dp with matrix exponentiation
  we can build matrix to store, if we have rem j, in how many ways we can go to rem i
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



const double eps = 1e-8;

typedef  long long ll;

const ll mod = 1e9+7;

const int inf = 1<<30;
const int maxn = 2e5+5;

typedef vector<ll> row;
typedef vector<row> matrix;

matrix zero(int n, int m) {
    return matrix(n, row(m, 0));
}

matrix identityMatrix(int n) {
    matrix ret = zero(n, n);
    for (int i = 0; i < ret.size(); i++)
        ret[i][i] = 1;
    return ret;
}

matrix multiply(const matrix &a, const  matrix &b) {
    matrix ret = zero(a.size(), b[0].size());
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b[0].size(); j++)
            for (int k = 0; k < a[0].size(); k++)
                ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % mod;
    return ret;
}

matrix pow(const matrix& a, ll k){
    if (k == 0)
        return identityMatrix(a.size());
    if (k % 2 == 1)
        return multiply(a, pow(a, k - 1));
    return pow(multiply(a, a), k / 2);
}


int cn[10];

void solve() {
    int n,b,k,x; scii(n,b); scii(k,x);
    lp(i,n){
        int d; sci(d);
        cn[d]++;
    }
    matrix t = zero(x,x), a = zero(x,x);
    lp(i,x) lp(j,10){
        t[(i*10+j)%x][i] += cn[j];
    }
    t = pow(t,b-1);
    lp(i,10)
        a[i%x][0] += cn[i];
    a = multiply(t,a);
    prll(a[k][0]);
}


int main(){
    freopen("in.txt","r",stdin);
    int tc = 1;
    //sci(tc);
    lp(tt,tc){
        //printf("Case %d:\n",tt+1);
        solve();
    }
}

