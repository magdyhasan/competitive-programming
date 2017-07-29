#include<bits/stdc++.h>
using namespace std;

const int maxn = 300500;

int segT[maxn*4];

int n;
int a[maxn];

int query(int x, int y, int idx = 1, int l = 0, int r = n - 1){
	if (x > r || y < l) return (1 << 31) - 1;
	if (x <= l && y >= r) return segT[idx]; 
	int mid = (l + r) / 2, lidx = idx << 1, ridx = lidx | 1;
	return query(x, y, lidx, l, mid)&query(x, y, ridx, mid + 1, r);
}

void build(int idx = 1, int l = 0, int r = n - 1){
	if (l == r){
		segT[idx] = a[l];
		return;
	}
	int mid = (l + r) / 2, lidx = idx << 1, ridx = lidx | 1;
	build(lidx, l, mid);
	build(ridx, mid + 1, r);
	segT[idx] = segT[lidx] & segT[ridx];
}



int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	while (T--){
		int k; scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++) scanf("%d", a + i);
		build();
		int ret;
		for (int i = 0; i < n; i++){
			if (i - k < 0) ret = query(0, i)&query(max(i, n + (i - k)), n - 1);
			else ret = query(i - k, i);
			if (i + k >= n) ret = ret & query(i, n - 1) & query(0, min(i, (i + k) - n));
			else ret = ret&query(i, i + k);
			printf("%d ", ret);
		}	
		puts("");
	}
}
