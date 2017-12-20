/*
	problem: find smallest permutation with number of inversions = m

	if we are at position i we need to find number to place such that number of inversion it will make
	with rest of the array and the largest number of inversions we can have from other elements of array
	will be <= m
	we can use BS + BIT to find such element
*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 800500;


int bit[maxn];
int n, m;

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


int main(){
	
	while (scanf("%d%d", &n, &m)){
		if (n == -1) break;
		memset(bit, 0, sizeof(bit));
		for (int i = 1; i <= n; i++) update(i, 1);
		for (int i = 1; i <= n; i++){
			int l = 1, r = n, ans = i, nn = n - i;
			while (l <= r){
				int mid = (l + r) / 2;
				int q = query(mid) - 1;
				if (q >= 0 && query(mid) + (nn*(nn - 1) / 2) - 1 >= m) ans = mid, r = mid - 1;
				else l = mid + 1;
			}
			m -= query(ans) - 1;
			update(ans, -1);
			printf("%d%s", ans, (i == n) ? "\n" : " ");
		}
	}
}

