#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 800500;
int a[maxn];


void update(ll T[], int idx,int val){
	for (; idx < maxn; idx |= (idx + 1))
		T[idx] += val;
}

ll query(ll T[], int idx){
	ll ret = 0;
	for (; idx >= 0; idx = (idx&(idx + 1)) - 1)
		ret += T[idx];
	return ret;
}

ll Tl[maxn], Tr[maxn];

int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	while (T--){
		int n; scanf("%d", &n);
		for (int i = 0; i < maxn; i++) Tl[i] = Tr[i] = 0;
		for (int i = 0; i < n; i++) scanf("%d", a + i);
		for (int i = 1; i < n; i++) update(Tr, a[i], 1);
		update(Tl, a[0], 1);
		ll ret = 0;
		for (int i = 1; i < n; i++){
			update(Tr, a[i], -1);
			ret += query(Tl, a[i])*(n-i-1-query(Tr, a[i]));
			ret += (i-query(Tl, a[i]))*query(Tr, a[i]);
			update(Tl, a[i], 1);
		}
		printf("%lld\n", ret);
	}
}
