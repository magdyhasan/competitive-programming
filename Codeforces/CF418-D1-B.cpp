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

const int maxn = 300500;

struct fr{
	int co, mo, pmsk;
	bool operator < (const fr &a) const{
		return mo < a.mo;
	}
} frs[105];

int n, m, b;

ll dp[1 << 20];

int main(){
#ifndef ONLINE_JUDGE
	freopen("CF.in", "rt", stdin);
#endif
	scii(n, m), sci(b);
	lp(i, n){
		scii(frs[i].co, frs[i].mo);
		frs[i].pmsk = 0;
		int ps, pn; sci(ps);
		lp(j, ps){
			sci(pn); pn--;
			frs[i].pmsk |= (1 << pn);
		}
	}
	sort(frs, frs + n);
	ll ret = 4223372036854775807LL;
	lp(j, (1 << m)) dp[j] = 4223372036854775807LL;
	dp[0] = 0;
	lp(i, n){
		lp(j, (1 << m)) if (dp[j] + frs[i].co < dp[j | frs[i].pmsk])
			dp[j | frs[i].pmsk] = dp[j] + frs[i].co;
		if (dp[(1 << m) - 1] != 4223372036854775807LL){
			ll c = dp[(1 << m) - 1] + 1LL * b*frs[i].mo;
			ret = min(ret, c);
		}
	}
	printf("%lld", ret == 4223372036854775807LL ? -1 : ret);
}

