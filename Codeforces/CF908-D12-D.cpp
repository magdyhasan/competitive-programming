/*
 * let's build dp[as][ab]
 * where as is current number of a's we have now
 * and ab number of ab subsequences we have
 *
 * we have 2 choices, we add a with pa probability or b with pb probability
 *
 * because as can grow infinite, when we as >= k
 * we know next b will end sequence for sure
 * so we use formula for this case which is,
 * number of expected ab's is: (1-p)/p, where p = pb
 */
#include <bits/stdc++.h>
using namespace std;


#define all(v)          ((v).begin()), ((v).end())
#define sz size()
#define clr(v,d)         memset(v,d,sizeof(v))
#define lp(i, n)         for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define sci(a)	scanf("%d",&a)
#define scii(a, b)	scanf("%d%d",&a, &b)
#define pri(a)	printf("%d\n",a)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)


const int maxn = 600500;
typedef long long ll;

const ll mod = 1e9+7;

long long pow_mod(long long base, long long power){
	long long res = 1;
	while (power){
		if (power & 1)res = res * base % mod;
		base = base * base % mod;
		power >>= 1;
	}
	return res;
}

inline ll inv(ll x){
	return pow_mod(x,mod-2);
}
ll k,pa,pb, su;
ll dp[1005][1005];

ll rec(int as,int ab){
	if(ab>=k) return ab;
	if(as>=k) return (ab+as+((1-pb+mod)%mod)*inv(pb))%mod;
	ll &ret = dp[as][ab];
	if(ret != -1) return ret;
	return ret = ((rec(as+1,ab)*pa)%mod + (rec(as,ab+as)*pb)%mod)%mod;
}


void solve(){
	cin >> k >> pa >> pb;
	su = inv(pa+pb);
	pa = (pa*su)%mod;
	pb = (pb*su)%mod;
	clr(dp,-1);
	cout << rec(1,0);
}

int main() {
	//freopen("in.txt","r",stdin);
	int tc;
	//sci(tc);
	tc = 1;
	while(tc--){
		solve();
		puts("");
	}
}
