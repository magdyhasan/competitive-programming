/*
  if we have matrix that give cost after a steps
  and another matrix that give cost after b steps, we can combine them to make matrix after a+b steps
  because k is large, we do it with fast power in log(k)
  
  now we have cost[i][j] after exactly k steps
  but notice that this may not be optimal
  we may go to another node after k steps and then return from it to this node with minimum cost
  which can be done easily with floyd
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
const int maxn = 600500;//2e5+5;



typedef vector<ll> row;
typedef vector<row> matrix;

matrix zero(int n, int m) {
    return matrix(n, row(m, 0));
}

matrix minf(int n, int m) {
    return matrix(n, row(m, 1LL<<55));
}


matrix identityMatrix(int n) {
    matrix ret = zero(n, n);
    for (int i = 0; i < ret.size(); i++)
        ret[i][i] = 1;
    return ret;
}


matrix multiply(const matrix &a, const  matrix &b) {
    matrix ret = minf(a.size(), b[0].size());
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b[0].size(); j++)
            for (int k = 0; k < a[0].size(); k++)
                ret[i][j] = min(ret[i][j], a[i][k] + b[k][j]);
    return ret;
}

matrix pow(const matrix& a, ll k){
    if (k == 1){
        matrix b = a;
        return b;
    }
    if (k % 2 == 1)
        return multiply(a, pow(a, k - 1));
    return pow(multiply(a, a), k / 2);
}


void solve() {
    int k; sci(k);
    int n; sci(n);
    matrix a = zero(n,n);
    lp(i,n) lp(j,n)
        scll(a[i][j]);
    matrix ka = pow(a,k);
    lp(k,n) lp(i,n) lp(j,n)
        a[i][j] = min(a[i][j],a[i][k]+a[k][j]);
    lp(i,n) lp(j,n) lp(k,n)
        ka[i][j] = min(ka[i][j],ka[i][k]+a[k][j]);
    lp(i,n){
        lp(j,n)
            printf("%lld ",ka[i][j]);
        puts("");
    }
}


int main(){
    freopen("in.txt","r",stdin);
    int tc = 1;
    sci(tc);
    lp(tt,tc){
        printf("Region #%d:\n",tt+1);
        solve();
    }
}
