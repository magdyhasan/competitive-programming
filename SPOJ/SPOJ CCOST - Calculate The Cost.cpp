/*
 * sort queries and trees by y
 * now iterating on y's it's just 1-d problem
 * can be easily solved using BIT
 *
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


const int maxn = 300500;
typedef long long ll;

int xt[maxn], yt[maxn], vt[maxn];

int xr[maxn], yr[maxn], xr2[maxn], yr2[maxn];

const int maxBIT = 1000*1000*10 + 2;

ll bit[maxBIT];

void update(int idx, int val){
	for (int x = idx; x < maxBIT; x = (x | (x + 1)))
		bit[x] += val;
}

ll query(int idx){
	ll ret = 0;
	for (int x = idx; x >= 0; x = ((x&(x + 1)) - 1))
		ret += bit[x];
	return ret;
}

struct no{
	int x1,x2,y,si;
	bool ad;
	int qidx;
	bool operator <(const no& ot) const {
		if(y != ot.y) return y < ot.y;
		return ad > ot.ad;
	}
} po[maxn];


ll ret[maxn];

void solve(){
	int n; sci(n);
	lp(i,n)
		scii(xt[i],yt[i]), sci(vt[i]);
	int q; sci(q);
	lp(i,q)
		scii(xr[i],yr[i]), scii(xr2[i],yr2[i]);

	clr(ret,0);
	int pn = 0;
	lp(i,n) po[pn++] = {xt[i],vt[i],yt[i],1,1, -1};
	lp(i,q){
		po[pn++] = {xr[i],xr2[i],yr[i]-1,-1,0, i};
		po[pn++] = {xr[i],xr2[i],yr2[i],1,0, i};
	}
	sort(po ,po + pn);
	clr(bit,0);
	for(int j=0;j<pn;j++){
		no &i = po[j];
		if(i.ad){
			update(i.x1,i.x2);
		}else{
			ret[i.qidx] += i.si * (query(i.x2)-query(i.x1-1));
		}
	}
	lp(i,q) printf("%lld\n",ret[i]);
}

int main() {
//	freopen("in.txt","r",stdin);
	int tc; sci(tc);
	while(tc--){
		solve();
	}
}
