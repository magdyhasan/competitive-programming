#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
	int mi, mx, lazy;
} segT[(1<<18)];

int ans;

void update(int x, int y, int h, int idx = 1, int l = 1, int r = 100000){
	if (l > r) return;
	if (l!=r && segT[idx].lazy) {
		segT[idx << 1].mi = segT[idx << 1].mx = segT[idx << 1].lazy = segT[idx].lazy;
		segT[idx << 1 | 1].mi = segT[idx << 1 | 1].mx = segT[idx << 1 | 1].lazy = segT[idx].lazy;
		segT[idx].lazy = 0;
	}
	if (segT[idx].mi > h) return;
	if (x <= l && y >= r && segT[idx].mx <= h){
		ans += r - l + 1;
		segT[idx].mi = segT[idx].mx = segT[idx].lazy = h;
		return;
	}
	int mid = (l + r) >> 1;
	if (x <= mid) update(x, y, h, idx << 1, l, mid);
	if (y > mid) update(x, y, h, idx << 1 | 1, mid + 1, r);
	segT[idx].mi = min(segT[idx << 1].mi, segT[idx << 1 | 1].mi);
	segT[idx].mx = max(segT[idx << 1].mx, segT[idx << 1 | 1].mx);
}

int main(){
    freopen("uva.txt","rt",stdin);
	int T;	 scanf("%d", &T);
	while (T--){
		int n;	 scanf("%d", &n);
		memset(segT, 0, sizeof(segT));
		ans = 0;
		for (int i = 0; i < n; i++){
			int x, y, h;
			scanf("%d%d%d", &x, &y, &h);
			y--;
			update(x, y, h);
		}
		printf("%d\n", ans);
	}
}
