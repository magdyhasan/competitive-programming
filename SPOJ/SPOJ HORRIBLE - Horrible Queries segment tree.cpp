#include<bits/stdc++.h>
using namespace std;



typedef long long ll;

const int maxn = 300500;

int n;
ll segT[maxn * 4], lazy[maxn * 4];

void push(int idx, int l, int r){
	if (lazy[idx]){
		segT[idx] += lazy[idx] * ll(r - l + 1);
		if (l != r){
			lazy[idx << 1] += lazy[idx];
			lazy[(idx << 1) | 1] += lazy[idx];
		}
		lazy[idx] = 0;
	}
}

void updateSeg(int x, int y, int v, int idx = 1, int l = 0, int r = n - 1){
	push(idx, l, r);
	if (x > r || y < l) return;
	if (x <= l && y >= r){
		lazy[idx] += v;
		push(idx, l, r);
		return;
	}
	int mid = (l + r) >> 1;
	updateSeg(x, y, v, idx << 1, l, mid);
	updateSeg(x, y, v, (idx << 1) | 1, mid + 1, r);
	segT[idx] = segT[idx << 1] + segT[(idx << 1) | 1];
}

ll querySeg(int x, int y, int idx = 1, int l = 0, int r = n - 1){
	if (x > r || y < l) return 0;
	push(idx, l, r);
	if (x <= l && y >= r) return segT[idx];
	int mid = (l + r) >> 1;
	return querySeg(x, y, idx << 1, l, mid) + querySeg(x, y, (idx << 1) | 1, mid + 1, r);
}


int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	while (T--){
		int q; scanf("%d%d", &n, &q);
		memset(segT, 0, sizeof(segT));
		memset(lazy, 0, sizeof(lazy));
		int ty, l, r; 
		while (q--){
			scanf("%d%d%d", &ty, &l, &r);
			l--; r--;
			if (ty == 0) {
				int v; scanf("%d", &v);
				updateSeg(l, r, v);
			}
			else
				printf("%lld\n", querySeg(l, r));
		}
	}
}
