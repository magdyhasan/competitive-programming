#include<stdlib.h>
#include<stdio.h>
#include<unordered_map>
#include<algorithm>
using namespace std;


int have_r[16000010], have_l[16000010], have_cnt;
int A[4005], B[4005], C[4005], D[4005];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d%d%d", &A[i], &B[i], &C[i], &D[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			have_r[have_cnt] = C[i] + D[j], have_l[have_cnt++] = A[i] + B[j]; // sum the 2 first columns in have_l and last 2 in have_r
	sort(have_l, have_l + have_cnt);
	sort(have_r, have_r + have_cnt);
	long long ans = 0;
	for (int i = 0; i < have_cnt; ) {
		int j = i;
		while (i < have_cnt && have_r[i] == have_r[j]) i++; // find all repeated value of i ( this optimization to fit in time )
		int repeated = i - j;
		int u = upper_bound(have_l, have_l + have_cnt, -1*have_r[j]) - have_l; // binary search to find if there's a sum in the last 2 columns to make the sum == 0
		int l = lower_bound(have_l, have_l + have_cnt, -1*have_r[j]) - have_l;
		ans += (u - l)*repeated;  // we have all the possible range of (u-l) * repeated range of i
	}
	printf("%lld\n", ans);
}
