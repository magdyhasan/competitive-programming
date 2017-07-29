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



// number of cells cell(x,y) will reach after t seconds
//moving to cells with adjacent side
//in n*n square
//from: http://codeforces.com/contest/255/submission/2779503
long long calc(ll v){
	if (v <= 0)
		return 0;
	return v*v;
}
long long calc2(ll v){
	if (v <= 0)
		return 0;
	return v*(v + 1) / 2;
}

ll n;
long long cnt(ll t, ll x, ll y){
	long long outer = 0;
	outer = (t + 1)*(t + 1) * 2 - (t + 1) * 2 + 1;

	outer -= calc(t + 1 - x);
	outer -= calc(t + 1 - y);
	outer -= calc(t - (n - x));
	outer -= calc(t - (n - y));

	outer += calc2(t - x - y + 1);
	outer += calc2(t - x - (n - y));
	outer += calc2(t - (n - x) - y);
	outer += calc2(t - (n - x) - (n - y) - 1);
	return outer;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("CF.in", "rt", stdin);
#endif
	ll c, x, y;
	scanf("%lld%lld%lld%lld", &n, &x, &y, &c);
	ll l = 0, r = n * 2, ans = -1;
	while (l <= r){
		ll mid = l + (r - l) / 2LL;
		if (cnt(mid, x, y) >= c) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	printf("%lld\n", l);
}

