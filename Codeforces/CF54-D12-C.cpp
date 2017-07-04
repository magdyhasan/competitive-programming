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


ll numberOfOnes(ll x){
	if (x <= 1) return x;
	ll ret = 0;
	ll p = 1;
	while (2 * p <= x){
		ret += 2 * p - p;
		p *= 10LL;
	}
	if (p <= x)
		ret += x - p + 1;
	return ret;
}



double pr[1500];

double dp[1005][1005];
bool vis[1005][1005];

int K, n;

double rec(int idx, int k){
	if (idx >= n) return ((double(K) / 100.*double(n)) < double(k) + 1e-9) ? 1. : 0.;
	double &ret = dp[idx][k];
	if (vis[idx][k]) return ret;
	ret = rec(idx + 1, k + 1)*pr[idx] + rec(idx + 1, k)*(1 - pr[idx]);
	vis[idx][k] = 1;
	return ret;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("CF.in", "rt", stdin);
#endif
	sci(n);
	ll l, r;
	lp(i, n){
		scanf("%I64d%I64d", &l, &r);
		ll ones = numberOfOnes(r) - numberOfOnes(l - 1);
		pr[i] = double(ones) / double(r - l + 1LL);
	}
	memset(vis, 0, sizeof(vis));
	sci(K);
	printf("%.10lf", rec(0, 0));
}

