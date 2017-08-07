#include<bits/stdc++.h>
using namespace std;


//standard implementation for rmq
const int maxn = 300500;

int segT[maxn * 8], a[maxn];
int n;

int query(int x, int y, int idx = 1, int l = 1, int r = n){
	if (r < x || l > y) return -12345678;
	if (x <= l && r <= y) return segT[idx];
	int mid = (l + r) / 2, lidx = idx << 1;
	return max(query(x, y, lidx, l, mid), query(x, y, lidx | 1, mid + 1, r));
}

void build(int idx = 1, int l = 1, int r = n){
	if (l == r){
		segT[idx] = a[l];
		return;
	}
	int mid = (l + r) / 2, lidx = idx << 1, ridx = lidx | 1;
	build(lidx, l, mid);
	build(ridx, mid + 1, r);
	segT[idx] = max(segT[lidx], segT[ridx]);
}

int main(){
    freopen("uva.txt","rt",stdin);
	int m;
	while (scanf("%d%d", &n, &m) == 2){
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		build();
		int l, r, ret = 0;
		while (m--){
			scanf("%d%d", &l, &r); 
			if (l > r) swap(l, r);
			if (r - l < 2 || query(l + 1, r - 1) <= a[l])
				ret++;
		}
		printf("%d\n", ret);
	}
}
