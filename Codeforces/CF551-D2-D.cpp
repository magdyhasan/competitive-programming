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


ll m;

long long pow_mod(long long base, long long power){
	long long res = 1;
	while (power){
		if (power & 1)res = res * base % m;
		base = base * base % m;
		power >>= 1;
	}
	return res;
}


struct matrix{
	long long a[2][2];
	matrix() {
		memset(a, 0, sizeof(a));
	}
	matrix operator * (const matrix &p) {
		matrix c;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				for (int k = 0; k < 2; k++)
					c.a[i][j] = (c.a[i][j] + a[i][k] * p.a[k][j]) % m;
		return c;
	}
};

matrix pow(long long n, matrix t)
{
	if (n <= 1) return t;
	if (n & 1LL) return pow(n / 2, t * t) * t;
	return pow(n / 2, t * t);
}


int main(){
#ifndef ONLINE_JUDGE
	freopen("CF.in", "rt", stdin);
#endif
	ll n, k, l;
	scanf("%lld%lld%lld%lld", &n, &k, &l, &m);
	if ((l < 63 && k >= (1LL << l)) || m == 1){
		puts("0");
		return 0;
	}
	matrix a;
	a.a[0][1] = a.a[1][0] = a.a[1][1] = 1;
	a = pow(n + 2, a);
	ll ret = 1;
	lp(i, l){
		ll cur = 1;
		if (k&(1LL << i)) cur = pow_mod(2, n) - a.a[0][1];
		else cur = a.a[0][1];
		cur += m;
		cur %= m;
		ret = (ret*cur) % m;
	}
	printf("%lld", ret);
}