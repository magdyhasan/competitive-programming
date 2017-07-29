#include <bits/stdc++.h>

#include <unordered_map>
using namespace std;
#define all(v)           ((v).begin()), ((v).end())
#define sz size()
#define clr(v,d)         memset(v,d,sizeof(v))
#define rep(i, v)        for(int i=0;i<(v).sz;++i)
#define lp(i, n)         for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define sci(a)	scanf("%d",&a)
#define scii(a, b)	scanf("%d%d",&a, &b)
#define pri(a)	printf("%d\n",a)
#define prii(a, b)	printf("%d %d\n",a, b)
#define DB1(a)          std::cout<<#a<<"="<<(a)<<endl
#define DB2(a,b)        std::cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<endl
#define DB3(a,b,c)      std::cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<endl
#define DB4(a,b,c,d)    std::cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<endl
#define DB5(a,b,c,d,e)  std::cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<endl
typedef pair<int, int> pii;
typedef long long ll;
const ll  inf = 1000000000000000000LL;
const double EPS = 1e-9;
const ll mod = 1000000007ll;
#define PI acos(-1)


const int  maxn = (int)100500 + 10;

int segT[maxn * 4];
int n, m;
int x, y, v;


void update(int idx = 1, int l = 0, int r = n - 1){
	if (x > r || y < l) return;
	if (x <= l && y >= r){
		segT[idx] |= v;
		return;
	}
	int mid = (l + r) >> 1;
	if (x <= mid)
		update(idx << 1, l, mid);
	if (y > mid)
		update((idx << 1) | 1, mid + 1, r);
	segT[idx] |= segT[idx << 1] & segT[(idx << 1) | 1];
	return;
}

int query(int idx = 1, int l = 0, int r = n - 1){
	if (x > r || y < l) return (1 << 30) - 1;
	if (x <= l && y >= r)return segT[idx];
	int mid = (l + r) >> 1;
	return segT[idx] | (query(idx << 1, l, mid)&query((idx << 1) | 1, mid + 1, r)) | segT[idx];
}

int al[maxn], ar[maxn];
int a[maxn];

int main(){
#ifndef ONLINE_JUDGE
	freopen("CF.in", "rt", stdin);
#endif
	scii(n, m);
	int l, r;
	lp(i, m) scii(al[i], ar[i]), scanf("%d", &a[i]), al[i]--, ar[i]--, x = al[i], y = ar[i], v = a[i], update();
	lp(i, m){
		x = al[i], y = ar[i];
		if (query() != a[i]) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	for (int i = 0; i < n; i++) {
		x = i, y = i;
		printf("%d ", query());
	}
}