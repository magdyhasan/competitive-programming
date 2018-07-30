#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define all(v)           ((v).begin()), ((v).end())
#define sz size()
#define clr(v,d)         memset(v,d,sizeof(v))
#define rep(i, v)        for(int i=0;i<(v).sz;++i)
#define lp(i, n)         for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define sci(a)	scanf("%d",&a)
#define scii(a, b)	scanf("%d%d",&a, &b)
#define pri(a)	printf("%d\n",a)
#define prii(a, b)	printf("%d %d\n",a, b)
#define DB1(a)          std::cout<<#a<<"="<<(a)<<endl
#define DB2(a,b)        std::cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<endl
#define DB3(a,b,c)      std::cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<endl
#define DB4(a,b,c,d)    std::cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<endl
#define DB5(a,b,c,d,e)  std::cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<endl
typedef pair<int, int> pii;
typedef long long ll;
const ll  inf = 1000000000000000000LL;
const double EPS = 1e-9;
const ll mod = 1000000007ll;
#define PI acos(-1)

const int maxn = 10000005;


bool sy[maxn], notPrime[maxn];
int cnt[maxn];
ll pr[300500];
int prCnt;

bool chk(int n){
   if(n < 2) return 0;
   int cn = 0;
   for(int i=0;i<prCnt;i++){
      if(pr[i]*pr[i] > n || n < 2) break;
      if(n%pr[i] == 0){
         int cur = 0;
         while(n%pr[i] == 0){
            cur ++;
            n /= pr[i];
         }
         cn += (cur%2==0)?1:-1;
      }
   }
   if(n > 1) cn += -1;
   return cn > 0;
}


int main(){
#ifndef ONLINE_JUDGE
	freopen("uva.txt", "rt", stdin);
#endif
   for(int i=2;i<maxn;i++) {
      if(!notPrime[i]){
         pr[prCnt++] = i;
         for(int j=i;j<maxn;j+=i){
            notPrime[j] = 1;
            cnt[j] += (((j / i) & 1) == 0)? 1:-1;
         }
      }
      sy[i] = cnt[i] > 0;
   }
	int T; sci(T);
	while(T--){
	   int n; sci(n);
	   puts(chk(n)? "Psycho Number":"Ordinary Number");
	}
}

