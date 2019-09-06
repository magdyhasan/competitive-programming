/*
 * let dp[i][j], be string from position i with length j
 * we try all possible intermediate nodes dp[i][k]+dp[i+k][j-k]
 * also try all possible cycles in string s[i][i+j]
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

char s[maxn];

int dp[512][512];
int n;



bool cycle(int i,int j,int k){
	int ln = (j-i+1)/k;
	lp(l,k){
		lp(p,ln) if(s[l+i]!=s[l+i+p*k])
			return 0;
	}
	return 1;
}

int di(int x){
	int ret = 0;
	while(x>0){
		x /= 10;
		ret++;
	}
	return ret;
}

void solve(){
	scanf("%s",s);
	n = strlen(s);
	clr(dp,63);
	lp(i,n+1) dp[i][1] = 1, dp[i][0] = 0;
	lpi(len,2,n+1){
		lp(i,n){
			if(i+len>n) break;
			lpi(k,1,len){
				dp[i][len] = min(dp[i][len],dp[i][k]+dp[i+k][len-k]);
				if(len%k == 0 && cycle(i,i+len-1,k))
					dp[i][len] = min(dp[i][len],dp[i][k]+2+di(len/k));
			}
		}
	}
	pri(dp[0][n]);
}

int main() {
	freopen("in.txt","r",stdin);
	int tc;
	sci(tc);
	//tc = 1;
	while(tc--){
		solve();
		//puts("");
	}
}
