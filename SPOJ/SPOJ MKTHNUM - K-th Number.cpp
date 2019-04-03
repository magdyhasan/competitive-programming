/*
	standard task using segment trees with sorted vectors in nodes
	and using BS 
	time: O(Nlog^2N)
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define all(v)           ((v).begin()), ((v).end())
#define sz size()
#define clr(v,d)         memset(v,d,sizeof(v))
#define lp(i, n)         for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define sci(a)	scanf("%d",&a)
#define scii(a, b)	scanf("%d%d",&a, &b)
#define scll(a)	scanf("%lld",&a)
#define pri(a)	printf("%d\n",a)
#define prll(a)	printf("%lld\n",a)

const int maxn = 100005;

const int MOD = 1e9 + 7;
typedef pair<int, int> pii;

vector<int> segT[maxn * 4];
int n;

int a[maxn];

void build(int idx = 1, int l = 0, int r = n - 1){
	if (l == r){
		segT[idx].push_back(a[l]);
		return;
	}
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	build(lidx, l, mid);
	build(ridx, mid + 1, r);
	segT[idx].resize(r - l + 1);
	merge(all(segT[lidx]), all(segT[ridx]), segT[idx].begin());
}

int query(int x, int y, int v, int idx = 1, int l = 0, int r = n - 1){
	if (x > r || y < l) return 0;
	if (x <= l && y >= r) return upper_bound(all(segT[idx]), v) - segT[idx].begin();
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	return query(x, y, v, lidx, l, mid) + query(x, y, v, ridx, mid + 1, r);
}

int main(){
	freopen("uva.txt", "r", stdin);
	int q; scii(n, q);
	lp(i, n) sci(a[i]);
	build();
	sort(a, a + n);
	while (q--){
		int l, r, k; scii(l, r); sci(k);
		--l; --r;
		int ll = 0, rr = n - 1, mid, ans;
		while (ll <= rr){
			mid = (ll + rr) / 2;
			if (query(l, r, a[mid]) >= k){
				ans = a[mid];
				rr = mid - 1;
			}
			else
				ll = mid + 1;
		}
		pri(ans);
	}
}