/*
  because we want product of 2 numbers to be prefect square
  we need the two numbers to either have even number of same prime number or if one of them have odd prime number, the other number have to have this exact prime odd number of times
  after we notice this, problem is just remove all even occurances of prime numbers
  and then find number of distinct elements in all subarrays
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
const int maxn = 1000500;//2e5+5;
const double EPS = 1e-7;


int a[maxn], b[maxn];

int pr[maxn], notPr[maxn];
int prCnt;

int fact(int x){
    int ret = x;
    x = abs(x);
    lp(i,prCnt){
        if(pr[i]*pr[i]>x) break;
        while(x%(pr[i]*pr[i]) == 0)
            x /= (pr[i]*pr[i]), ret /= (pr[i]*pr[i]);
    }
    return ret;
}

int cn[maxn];
int ret[maxn];

void solve() {
    lpi(i,2,maxn)if(!notPr[i]){
        pr[prCnt++] = i;
        for(int j=i;j<maxn;j+=i) notPr[i] = 1;
    }
    int n; sci(n);
    vector<int> ma;
    lp(i,n){
        sci(a[i]);
        a[i] = fact(a[i]);
        ma.push_back(a[i]);
    }
    sort(ma.begin(), ma.end());
    ma.resize(unique(ma.begin(), ma.end())-ma.begin());
    lp(i,n)
        b[i] = lower_bound(ma.begin(),ma.end(),a[i])-ma.begin();
//    lp(i,n){
//        printf("%d %d\n",a[i],b[i]);
//    }
    lp(i,n){
        lp(j,n) cn[j] = 0;
        int gr = 0;
        lpi(j,i,n) {
            if(a[j]){
                if(!cn[b[j]]) ++gr;
                ++cn[b[j]];
            }
            ++ret[max(1,gr)];
        }
    }
    lpi(i,1,n+1)
        printf("%d ",ret[i]);
}


int main(){
    freopen("in.txt","r",stdin);
    int tc = 1;
    //sci(tc);
    lp(tt,tc){
//        printf("Case %d:\n",tt+1);
        solve();
    }
}
