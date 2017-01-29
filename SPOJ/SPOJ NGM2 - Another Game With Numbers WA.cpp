#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;


typedef long long ll;
ll x[20];
ll tx[20], tk;
ll n, k, not_cancelled;

void rec(int idx,ll sum,int cnt){
	if (sum > n)
		return ;
	if (idx == k) {
		if (cnt && cnt % 2 == 0)
			not_cancelled += n/sum;
		else if (cnt)
			not_cancelled -= n/sum;
		return;
	}
	rec(idx + 1, sum*x[idx], cnt + 1);
	rec(idx + 1, sum, cnt);
	return;
}

int main(){
    freopen("uva.txt","rt",stdin);
	scanf("%lld%lld", &n, &tk);
	for (int i = 0; i < tk; i++)
		scanf("%lld", tx + i);
	k = 0;
	sort(tx, tx + tk);
	for (int i = 0; i < tk; i++) {
		bool isMultiple = 0;
		for (int j = 0; j < k; j++)
			if (tx[i] % x[j] == 0)
				isMultiple = 1;
		if (isMultiple == false)
			x[k++] = tx[i];
	}
	not_cancelled = n;
	printf("%lld \n", not_cancelled);
	for (int i = 0; i < k; i++)
		printf(" %d ", x[i]);
	puts("");
	rec(0, 1, 0);
	printf("%lld\n", not_cancelled);
}
