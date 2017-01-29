#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;

typedef long long ll;

ll _left[20], _right[20], l, r;
ll sub_left[(1 << 20)], sub_right[(1 << 20)];

int N, A, B;

int main(){
	scanf("%d%d%d", &N, &A, &B);
	int left_n = N / 2, right_n = N - left_n; // divide interval into 2 halfs
	for (int i = 0; i < left_n; i++) // read the first half
		scanf("%lld", _left + i);
	for (int i = 0; i < right_n; i++) // read the second half
		scanf("%lld", _right + i);
	for (int i = 0; i < (1 << left_n); i++) { // create all subsets from first half
		ll sum = 0;
		for (int j = 0; j < left_n; j++)
			if (i & (1 << j))
				sum += _left[j];
		sub_left[l++] = sum;
	}
	for (int i = 0; i < (1 << right_n); i++) { // create all subsets from second half
		ll sum = 0;
		for (int j = 0; j < right_n; j++)
			if (i & (1 << j))
				sum += _right[j];
		sub_right[r++] = sum;
	}
	ll ans = 0;
	sort(sub_right, sub_right + r); // sort the right subsets
	for (int i = 0; i < l; i++) // find matched element from right that make left subset + right subset between A and B
		ans += upper_bound(sub_right, sub_right + r, B - sub_left[i]) - lower_bound(sub_right, sub_right + r, A - sub_left[i]);
	printf("%lld", ans);
}
