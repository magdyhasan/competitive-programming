#include<bits/stdc++.h>
using namespace std;

const int maxn = 300500;

int bit[maxn * 8];


void update(int idx, int val){
	for (int x = idx; x < maxn; x = (x | (x + 1)))
		bit[x] += val;
}

int query(int idx){
	int ret = 0;
	for (int x = idx; x >= 0; x = ((x&(x + 1)) - 1))
		ret += bit[x];
	return ret;
}

int queryR(int l, int r){
	if (l <= 1) return query(r);
	return query(r) - query(l - 1);
}


int main(){
	freopen("uva.txt", "r", stdin);
	int T; scanf("%d", &T);
	while (T--){
		int n, m; scanf("%d%d", &n, &m);
		memset(bit, 0, sizeof(bit));
		for (int i = 1; i <= n; i++) update(i, 1);
		int ty, l, r;
		while (m--){
			scanf("%d%d", &ty, &l);
			if (ty == 0){
				if (queryR(l,l) == 1)	update(l, -1);
				else update(l, 1);
			}
			else{
				scanf("%d", &r);
				if (l > r) swap(l, r);
				if (queryR(l, r - 1) == r - l || (query(l - 1) + 1 == l && queryR(r, n) == n - r + 1))
					puts("1");
				else puts("0");
			}
		}
	}
}