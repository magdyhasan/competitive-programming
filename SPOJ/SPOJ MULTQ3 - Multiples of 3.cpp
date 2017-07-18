#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

const int maxn = 200500;

int n;
ll segT[maxn * 4][3], lazy[maxn * 4];
int a[maxn];

void updateSeg(int x, int y,int idx = 1, int l = 0, int r = n - 1){
	if (lazy[idx]){
		int t[3];
		for (int j = 0; j < 3; j++) t[j] = segT[idx][j];
		segT[idx][0] = segT[idx][1] = segT[idx][2] = 0;
		for (int j = 0; j < 3; j++) segT[idx][(j + lazy[idx]) % 3] += t[j];
		if (l != r){
			lazy[idx << 1] += lazy[idx];
			lazy[(idx << 1) | 1] += lazy[idx];
		}
		lazy[idx] = 0;
	}
	if (x > r || y < l) return;
	if (x <= l && y >= r){
		int t[3];
		for (int j = 0; j < 3; j++) t[j] = segT[idx][j];
		segT[idx][0] = segT[idx][1] = segT[idx][2] = 0;
		for (int j = 0; j < 3; j++) segT[idx][(j + 1) % 3] += t[j];
		if (l != r){
			lazy[idx << 1] ++;
			lazy[(idx << 1) | 1] ++;
		}
		return;
	}
	int mid = (l + r) >> 1;
	updateSeg(x, y, idx << 1, l, mid);
	updateSeg(x, y, (idx << 1) | 1, mid + 1, r);
	for (int j = 0; j<3;j++)
		segT[idx][j] = segT[idx << 1][j] + segT[(idx << 1) | 1][j];
}

ll querySeg(int x, int y, int idx = 1, int l = 0, int r = n - 1){
	if (x > r || y < l) return 0;
	if (lazy[idx]){
		int t[3];
		for (int j = 0; j < 3; j++) t[j] = segT[idx][j];
		segT[idx][0] = segT[idx][1] = segT[idx][2] = 0;
		for (int j = 0; j < 3; j++) segT[idx][(j + lazy[idx]) % 3] += t[j];
		if (l != r){
			lazy[idx << 1] += lazy[idx];
			lazy[(idx << 1) | 1] += lazy[idx];
		}
		lazy[idx] = 0;
	}
	if (x <= l && y >= r) return segT[idx][0];
	int mid = (l + r) >> 1;
	return querySeg(x, y, idx << 1, l, mid) + querySeg(x, y, (idx << 1) | 1, mid + 1, r);
}

void build(int idx = 1, int l = 0, int r = n - 1){
	if (l == r){
		segT[idx][0] = 1;
		return;
	}
	int mid = (r + l) >> 1, lidx = idx << 1;
	build(lidx, l, mid);
	build(lidx + 1, mid + 1, r);
	for (int j = 0; j<3; j++)
		segT[idx][j] = segT[idx << 1][j] + segT[(idx << 1) | 1][j];
}

int main(){
    freopen("uva.txt","rt",stdin);
	int q;
	scanf("%d%d", &n, &q);
	build();
	while (q--){
		int ty, l, r;
		scanf("%d%d%d", &ty, &l, &r);
		if (ty == 0) updateSeg(l, r);
		else printf("%lld\n", querySeg(l, r));
	}
}
