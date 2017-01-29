#include<stdlib.h>
#include<stdio.h>
#include<cstring>
using namespace std;


int a[10004], n, k;
int segT[53][4 * 100003];
int dp[53][100003];

int queryST(int k, int y, int idx = 1, int l = 0, int r = 100002){
	if (l > r || y < l) return 0;
	if (y >= r) return segT[k][idx];
	int mid = (l + r) >> 1;
	return (queryST(k, y, idx << 1, l, mid) + queryST(k, y, idx << 1 | 1, mid + 1, r)) % 5000000;
}

void updateST(int k, int x, int y, int idx = 1, int l = 0, int r = 100002){
	if (l == r){
		segT[k][idx] += y;
		segT[k][idx] %= 5000000;
		return;
	}
	int mid = (l + r) >> 1;
	if (x <= mid) updateST(k, x, y, idx << 1, l, mid);
	else updateST(k, x, y, idx << 1 | 1, mid + 1, r);
	segT[k][idx] = (segT[k][idx << 1] + segT[k][idx << 1 | 1]) % 5000000;
}


int main(){
	freopen("uva.txt", "rt", stdin);
	scanf("%d%d", &n, &k);
	memset(dp, 0, sizeof(dp));
	memset(segT, 0, sizeof(segT));
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	updateST(1, 0, 1);
	for (int i = 0; i < n; i++)
		for (int e = 1; e <= k; e++){
			dp[e][i] = queryST(e, a[i]);
			updateST(e + 1, a[i] + 1, dp[e][i]);
		}
	int ret = 0;
	for (int i = 0; i < n; i++)
		ret = (dp[k][i] + ret) % 5000000;
	printf("%d\n", ret);
}