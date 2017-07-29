#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000500;

bool notPrime[maxn];
int segT[maxn], lazy[maxn];
int a[maxn];
int n;

void push(int idx, int l, int r){
	if (lazy[idx] != -1){
		segT[idx] = lazy[idx] * (r - l + 1);
		if (l != r){
			lazy[idx << 1] = lazy[idx];
			lazy[(idx << 1) | 1] = lazy[idx];
		}
		lazy[idx] = -1;
	}
}


void update(int x, int y, int v, int idx = 1, int l = 0, int r = n - 1){
	push(idx, l, r);
	if (x > r || y < l) return;
	if (x <= l && y >= r){
		lazy[idx] = v;
		push(idx, l, r);
		return;
	}
	int mid = (l + r) / 2, lidx = idx << 1, ridx = lidx | 1;
	update(x, y, v, lidx, l, mid);
	update(x, y, v, ridx, mid + 1, r);
	segT[idx] = segT[lidx] + segT[ridx];
}


int query(int x, int y, int idx = 1, int l = 0, int r = n - 1){
	if (x > r || y < l) return 0;
	push(idx, l, r);
	if (x <= l && y >= r) return segT[idx];
	int mid = (l + r) / 2, lidx = idx << 1, ridx = lidx | 1;
	return query(x, y, lidx, l, mid) + query(x, y, ridx, mid + 1, r);
}

void build(int idx = 1, int l = 0, int r = n - 1){
	lazy[idx] = -1;
	if (l == r){
		segT[idx] = !notPrime[a[l]];
		return;
	}
	int mid = (l + r) / 2, lidx = idx << 1, ridx = lidx | 1;
	build(lidx, l, mid);
	build(ridx, mid + 1, r);
	segT[idx] = segT[lidx] + segT[ridx];
}

typedef long long ll;

int main(){
    freopen("uva.txt","rt",stdin);
	for (ll i = 2; i < maxn; i++) if(!notPrime[i]){
		for (ll j = i*i; j < maxn; j += i) notPrime[j] = 1;
	}
	int T; scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++){
		printf("Case %d:\n", tc);
		int q; scanf("%d%d", &n, &q);
		for (int i = 0; i < n; i++) scanf("%d", a + i);
		build();
		while (q--){
			int ty, x, y, v;
			scanf("%d%d%d", &ty, &x, &y); x--; y--;
			if (ty == 1) printf("%d\n", query(x, y));
			else{
				scanf("%d", &v);
				update(x, y, !notPrime[v]);
			}
		}
	}
}
