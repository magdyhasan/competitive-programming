#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
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

const int maxn = 300500;

int a[maxn];
vector<pii> g[maxn];
int vis[8000500];
int mx[maxn];
ll segT[maxn * 8], lazy[maxn * 8];

ll ret[maxn];
int n, q;  

void push(int idx,int l,int r){
	if (lazy[idx]){
		int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
		lazy[lidx] += lazy[idx];
		lazy[ridx] += lazy[idx];
		segT[lidx] += (mid - l + 1)*lazy[idx];
		segT[ridx] += (r - mid)*lazy[idx];
		lazy[idx] = 0;
	}
}

void update(int x, int y, int idx = 1, int l = 0, int r = n - 1){
	if (x > r || y < l) return;
	push(idx, l, r);
	if (x <= l && y >= r){
		lazy[idx] ++;
		segT[idx] += r - l + 1;	
		return;
	}
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	if (x <= mid) update(x, y, lidx, l, mid);
	if (y>mid) update(x, y, ridx, mid + 1, r);
	segT[idx] = segT[lidx] + segT[ridx];
}

ll query(int x, int y, int idx = 1, int l = 0, int r = n - 1){
	if (x > r || y < l) return 0;
	push(idx, l, r);
	if (x <= l&&y >= r) return segT[idx];
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	return query(x, y, lidx, l, mid) + query(x, y, ridx, mid + 1, r);
}


int main(){
	freopen("uva.txt", "r", stdin);
	scii(n, q);
	lp(i, n) sci(a[i]);
	int l, r;
	lp(i, q){
		scii(l, r); l--; r--;
		g[l].push_back({ r, i });
	}
	int i = 0, j = 0;
	for (; i < n; i++){
		while (j < n && !vis[a[j]]) vis[a[j]]++, j++;
		mx[i] = j - 1;
		vis[a[i]]--;
	}
	for (int i = n - 1; i >= 0; i--){
		update(i, mx[i]);
		for (auto r : g[i])
			ret[r.second] = query(i, r.first);
	}
	lp(i, q) printf("%lld\n", ret[i]);
}

