/*
	Notice for each point we can calcualte distance of x's and y's for others points seperatly
	to get distance from this point x to all other points x's use this BIT techinque: https://drive.google.com/open?id=0BzgibPXBVUzjcHRHVzA0TVVXQ0U
	and do same for y

	This problem can be also solved by sorting all x's and y's and for all x calculae distance to all others x and same for y
	and with this preprocessing
	just iterate through each point and add sum of x's and y's
*/


#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const int maxn = 1000500;

ll xcntT[maxn], ycntT[maxn];
ll dxT[maxn], dyT[maxn];

ll sum(ll T[], int idx){
	ll ret = 0;
	for (; idx; idx -= idx&-idx) ret += T[idx];
	return ret;
}

ll sumR(ll T[], int l, int r){
	return sum(T, r) - sum(T, l - 1);
}

void update(ll T[], int idx, ll val){
	for (; idx < maxn; idx += idx&-idx)  T[idx] += val;
}

int x[maxn], y[maxn];

int main(){
    freopen("uva.txt","rt",stdin);
	int T;	scanf("%d", &T);
	while (T--){
		int n;		scanf("%d", &n);
		for (int i = 0; i < maxn; i++) xcntT[i] = ycntT[i] = dxT[i] = dyT[i] = 0;
		for (int i = 0; i < n; i++){
			scanf("%d%d", x + i, y + i);
			update(xcntT, x[i], 1);
			update(ycntT, y[i], 1);
			update(dxT, x[i], x[i]);
			update(dyT, y[i], y[i]);
		}
		ll ret = 1234567891234567LL;
		for (int i = 0; i < n; i++){
			ll xnl = sumR(xcntT, 1, x[i]), xnr = sumR(xcntT, x[i], maxn - 100);
			ll ynl = sumR(ycntT, 1, y[i]), ynr = sumR(ycntT, y[i], maxn - 100);
			ll xspl = sumR(dxT, 1, x[i]), xspr = sumR(dxT, x[i], maxn - 100);
			ll yspl = sumR(dyT, 1, y[i]), yspr = sumR(dyT, y[i], maxn - 100);
			ret = min(ret,(x[i] * xnl - xspl) + (xspr - x[i] * xnr) + (y[i]*ynl - yspl) + (yspr - y[i]*ynr));
		}
		printf("%lld\n", ret);
	}
}
