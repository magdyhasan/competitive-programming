#include<stdlib.h>
#include<stdio.h>
#include<cstring>
using namespace std;

int segT[6 * 100500], lazy[6*100500];

void update(int x, int y, int v, int idx = 1, int l = 1, int r = 100500){
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
	update(x, y, v, idx << 1, l, mid);
	update(x, y, v, (idx << 1) | 1, mid + 1, r);
	segT[idx] = segT[idx << 1] + segT[(idx << 1) | 1];
}

int query(int x,int idx = 1, int l = 1, int r = 100500){
	if (x > r || x < l) return 0;
	if (lazy[idx]){
		segT[idx] += lazy[idx];
		if (l != r){
			lazy[idx << 1] += lazy[idx];
			lazy[(idx << 1) | 1] += lazy[idx];
		}
		lazy[idx] = 0;
	}
	if (x <= l && x >= r) return segT[idx];
	int mid = (l + r) >> 1;
	return query(x, idx << 1, l, mid) +
		query(x, (idx << 1) | 1, mid + 1, r);
}

int main(){
    freopen("uva.txt","rt",stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		int l, r;
		scanf("%d%d", &l, &r);
		int ql = query(l), qr = query(r);
		printf("%d\n", ql + qr);
		update(l ,l,-ql);
		update(r, r, -qr);
		update(l + 1, r - 1, 1);
	}
}
