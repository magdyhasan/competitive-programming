/*
	we can find for each domino that first domino it doesn't cover
	and record cost from this domino to that domino it doesn't cover

	but for each query we might iterate over all domino's so we need something faster

	since jumping from domino to another we just need add operation
	we can use sparse table idea
	for each domino build nxt[][19], co[][19]
	where nxt[][j] repest if make jump  of length 2^j where we end
	and co[][j] of this jump

	just like in LCM we can build this table and answer queiries easily 

	ALso, there's another offline solution
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define all(v)           ((v).begin()), ((v).end())
#define sz size()
#define clr(v,d)         memset(v,d,sizeof(v))
#define lp(i, n)         for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define sci(a)	scanf("%d",&a)
#define scl(a)	scanf("%lld",&a)
#define scii(a, b)	scanf("%d%d",&a, &b)
#define pri(a)	printf("%d\n",a)
#define prl(a)	printf("%lld\n",a)


const int maxn = 1000500;

int n;

namespace rmq {
	int tree[maxn];

	void upd(int x, int v) {
		while (x <= n) {
			tree[x] = max(tree[x], v);
			x += x & -x;
		}
	}

	int get(int x) {
		int ret = 0;
		while (x > 0) {
			ret = max(ret, tree[x]);
			x -= x & -x;
		}
		return ret;
	}
};

int p[maxn], l[maxn], ri[maxn];

const int LOG = 19;

int nxt[maxn][LOG], co[maxn][LOG];



int main(){
	sci(n);
	lp(i, n) scii(p[i], l[i]);
	for (int i = n - 1; i >= 0; i--){
		ri[i] = max(p[i] + l[i], rmq::get(upper_bound(p, p + n, p[i] + l[i]) - p - 1));
		nxt[i][0] = upper_bound(p, p + n, ri[i]) - p;
		co[i][0] = max(0, p[nxt[i][0]] - ri[i]);
		if(i) rmq::upd(i, ri[i]);
	}
	nxt[n][0] = n;
	for (int k = 1; k < LOG; k++){
		nxt[n][k] = n;
		lp(i, n){
			nxt[i][k] = nxt[nxt[i][k - 1]][k - 1];
			co[i][k] = co[i][k - 1] + co[nxt[i][k - 1]][k - 1];
		}
	}
	int q; sci(q);
	while (q--){
		int a, b; scii(a, b);
		--a; --b;
		int ret = 0;
		for (int k = LOG - 1; k >= 0; k--) if (nxt[a][k] <= b){
			ret += co[a][k];
			a = nxt[a][k];
		}
		pri(ret);
	}
}