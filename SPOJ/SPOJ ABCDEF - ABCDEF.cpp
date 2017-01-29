#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;

int have_r[1500000], have_l[1500000], have_r_cnt, have_l_cnt;
int S[105];

int main(){
	int n, i, j, k;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", S + i);
	/*
		(a*b+c)/d - e = f
		(a*b+c)/d = f + e
		a*b+c = ( f + e ) * d
	*/
	for (i = 0; i < n; i++) // preprocess all possible a*b+c
		for (j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				have_l[have_l_cnt++] = (S[i] * S[j]) + S[k];
	for (i = 0; i < n; i++) // preprocess all possible ( f + e ) * d
		for (j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				if(S[k] != 0 )
					have_r[have_r_cnt++] = (S[i] + S[j])*S[k];
	sort(have_l, have_l + have_l_cnt); // sort preprocessed data to do Binary search on them
	sort(have_r, have_r + have_r_cnt);
	long long ans = 0;
	for (i = 0; i < have_l_cnt;){
		j = i;
		while (i < have_l_cnt && have_l[j] == have_l[i]) i++; // find repeated value from have_l
		int repeated = i - j;
		int up = upper_bound(have_r, have_r + have_r_cnt, have_l[j]) - have_r; // find number of have_r values == have_[j]
		int lo = lower_bound(have_r, have_r + have_r_cnt, have_l[j]) - have_r;
		ans += (up - lo)*repeated;
	}
	printf("%lld", ans);
}
