#include<stdio.h>
#include<algorithm>
#include<limits>
#include<stack>
using namespace std;

const int maxn = 50500;

typedef long long ll;


int segT[maxn * 8][2];

int a[maxn];

typedef pair<int, int> pii;


int n;

pii query(int x, int y, int idx = 1, int l = 0, int r = n - 1){
	if (r < x || l > y) return make_pair( 123456789, -12345678 );
	if (x <= l && r <= y) return make_pair( segT[idx][0], segT[idx][1] );
	int mid = (l + r) / 2, lidx = idx << 1;
	pii lq = query(x, y, lidx, l, mid), rq = query(x, y, lidx | 1, mid + 1, r);
	return make_pair( min(lq.first, rq.first), max(lq.second, rq.second) );
}


void build(int idx = 1, int l = 0, int r = n - 1){
	if (l == r){
		segT[idx][0] = segT[idx][1] = a[l];
		return;
	}
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	build(lidx, l, mid);
	build(ridx, mid + 1, r);
	segT[idx][0] = min(segT[lidx][0], segT[ridx][0]);
	segT[idx][1] = max(segT[lidx][1], segT[ridx][1]);
}


bool can(int r){
	for (int i = r-1; i < n; i++){
		if (a[i] > a[i - r + 1]){
			if (r == 2) return 1;
			pii qu = query(i - r + 2, i - 1);
			if (qu.first > a[i - r + 1] && qu.second < a[i])
				return 1;
		}
	}
	return 0;
}


int main(){
	freopen("uva.txt", "r", stdin);
	while (scanf("%d", &n) != EOF){
		for (int i = 0; i < n; i++) scanf("%d", a + i);
		build();
		int l = 2, r = n, ret = 0;
		while (l <= r){
			int mid = (l + r) / 2;
			if (can(mid)) l = mid + 1, ret = mid;
			else r = mid - 1;
		}
		printf("%d\n", ret - 1);
	}
}