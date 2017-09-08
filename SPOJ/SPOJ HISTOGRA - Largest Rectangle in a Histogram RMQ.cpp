#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

//standard implementation for rmq
const int maxn = 300500;

int segT[maxn * 8], a[maxn];
int n;

int query(int x, int y, int idx = 1, int l = 1, int r = n){
	if (r < x || l > y) return -1;
	if (x <= l && r <= y) return segT[idx];
	int mid = (l + r) / 2, lidx = idx << 1, ridx = lidx | 1;
	int lq = query(x, y, lidx, l, mid), rq = query(x, y, lidx | 1, mid + 1, r);
	if (lq == -1) return rq;
	if (rq == -1) return lq;
	if (a[lq] < a[rq]) return lq;
	return rq;
}

void build(int idx = 1, int l = 1, int r = n){
	if (l == r){
		segT[idx] = l;
		return;
	}
	int mid = (l + r) / 2, lidx = idx << 1, ridx = lidx | 1;
	build(lidx, l, mid);
	build(ridx, mid + 1, r);
	if (a[segT[lidx]] <= a[segT[ridx]]) segT[idx] = segT[lidx];
	else segT[idx] = segT[ridx];
}



ll rec(int l, int r){
	if (l>r) return -1;
	if (l == r) return a[l];
	int mi = query(l, r);
	return max(rec(l, mi - 1), max(rec(mi + 1, r), 1LL * (r - l + 1)*a[mi]));
}

int main(){
    freopen("uva.txt","rt",stdin);
	while (scanf("%d", &n)){
		if (!n) break; 
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		build();
		printf("%lld\n", rec(1, n));
	}
}
