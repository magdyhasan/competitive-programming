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



ll sm[maxn], s0[maxn];
ll segT[2][maxn * 8], f[maxn], g[maxn];
ll n, m, a, b, x, y;

ll query(bool f, ll x, ll y, ll idx = 1, ll l = 0, ll r = n){
	if (x > r || y < l) return 100000000000000000;
	if (x <= l&&y >= r) return segT[f][idx];
	int mid = (l + r) / 2, lidx = idx << 1, ridx = lidx | 1;
	return min(query(f, x, y, lidx, l, mid), query(f, x, y, ridx, mid + 1, r));
}

void update(bool f, ll x, ll y, ll idx = 1, ll l = 0, ll r = n){
	if (l == r){
		segT[f][idx] = y;
		return;
	}
	int mid = (l + r) / 2, lidx = idx << 1, ridx = lidx | 1;
	if (x <= mid) update(f, x, y, lidx, l, mid);
	else update(f, x, y, ridx, mid + 1, r);
	segT[f][idx] = min(segT[f][lidx], segT[f][ridx]);
}


int main(){
	scanf("%lld%lld%lld%lld%lld%lld", &n, &m, &a, &b, &x, &y);
	for (int i = 1; i <= n; i++){
		scanf("%lld", s0 + i);
		sm[i] = m - s0[i];
		sm[i] *= x;
		s0[i] *= y;
		sm[i] += sm[i - 1], s0[i] += s0[i - 1];
	}
	lp(i, 2) lpi(j,1, maxn) segT[i][j] = 100000000000000000;
	update(0, 0, 0);
	update(1, 0, 0);

	for (int i = 1; i <= n; i++){
		ll mi = query(0, i - b, i - a);
		f[i] = sm[i] + mi;
		update(1, i, f[i]-s0[i]);

		mi = query(1, i - b, i - a);
		g[i] = s0[i] + mi;
		update(0, i, g[i] - sm[i]);
	}
	ll ret = min(g[n], f[n]);
	printf(ret >= 100000000000000000 ? "-1" : "%lld\n", ret);
}