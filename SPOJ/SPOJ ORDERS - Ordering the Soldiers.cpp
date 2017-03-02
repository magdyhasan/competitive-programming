#include<stdlib.h>
#include<stdio.h>
#include<cstring>
using namespace std;

const int maxn = 200500;

int segT[maxn * 4], ql[maxn], ra[maxn];
int n;

int query(int v, int idx = 1, int l = 1, int r = n){
	if (l == r) return l;
	int mid = (l + r) >> 1;
	if(v <= segT[idx<<1]) return query(v, idx << 1, l, mid);
	else return query(v - segT[idx << 1], idx << 1 | 1, mid + 1, r);
}

void updateSeg(int x, int v, int idx = 1, int l = 1, int r = n){
	if (l == r){
		segT[idx] += v;
		return;
	}
	int mid = (l + r) >> 1;
	if (x <= mid) updateSeg(x, v, idx << 1, l, mid);
	else updateSeg(x, v, idx << 1 | 1, mid + 1, r);
	segT[idx] = segT[idx << 1] + segT[idx << 1 | 1];
}

int main(){
    freopen("uva.txt","rt",stdin);
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d", &n);
		for (int i = 0; i <= 4*n; i++) segT[i] = 0;
		for (int i = 1; i <= n; i++) updateSeg(i, 1);
		for (int i = 1; i <= n; i++) scanf("%d", ql + i);
		for (int i = n; i > 0; i--){
			ra[i] = query(i - ql[i]);
			updateSeg(ra[i], -1);
		}
		for (int i = 1; i <= n; i++) printf("%d%s", ra[i], (i == n) ? "\n" : " ");
	}
}
