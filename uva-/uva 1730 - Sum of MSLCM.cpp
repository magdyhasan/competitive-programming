/*
  problem is just, sum of divisors of a number n
  which is multipication of (p^e-1)/(p-1), for prime in prime factorization of number n
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
const int maxn = 2e7+5;

int lp[maxn];
int pr[maxn], prCnt;
ll su[maxn];



void solve() {
    for (int i=2; i<maxn; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr[prCnt++] = i;
        }
        for (int j=0; j<prCnt && pr[j]<=lp[i] && i*pr[j]< maxn; ++j)
            lp[i * pr[j]] = pr[j];
    }
    for(int i=2;i<maxn;i++){
        int n=i;
        su[i] = 1;
        while(lp[n]){
            ll cp = lp[n], pp = lp[n];
            while(n%cp == 0){
                n /= cp;
                pp *= cp;
            }
            su[i] *= (pp-1)/(cp-1);
        }
    }
//    lpi(i,2,11)
//        printf("%d %lld\n",i,su[i]);
    int n;
    while(true){
        sci(n);
        if(!n) break;
        ll ret =0;
        lpi(i,2,n+1) ret += su[i];
        prll(ret);
    }
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

