/*
	use BIT to find Kth biggst element ( using binary search on BIT )
	use DSU to maintain groups 
*/

#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 300500;
int bit[maxn];
int n;

void update(int idx, int val){
	for (int x = idx; x <= 300000; x += x & -x)
		bit[x] += val;
}

int query(int idx){
	int ret = 0;
	for (int x = idx; x > 0; x -= x & -x)
		ret += bit[x];
	return ret;
}

int solve(int x){
	int l = 0, r = n, s = query(n);
	while (l < r){
		int mid = (l + r) / 2;
		if (query(mid) <= s - x) l = mid + 1;
		else r = mid;
	}
	return l;
}


int p[maxn], cnt[maxn];
int par(int x){
	return (x == p[x]) ? x : p[x] = par(p[x]);
}

int main(){
	freopen("uva.txt", "r", stdin);
	int m; 
	scanf("%d%d", &n, &m);
	update(1, n);
	for (int i = 0; i <= n; i++) p[i] = i, cnt[i] = 1;
	while (m--){
		int ty; scanf("%d", &ty);
		if (ty == 0){
			int u, v; scanf("%d%d", &u, &v);
			u = par(u), v = par(v);
			if (u != v){
				update(cnt[u], -1);
				update(cnt[v], -1);
				update(cnt[u] + cnt[v], 1);
				cnt[u] += cnt[v];
				p[v] = u;
			}
		}else{
			int k; scanf("%d", &k);
		 	printf("%d\n", solve(k));
		}
	}
}