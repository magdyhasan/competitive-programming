/*
  let's have dp[i][j][cnt]
  where i and j is range of string we're solving for
  and let cnt be the count of the same char as s[i] we have as our prefix
  
  -now we can remove cuurent char with eariler prefix and have a[prefix]
  -try to solve for ranges, and add prefix to new ranges
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

int n;
int a[maxn];

char s[maxn];

ll dp[102][102][102];

ll rec(int i, int j,int cn){
    if(j-i<1) return 0;
    if(j-i == 1) return a[cn];
    ll &ret = dp[i][j][cn];
    if(ret != -1) return ret;
    ret = a[cn] + rec(i+1,j,1);
    for(int p=i+1;p<j;p++) if(s[p] == s[i])
        ret = max(ret,rec(i+1,p,1)+rec(p,j,cn+1));
    return ret;
}


void solve(){
    sci(n);
    scanf("%s",s);
    lp(i,n)
        sci(a[i+1]);
    memset(dp,-1,sizeof dp);
    prll(rec(0,n,1));
}


int main() {
    freopen("in.txt","r",stdin);
    solve();
}










