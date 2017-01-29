#include <bits/stdc++.h>
#include <unordered_map>
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



const int  maxn = (int)200500 + 10;

int dp[maxn], cnt[maxn], a[maxn], occur[maxn];
int scnt[maxn], soccur[maxn];


int main(){
#ifndef ONLINE_JUDGE
	freopen("CF.in", "rt", stdin);
#endif	
	memset(dp, -1, sizeof(dp));
	int n, s;
	scii(n, s);	s--;
	lp(i, n) sci(a[i]);
	if (n == 1){
		puts(a[0] ? "1" : "0");
		return 0;
	}
	int z = 0;
	lp(i, n) if (a[i] == 0 && i != s) z++;
	lp(i, n)  if (i != s)cnt[a[i]]++, occur[a[i]] = 1;
	cnt[0] = occur[0] = 0;
	lpi(i, 1, maxn)	scnt[i] = cnt[i] + scnt[i - 1], soccur[i] = occur[i] + soccur[i - 1];

	int ret = 123456789;
	for (int i = 1; i < maxn; i++){
		int tz = z;
		tz += (scnt[maxn - 1] - scnt[i]);
		int need = i - soccur[i];
		need -= min(need, tz);
		need += tz;
		ret = min(ret, need + (a[s] != 0));
	}
	pri(ret);
}