#include<bits/stdc++.h>
using namespace std;

const int maxn = 800500;

typedef long long ll;

ll bit[maxn * 4];
ll val[maxn], cnt[maxn];

void update(ll T[], int idx, ll val){
	for (; idx<maxn; idx |= (idx + 1))
		T[idx] += val;
}


ll query(ll T[], int idx){
	ll sum = 0;
	for (; idx >= 0; idx = (idx & (idx + 1)) - 1) sum += T[idx];
	return sum;
}

int a[maxn];

int main(){
	freopen("uva.txt", "r", stdin);
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	ll ret = 0;
	for (int i = n; i > 0; i--){
		ret += a[i] * query(cnt, a[i]) + query(val, a[i]);
		update(val, a[i], a[i]);
		update(cnt, a[i], 1);
	}
	printf("%lld\n", ret);
}