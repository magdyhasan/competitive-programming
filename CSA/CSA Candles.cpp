/*
	greedy part: we will use bigger candles first

	now we want operation to decrase range that has maximum heights

	but if we decrase the range, we might make array unsorted, then after that we can't decrase whole range again

	we need to keep array sorted

	notice that we are decrasing range with -1, so the only value that can make array unsrted is last element on the block
	e.g [6 5 4 3 3 1] if we decrases [1,4] then we have [6 5 4 2 3 1]
	what we can do is find last element we decrase ( here is 3 ) and instead of removing from right to left
	remove 3's from left to right, so we have [6 5 4 3 2 1 ]

	now all this operations is doable with segment tree
	or BIT
*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 300500;

struct node{
	int mx, lzy;
} tr[maxn * 4];

int n;
int H[maxn], C[maxn];

void push(int idx){
	if (tr[idx].lzy){
		int lidx = idx << 1, ridx = lidx | 1;
		tr[lidx].lzy += tr[idx].lzy;
		tr[lidx].mx += tr[idx].lzy;
		tr[ridx].lzy += tr[idx].lzy;
		tr[ridx].mx += tr[idx].lzy;
		tr[idx].lzy = 0;
	}
}

void build(int idx = 1, int l = 1, int r = n){
	if (l == r){
		tr[idx].lzy = 0;
		tr[idx].mx = H[l];
		return;
	}
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	build(lidx, l, mid);
	build(ridx, mid + 1, r);
	tr[idx].mx = max(tr[lidx].mx, tr[ridx].mx);
}

int getKthElm(int k, int idx = 1, int l = 1, int r = n){
	if (l == r) return tr[idx].mx;
	push(idx);
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	if (k <= mid) return getKthElm(k, lidx, l, mid);
	return getKthElm(k, ridx, mid + 1, r);
}

int getLastOcc(int x, int idx = 1, int l = 1, int r = n){
	if (tr[idx].mx < x) return 0;
	if (l == r) return l;
	push(idx);
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	if (tr[ridx].mx < x) return getLastOcc(x, lidx, l, mid);
	return getLastOcc(x, ridx, mid + 1, r);
}

void updateRange(int x, int y, int v, int idx = 1, int l = 1, int r = n){
	if (x <= l && y >= r){
		tr[idx].lzy += v;
		tr[idx].mx += v;
		return;
	}
	if (x > r || y < l) return;
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	updateRange(x, y, v, lidx, l, mid);
	updateRange(x, y, v, ridx, mid + 1, r);
	push(idx);
	tr[idx].mx = max(tr[lidx].mx, tr[ridx].mx);
}

int main(){
	int m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", H + i + 1);
	for (int i = 0; i < m; i++) scanf("%d", C + i);
	sort(H + 1, H + n + 1);
	reverse(H + 1, H + n + 1);
	// build the tree of heights of candles in non-increasing order
	build();
	for (int i = 0; i < m; i++){
		int v;

		if (C[i]>n) v = 0;
		else v = getKthElm(C[i]); // find last one we will be lighting
		if (v == 0){// if this zero, then we don't have enough candles
			printf("%d\n", i);
			return 0;
		}
		int l = getLastOcc(v + 1), r = getLastOcc(v);// find last occurance of last candle we'll use and last occurance of the one before
		updateRange(1, l, -1);// decrase hieght of all candles that bigger than last candle we will use
		updateRange(r - (C[i] - l) + 1, r, -1);//decrase height of the rightmost last candles we will use to keep array sorted
	}
	printf("%d\n", m);
}