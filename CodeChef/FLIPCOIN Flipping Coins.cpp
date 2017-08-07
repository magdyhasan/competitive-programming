#include<bits/stdc++.h>
using namespace std;

const int maxn = 300500;



int n;
int segT[maxn * 4], lazy[maxn * 4];
int a[maxn];

void push(int idx, int l, int r){
	if (lazy[idx]){
		segT[idx] = (r - l + 1) - segT[idx];
		if (l != r){
			if(lazy[idx << 1]) lazy[idx << 1] = 0;
			else lazy[idx << 1] = 1;
			if (lazy[(idx << 1) | 1]) lazy[(idx << 1) | 1] = 0;
			else lazy[(idx << 1) | 1] = 1;
		}
		lazy[idx] = 0;
	}
}

void updateSeg(int x, int y, int idx = 1, int l = 0, int r = n - 1){
	push(idx, l, r);
	if (x > r || y < l) return;
	if (x <= l && y >= r){
		lazy[idx] = 1;
		push(idx, l, r);
		return;
	}
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	updateSeg(x, y, lidx, l, mid);
	updateSeg(x, y, ridx, mid + 1, r);
	segT[idx] = segT[lidx] + segT[ridx];
}

int querySeg(int x, int y, int idx = 1, int l = 0, int r = n - 1){
	if (x > r || y < l) return 0;
	push(idx, l, r);
	if (x <= l && y >= r) return segT[idx];
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	return querySeg(x, y, lidx, l, mid) + querySeg(x, y, ridx, mid + 1, r);
}

void build(int idx = 1, int l = 0, int r = n - 1){
	if (l == r){
		segT[idx] = a[l];
		return;
	}
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	build(lidx, l, mid);
	build(ridx, mid + 1, r);
	segT[idx] = segT[lidx] + segT[ridx];
}

int main(){
	freopen("uva.txt", "r", stdin);
	int q; scanf("%d%d", &n, &q);
	int l, r, ty;
	while (q--){
		scanf("%d%d%d", &ty, &l, &r);
		if (ty == 1) printf("%d\n", querySeg(l, r));
		else updateSeg(l, r);
	}
}