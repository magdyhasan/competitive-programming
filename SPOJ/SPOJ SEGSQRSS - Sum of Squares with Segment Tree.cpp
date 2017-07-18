#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

const int maxn = 200500;

int n;
ll segT[maxn * 4][2];// segT[idx][0]: sum, segT[idx][1]: sum of sqr's
ll lazy[maxn * 4][2];
int a[maxn];

void push(int idx, int l, int r){
	if (lazy[idx][0]){// first update, add x to all numebers in range
		segT[idx][1] += ll(r - l + 1)*ll(lazy[idx][0] * lazy[idx][0]) + 2LL * lazy[idx][0] * segT[idx][0];
		segT[idx][0] += lazy[idx][0] * ll(r - l + 1);
		if (l != r){
			lazy[idx << 1][0] += lazy[idx][0];
			lazy[(idx << 1) | 1][0] += lazy[idx][0];
		}
		lazy[idx][0] = 0;
	}
	if (lazy[idx][1]){//second update, set all numbers in range to x
		segT[idx][1] = ll(r - l + 1)*ll(lazy[idx][1] * lazy[idx][1]);
		segT[idx][0] = lazy[idx][1] * ll(r - l + 1);
		if (l != r){
			lazy[idx << 1][1] += lazy[idx][1];
			lazy[(idx << 1) | 1][1] += lazy[idx][1];
		}
		lazy[idx][1] = 0;
	}
}

void updateSeg(int x, int y, int v, int idx = 1, int l = 0, int r = n - 1){
	push(idx, l, r);
	if (x > r || y < l) return;
	if (x <= l && y >= r){
		lazy[idx][0] += v;
		push(idx, l, r);
		return;
	}
	int mid = (l + r) >> 1;
	updateSeg(x, y, v, idx << 1, l, mid);
	updateSeg(x, y, v, (idx << 1) | 1, mid + 1, r);
	segT[idx][0] = segT[idx << 1][0] + segT[(idx << 1) | 1][0];
	segT[idx][1] = segT[idx << 1][1] + segT[(idx << 1) | 1][1];
}


void setSeg(int x, int y, int v, int idx = 1, int l = 0, int r = n - 1){
	push(idx, l, r);
	if (x > r || y < l) return;
	if (x <= l && y >= r){
		lazy[idx][1] += v;
		push(idx, l, r);
		return;
	}
	int mid = (l + r) >> 1;
	setSeg(x, y, v, idx << 1, l, mid);
	setSeg(x, y, v, (idx << 1) | 1, mid + 1, r);
	segT[idx][0] = segT[idx << 1][0] + segT[(idx << 1) | 1][0];
	segT[idx][1] = segT[idx << 1][1] + segT[(idx << 1) | 1][1];
}

ll querySeg(int x, int y, int idx = 1, int l = 0, int r = n - 1){
	if (x > r || y < l) return 0LL;
	push(idx, l, r);
	if (x <= l && y >= r) return segT[idx][1];
	int mid = (l + r) >> 1;
	return querySeg(x, y, idx << 1, l, mid) + querySeg(x, y, (idx << 1) | 1, mid + 1, r);
}

void build(int idx = 1, int l = 0, int r = n - 1){
	if (l == r){
		segT[idx][0] = a[l];
		segT[idx][1] = a[l] * a[l];
		return;
	}
	int mid = (r + l) >> 1, lidx = idx << 1;
	build(lidx, l, mid);
	build(lidx + 1, mid + 1, r);
	segT[idx][0] = segT[idx << 1][0] + segT[(idx << 1) | 1][0];
	segT[idx][1] = segT[idx << 1][1] + segT[(idx << 1) | 1][1];
}

int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++){
		memset(segT, 0, sizeof(segT));
		memset(lazy, 0, sizeof(lazy));
		int q; scanf("%d%d", &n, &q);
		for (int i = 0; i < n; i++) scanf("%d", a + i);
		build();
		printf("Case %d:\n", tc);
		int ty, l, r, v;
		while (q--){
			scanf("%d%d%d", &ty, &l, &r); l--; r--;
			if (ty == 2) printf("%lld\n", querySeg(l, r));
			else {
				scanf("%d", &v);
				if (ty == 1) updateSeg(l, r, v);
				else setSeg(l, r, v);
			}
		}
	}
}
