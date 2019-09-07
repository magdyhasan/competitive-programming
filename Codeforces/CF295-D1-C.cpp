/*
 * dp[c1][c2][st][si], repesent we have c1 of people with weight 50, c2 of people with weight 100
 * we have st steps to make, and which side we are on
 *
 * each transition is choosing some c1+c2 <= k and goiong to other side
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

int nck(int n, int k) {
    int &res = binomial_memo[n][k];
    if (res>=0) return res;
    return res = (k==0) ? 1 : (k==n) ? 1 : (nck(n-1,k-1) + nck(n-1,k)) % mod; // with mod
}

int dp[52][52][205][2];
int tc1,tc2, k;

int rec(int c1,int c2,int st,bool si){
	if(st == 0) return (c1 == 0 && c2 == 0);
	int &ret = dp[c1][c2][st][si];
	if(ret != -1) return ret;
	ret = 0;
	if(si) c1 = tc1 - c1, c2 = tc2 - c2;
	for(int i=0;i<=c1&&i<=k;i++) for(int j=0;j<=c2&&i+j*2<=k;j++) if(i+j){
		int nc1,nc2;
		if(!si) nc1 = c1 - i, nc2 = c2 - j;
		else nc1 = tc1-c1+i, nc2 = tc2-c2+j;
		ll tv = (rec(nc1,nc2,st-1,!si)* 1LL* nck(c1,i))%mod;
		tv = (tv*nck(c2,j))%mod;
		ret =(ret+tv)% mod;
	}
	return ret;
}


void solve(){
	clr(binomial_memo,-1);
	int n; scii(n,k);
	k/=50;
	int va;
	tc1 = tc2= 0;
	lp(i,n){
		sci(va);
		tc1 += va==50;
		tc2 += va==100;
	}
	clr(dp,-1);
	lp(st,205) if(rec(tc1,tc2,st,0)){
		pri(st);
		pri(rec(tc1,tc2,st,0));
		return;
	}
	pri(-1); pri(0);
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
