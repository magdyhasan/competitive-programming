/*
 *	notice that, when we start from position x, we either go left or right
 *	going left or right to some specific point, it's always optimal to take other points on the way
 *	so we sort the point
 *	start from x
 *	have a dp[i][j][f], i our current left point, j current right pointer
 *	f, whether we came from right or left
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


int su[maxn];

int n,v,x;

struct da{
	int x,c,d;
	bool operator < (const da& ot) const {
		return x < ot.x;
	}
}a[maxn];


double dp[1005][1005][2];
bool vis[1005][1005][2];

double ti(int i,int j){
	return (abs(a[i].x-a[j].x)*1.0/(1.*v));
}

double rec(int i, int j, bool f){
	if(i<1&&j>n+1) return 0;
	double &ret =dp[i][j][f];
	if(vis[i][j][f]) return ret;
	vis[i][j][f] = 1;
	ret = 1e11;
	int c = (f ? j-1:i+1);
	//if(!(c>0&&c<n+2)) return ret;
	if(i) ret = min(ret,rec(i-1,j,0)+ti(i,c)*(su[i]+su[n+1]-su[j-1]));
	if(j<n+2) ret = min(ret,rec(i,j+1,1)+ti(j,c)*(su[i]+su[n+1]-su[j-1]));
	return ret;
}

void solve(){
	 while(scanf("%d%d%d",&n,&v,&x)!=-1){
		 if(!n)break;
		 a[0] = {-1,0,0};
		 a[n+1] = {x,0,0};
		 int alc = 0;
		 lpi(i,1,n+1){
			 sci(a[i].x); scii(a[i].c, a[i].d);
			 alc += a[i].c;
		 }
		 sort(a+1,a+n+2);
		 su[0] = 0;
		 lpi(i,1,n+2) su[i] = su[i-1]+a[i].d;
		 int i = 1;
		 for(;;i++) if(a[i].x == x)
			 break;
		 clr(vis,0);
		 pri(int(rec(i-1,i+1,0)+1e-7)+alc);
	 }
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
