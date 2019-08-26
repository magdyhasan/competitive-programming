/*
 * number of bits is 16, we can't process all possible masks for them for each input
 * this hint for meet-in-middle
 * we process for each number all it's possible left masks with their distance
 * now for each query we process all possible right masks and check already computed masks
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


const int maxn = 1e7+50;
typedef long long ll;

int ret[32];

int cnt[256][256][10];

inline int bc(int x){
	int cn = 0;
	for(int i=16;i>=0;i--){
		cn += (x>>i)&1;
	}
	return cn;
}
int n,m;

void add(){
	int x;
	sci(x);
	int left = x>>8;
	int right = x&255;
	clr(ret,0);
	lp(j,256){
		int ld = bc(j^right);
		lp(k,9)
			ret[ld+k] += cnt[left][j][k];
	}
	lp(j,m+1) printf("%d ",ret[j]);
	puts("");
	lp(j,256){
		++cnt[j][right][bc(j^left)];
	}
}

void solve(){
	scii(n,m);
	lp(i,n){
		add();
	}
}

int main() {
	freopen("in.txt","r",stdin);
	int tc;
	//sci(tc);
	tc = 1;
	while(tc--){
		solve();
		puts("");
	}
}
