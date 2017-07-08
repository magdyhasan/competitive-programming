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

bool vis[maxn];
int a[maxn];


inline ll GCD(ll a, ll b){
	if (b == 0)
		return a;
	return GCD(b, a%b);
}

inline ll LCM(ll a, ll b){
	return a*b / GCD(a, b);
}

int getf(int k, int x){
	if (k == 1) return a[x];
	return getf(k - 1, a[x]);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("CF.in", "rt", stdin);
#endif
	int n; sci(n);
	lpi(i, 1, n + 1) sci(a[i]);
	int t1, t2;
	ll lcm = 1;
	int mi = -1;
	lpi(i, 1, n + 1) if (vis[i] == 0){
		int cyc = 0;
		int j = i;
		int in[205] = {};
		while (in[j] == 0) {
			cyc++;
			vis[j] = 1;
			in[j] = cyc;
			j = a[j];
		}
		mi = max(mi, in[j] - 1);
		cyc = cyc - in[j] + 1;
		lcm = LCM(lcm, cyc);
	}
	ll tlcm = lcm;
	while (lcm < mi) lcm += tlcm;
	printf("%lld", lcm);
}

