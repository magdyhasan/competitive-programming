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

const int maxn = 200500, L = 19;

int GCD(int a, int b)
{
	if (a<0)a *= -1;
	if (b<0)b *= -1;
	while (a&&b)a>b ? a %= b : b %= a;
	return a + b;
}


int x[maxn], y[maxn], xxmi1[4500000];

unordered_map<ll, int> cnt;

int main(){
#ifndef ONLINE_JUDGE
	freopen("CF.in", "rt", stdin);
#endif
	int n; sci(n);
	lp(i, n) scii(x[i], y[i]);
	for (int i = 2; i <= 2000; i++)
		xxmi1[i*i - i] = i;
	int a, b, c;
	lp(i, n) lp(j, n) if (i != j) {
		a = y[i] - y[j];
		b = x[j] - x[i];
		c = -a*x[i] - b*y[i];
		int q = GCD(a, GCD(b, c));
		a /= q;
		b /= q;
		c /= q;
		if (a<0 || a == 0 && b<0 || a == 0 && b == 0 && c<0)
			a *= -1, b *= -1, c *= -1;
		ll hsh = a * 27000000000LL + b * 9000000LL + c;
		cnt[hsh]++;
	}
	ll ret = ((ll)n*(n - 1)*(n - 2)) / 6;
	for (auto it : cnt){
		int cur = it.second;
		cur = xxmi1[cur];
		ret -= ((ll)cur*(cur - 1)*(cur - 2)) / 6;
	}
	printf("%lld", ret);
}

