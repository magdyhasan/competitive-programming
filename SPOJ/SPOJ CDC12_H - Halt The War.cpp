#include<stdlib.h>
#include<stdio.h>
#include<cstring>
using namespace std;


typedef long long ll;

int n;
ll segT[100500 * 4], lazy[100500 * 4];

void updateSeg(int x, int y, int idx = 1, int l = 0, int r = n - 1){
	if (lazy[idx]){
		segT[idx] += (r - l + 1)*lazy[idx];
		if (l != r){
			lazy[idx << 1] += lazy[idx];
			lazy[(idx << 1) | 1] += lazy[idx];
		}
		lazy[idx] = 0;
	}
	if (x > r || y < l) return;
	if (x <= l && y >= r){
		segT[idx] += (r - l + 1);
		if (l != r){
			lazy[idx << 1] ++;
			lazy[(idx << 1) | 1] ++;
		}
		return;
	}
	int mid = (l + r) >> 1;
	updateSeg(x, y, idx << 1, l, mid);
	updateSeg(x, y, (idx << 1) | 1, mid + 1, r);
	segT[idx] = segT[idx << 1] + segT[(idx << 1) | 1];
}

ll querySeg(int x, int y, int idx = 1, int l = 0, int r = n - 1){
	if (x > r || y < l) return 0LL;
	if (lazy[idx]){
		segT[idx] += (r - l + 1)*lazy[idx];
		if (l != r){
			lazy[idx << 1] += lazy[idx];
			lazy[(idx << 1) | 1] += lazy[idx];
		}
		lazy[idx] = 0;
	}
	if (x <= l && y >= r) return segT[idx];
	int mid = (l + r) >> 1;
	return querySeg(x, y, idx << 1, l, mid) +
	querySeg(x, y, (idx << 1) | 1, mid + 1, r);
}

int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	char ty[100];
	for (int t = 1; t <= T; t++){
		memset(lazy, 0, sizeof(lazy));
		memset(segT, 0, sizeof(segT));
		printf("Scenario #%d:\n", t);
		int q, l, r;
		scanf("%d%d", &n, &q);
		while (q--){
			scanf("%s%d%d", ty, &l, &r);
			if (ty[0] == 'a')
				printf("%lld\n", querySeg(l - 1, r - 1));
			else
				updateSeg(l - 1, r - 1), puts("OK");
		}
	}
}
