#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 1000009;
typedef long long ll;

ll cnt[maxn], sum[maxn], a[maxn];

void update(ll T[], int idx, ll val){
	if (idx == 0) return;
	for (; idx < maxn; idx += (idx & -idx)) T[idx] += val;
}

ll query(ll T[], int idx){
	ll sum = 0;
	for (; idx>0; idx -= (idx & -idx)) sum += T[idx];
	return sum;
}


int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++){
		memset(cnt, 0, sizeof(cnt));
		memset(sum, 0, sizeof(sum));
		int k, c, n;
		scanf("%d%d%d%d", &k, &c, &n, a);
		ll ret = 0;
		for (int i = 1; i < n; i++) a[i] = (a[i - 1] * ll(k) + ll(c)) % 1000007LL;
		for (int i = 0; i < n; i++) a[i]++;
		for (int i = 0; i < n; i++){
			ll cntL = query(cnt, a[i] ), cntR = query(cnt, maxn - 1) - cntL;// number of points to L/R of me
			ll sumL = query(sum, a[i] ), sumR = query(sum, maxn - 1) - sumL;// sum of points to L/R of me
			ret += (a[i] * cntL - sumL) + (sumR - a[i] * cntR);
			update(cnt, a[i], 1);
			update(sum, a[i], a[i]);
		}
		printf("Case %d: %lld\n", tc, ret);
	}
}
