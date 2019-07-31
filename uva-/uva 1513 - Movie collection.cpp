/*
 * for repesenting queue we use BIT
 * when removing movie, we just query range and update point to remove it
 * and then update point in new position to add it to top of queue
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


int bit[maxn*4];

void update(int idx, int val){
	for (int x = idx; x < maxn; x = (x | (x + 1)))
		bit[x] += val;
}

int query(int idx){
	int ret = 0;
	for (int x = idx; x >= 0; x = ((x&(x + 1)) - 1))
		ret += bit[x];
	return ret;
}

int po[maxn];


void solve(){
	clr(bit,0);
	int n; sci(n);
	int q; sci(q);
	lpi(i,1,n+1) po[i] = n - i + 1, update(po[i],1);
	int cur = n;
	while(q--){
		int x; sci(x);
		printf("%d",n-query(po[x]));
		if(q) putchar(' ');
		update(po[x],-1);
		po[x] = ++ cur;
		update(po[x],1);
	}
}

int main() {
	freopen("in.txt","r",stdin);
	int tc; sci(tc);
	while(tc--){
		solve();
		puts("");
	}
}
