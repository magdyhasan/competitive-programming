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

vector<pii> adj[maxn];
int subsz[maxn];
int dp[maxn], dp2[maxn];

void calcSZ(int u, int p){
	subsz[u] = 1;
	for (pii v : adj[u]) if (v.first != p){
		calcSZ(v.fi, u);
		subsz[u] += subsz[v.first];
	}
}

inline bool isLucky(int x){
	while (x > 0){
		if (x % 10 != 7 && x % 10 != 4) return 0;
		x /= 10;
	}
	return 1;
}

int n;

void dfs1(int u, int p){
	dp[u] = 0;
	for (pii v : adj[u]) if (v.first != p){
		dfs1(v.first, u);
		if (v.second == 1) dp[u] += subsz[v.fi];
		else dp[u] += dp[v.first];
	}
}

void dfs2(int u, int p){
	for (pii v : adj[u])if (v.first != p){
		if (v.second == 1) dp2[v.fi] = n - subsz[v.fi];
		else dp2[v.fi] = dp2[u] + dp[u] - dp[v.first];
		dfs2(v.first, u);
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("CF.in", "rt", stdin);
#endif
	sci(n);
	lp(i, n - 1){
		int u, v, tv; scii(u, v), sci(tv);
		adj[u].push_back({ v, isLucky(tv) });
		adj[v].push_back({ u, isLucky(tv) });
	}
	calcSZ(1, -1);
	dfs1(1, -1);
	dp2[1] = 0;
	dfs2(1, -1);
	ll ret = 0;
	for (int i = 1; i <= n; i++) {
		ll s = dp[i] + dp2[i];
		ret += s*(s - 1);
	}
	printf("%lld", ret);
}