#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

const int maxn = 200500;

int n;
ll segT[maxn * 4], lazy[maxn * 4];
int a[maxn];

void updateSeg(int x, int y, int v, int idx = 1, int l = 0, int r = n - 1){
	if (lazy[idx]){
		segT[idx] += lazy[idx];
		if (l != r){
			lazy[idx << 1] += lazy[idx];
			lazy[(idx << 1) | 1] += lazy[idx];
		}
		lazy[idx] = 0;
	}
	if (x > r || y < l) return;
	if (x <= l && y >= r){
		segT[idx] += v;
		if (l != r){
			lazy[idx << 1] += v;
			lazy[(idx << 1) | 1] += v;
		}
		return;
	}
	int mid = (l + r) >> 1;
	updateSeg(x, y, v, idx << 1, l, mid);
	updateSeg(x, y, v, (idx << 1) | 1, mid + 1, r);
	segT[idx] = min(segT[idx << 1], segT[(idx << 1) | 1]);
}

ll querySeg(int x, int y, int idx = 1, int l = 0, int r = n - 1){
	if (x > r || y < l) return 9223372036854775807LL;
	if (lazy[idx]){
		segT[idx] += lazy[idx];
		if (l != r){
			lazy[idx << 1] += lazy[idx];
			lazy[(idx << 1) | 1] += lazy[idx];
		}
		lazy[idx] = 0;
	}
	if (x <= l && y >= r) return segT[idx];
	int mid = (l + r) >> 1;
	return min(querySeg(x, y, idx << 1, l, mid), querySeg(x, y, (idx << 1) | 1, mid + 1, r));
}

void build(int idx = 1, int l = 0, int r = n - 1){
	if (l == r){
		segT[idx] = a[l];
		return;
	}
	int mid = (r + l) >> 1, lidx = idx << 1;
	build(lidx, l, mid);
	build(lidx + 1, mid + 1, r);
	segT[idx] = min(segT[lidx], segT[lidx + 1]);
}


char li[maxn];

int main(){
	freopen("uva.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	build();
	int q, l, r, v; scanf("%d", &q);
	gets(li);
	while (q--){
		gets(li);
		if (sscanf(li, "%d%d%d", &l, &r, &v) == 3) {
			if (r < l) updateSeg(l, n - 1, v), updateSeg(0, r, v);
			else updateSeg(l, r, v);
		}
		else {
			ll mi;
			if (r < l) mi = min(querySeg(l, n - 1), querySeg(0, r));
			else mi = querySeg(l, r);
			printf("%lld\n", mi);
		}
	}
}