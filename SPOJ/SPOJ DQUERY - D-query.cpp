#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 30000 + 5;



vector<int> q[N];
int a[N], last[(int)1e6 + 100];

int n, tre[N * 4], l[200500], r[200500], ans[200500];

void update(int x, int idx = 1, int l = 1, int r = n){
	if (l == r) {
		tre[idx] ^= 1;
		return;
	}
	int mid = (l + r) >> 1;
	if (x <= mid)
		update(x, idx << 1, l, mid);
	else
		update(x, (idx << 1) + 1, mid + 1, r);
	tre[idx] = tre[idx << 1] + tre[(idx << 1) + 1];
}

int query(int x, int y, int idx = 1, int l = 1, int r = n){
	if (x > r || y < l)
		return 0;
	if (x <= l && y >= r)
		return tre[idx];
	int mid = (l + r) >> 1;
	return query(x, y, idx << 1, l, mid) + query(x, y, (idx << 1) + 1, mid + 1, r);
}

int main(){
    freopen("uva.txt","rt",stdin);
	scanf("%d", &n);
	int i, m;
	for (i = 0; i < n; i++)
		scanf("%d", a + i + 1);
	scanf("%d", &m);
	for (i = 0; i < m; i++)
		scanf("%d%d", l + i, r + i), q[r[i]].push_back(i);
	for (i = 1; i <= n; i++) {
		if (last[a[i]])
			update(last[a[i]]);
		last[a[i]] = i;
		update(i);
		for (int k : q[i])
			ans[k] = query(l[k], r[k]);
	}
	for (i = 0; i < m; i++)
		printf("%d\n", ans[i]);
}
