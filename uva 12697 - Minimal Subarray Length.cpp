/*
  BS the length of the subarray
  then standard sliding window
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
const int maxn = 3e5;
 
int n; 
ll k;
ll a[maxn];
 

bool ca(int ln){
   ll su = 0;
   for(int i=0;i<n;i++){
      su += a[i];
      if(i>= ln) su -= a[i-ln];
      if(i+1>=ln){
         if(su >= k)
            return 1;
      }
   }
   return 0;
}
 
int main(){
   int tc; sci(tc);
   while(tc--){
      sci(n); scll(k);
      lp(i,n) scll(a[i]);
      int l = 1, r = n, ans = -1;
      while(l <= r){
         int mid = (l+r) >> 1;
         if(ca(mid)){
            ans = mid;
            r = mid - 1;
         }
         else 
            l = mid + 1;
      }
      pri(ans);
   }
}
