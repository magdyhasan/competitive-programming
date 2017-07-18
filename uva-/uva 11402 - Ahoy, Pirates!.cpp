#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

const int maxn = 1524000;

int n;
int segT[maxn * 4], lazy[maxn * 4];
int a[maxn];

int flip(int x){
	if (x == 0) return 1;
	if (x == 1) return 0;
	if (x == 2) return -1;
	return 2;
}

void push(int idx, int l, int r){
	int mid = (l + r) / 2, lidx = idx << 1, ridx = lidx | 1;
	if (lazy[idx] == 0){ // F: all to 1
		segT[idx] = (r - l + 1);
		if (l != r){
			lazy[lidx] = lazy[ridx] = 0;
		}
		lazy[idx] = -1;
	}
	if (lazy[idx] == 1){// E: all to 0
		segT[idx] = 0;
		if (l != r){
			lazy[lidx] = lazy[ridx] = 1;
		}
		lazy[idx] = -1;
	}
	if (lazy[idx]  == 2){
		segT[idx] = (r - l + 1) - segT[idx];
		if (l != r){
			lazy[lidx] = flip(lazy[lidx]);
			lazy[ridx] = flip(lazy[ridx]);
		}
		lazy[idx] = -1;
	}
}

void updateSeg(int x, int y, int v, int idx = 1, int l = 0, int r = n - 1){
	if(lazy[idx] != -1) push(idx, l, r);
	if (x > r || y < l) return;
	if (x <= l && y >= r){
		lazy[idx]= v;
		push(idx, l, r);
		return;
	}
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	updateSeg(x, y, v, idx << 1, l, mid);
	updateSeg(x, y, v, (idx << 1) | 1, mid + 1, r);
	segT[idx] = segT[lidx] + segT[ridx];
}

int querySeg(int x, int y, int idx = 1, int l = 0, int r = n - 1){
	if (x > r || y < l) return 0;
	if (lazy[idx] != -1) push(idx, l, r);
	if (x <= l && y >= r) return segT[idx];
	int mid = (l + r) >> 1;
	return querySeg(x, y, idx << 1, l, mid) + querySeg(x, y, (idx << 1) | 1, mid + 1, r);
}

void build(int idx = 1, int l = 0, int r = n - 1){
	lazy[idx] = -1;
	if (l == r){
		segT[idx] = a[l];
		return;
	}
	int mid = (r + l) >> 1, lidx = idx << 1, ridx = lidx | 1;
	build(lidx, l, mid);
	build(ridx, mid + 1, r);
	segT[idx] = segT[lidx] + segT[ridx];
}

char st[105];

int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++){
		int m;  scanf("%d", &m);
		n = 0;
		for (int i = 0; i < m; i++){
			int tt; scanf("%d%s", &tt, st);
			while (tt--){
				for (int j = 0; st[j]; j++) a[n++] = (st[j] - '0');
			}
		}
		build();
		printf("Case %d:\n", tc);
		int q, qn = 0, l, r; scanf("%d", &q);
		char ch[2];
		while (q--){
			scanf("%s%d%d", ch, &l, &r);
			if (ch[0] == 'F') updateSeg(l, r, 0);
			if (ch[0] == 'E') updateSeg(l, r, 1);
			if (ch[0] == 'I') updateSeg(l, r, 2);
			if (ch[0] == 'S') printf("Q%d: %d\n", ++qn, querySeg(l, r));
		}
	}
}
