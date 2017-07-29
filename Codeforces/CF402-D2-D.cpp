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


int a[maxn];
map<int, bool> bp;

map<int, int> fdp;
int g[maxn];
int pr[4000500], prCnt;
bool notPrime[maxn];

int f(int s){
	if (s == 1)return 0;
	if (fdp.find(s) != fdp.end()) return fdp[s];
	for (int i = 0;; i++)
		if (s%pr[i] == 0)
			return fdp[s] = (((bp.find(pr[i]) == bp.end()) ? 1 : -1) + f(s / pr[i]));
		else if (pr[i] * pr[i] > s)
			return fdp[s] = (((bp.find(s) == bp.end()) ? 1 : -1) + f(1));
}

inline int gcd(int a, int b){ int t; while (b){ a = a%b; t = a; a = b; b = t; }return a; }


int main(){
#ifndef ONLINE_JUDGE
	freopen("CF.in", "rt", stdin);
#endif
	for (ll i = 2; i*i < 1000000000000LL; i++)if (!notPrime[i]){
		pr[prCnt++] = i;
		for (ll j = i*i; j < maxn; j += i) notPrime[j] = 1;
	}
	int n, m, t; scii(n, m);
	lp(i, n) sci(a[i]);
	lp(i, m){
		sci(t), bp[t] = 1;
	}
	int ret = 0;
	g[0] = a[0];
	lp(i, n) g[i] = gcd(g[i], a[i]), g[i + 1] = g[i];
	for (int i = n - 1; i >= 0; i--){
		if (f(g[i]) < 0)
			lp(j, i + 1) a[j] = a[j] / g[i], g[j] /= g[i];
	}
	lp(i, n)
		ret += f(a[i]);
	pri(ret);
}

