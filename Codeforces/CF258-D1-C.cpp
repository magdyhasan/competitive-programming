/*
 * let fix the maximum number
 * now each other number can be set to any divisior of max number (if it's >= than it )
 * how we find what numbers are >= than current divisor? using BS
 * so for each divisor of current max number, we iterate over it's divisor's
 * and find how many numbers >= than this divisor
 *
 * but we need to handle that we need at least one number in sequence equal to max number
 * we can do that by subtracting all ways to make numbers of last divisors != max number
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


const int maxn = 2e5+50;
typedef long long ll;
int binomial_memo[120][120];

const ll mod = 1000000007;

int a[maxn];

vector<int> dvs[maxn];

long long pm(long long base, long long power){
	long long res = 1;
	while (power){
		if (power & 1)res = res * base % mod;
		base = base * base % mod;
		power >>= 1;
	}
	return res;
}

void solve(){
	int n; sci(n);
	lp(i,n) sci(a[i]);
	sort(a,a+n);
	lpi(d,1,maxn){
		for(int i=d;i<maxn;i+=d)
			dvs[i].push_back(d);
	}
	int ret = 0;
	lpi(mx,1,maxn){
		vector<int> &ds = dvs[mx];
		int m = ds.size();
		int cnt = n - (lower_bound(a,a+n,mx)-a);
		ll re = (pm(m,cnt)-pm(m-1,cnt)+mod)%mod;
		for(int i=ds.size()-2;i>=0;i--){
			int cn = n - (lower_bound(a,a+n,ds[i])-a) - cnt;
			re = (re*pm(i+1,cn))%mod;
			cnt += cn;
		}
		ret = (ret+re)%mod;
	}
	pri(ret);
}

int main() {
	freopen("in.txt","r",stdin);
	int tc;
	//sci(tc);
	tc = 1;
	while(tc--){
		solve();
		//puts("");
	}
}
