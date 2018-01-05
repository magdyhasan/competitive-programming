/*
	we can save for each index i, queries whose left is i and save them in q[i]
	now if we iterate from right to left, notice the only difference we can make,
	is when find a number that appeared before in some position j
	so a[i] == a[j]
	what can get affect by this same number in position (i,j) is any queries with r >= j
	so to do this we use segment tree when we reach number that appeared before we add min value
	for all position >= j with value (j-i)
*/
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

const int maxn = 600500;

int segT[maxn * 8], a[maxn];
int n;

int query(int x, int y, int idx = 1, int l = 1, int r = n){
	if (r < x || l > y) return 1061109567;
	if (x <= l && y >= r) return segT[idx];
	int mid = (l + r) / 2, lidx = idx << 1;
	return min(query(x, y, lidx, l, mid), query(x, y, lidx | 1, mid + 1, r));
}

void update(int x, int v, int idx = 1, int l = 1, int r = n){
	if (l == r){
		segT[idx] = min(segT[idx], v);
		return;
	}
	int mid = (l + r) / 2, lidx = idx << 1;
	if (x <= mid) update(x, v, lidx, l, mid);
	if(x > mid) update(x, v, lidx | 1, mid + 1, r);
	segT[idx] = min(segT[lidx], segT[lidx | 1]);
}



map<int, int> last;
int ans[maxn];
vector<pii> q[maxn];	
int nxt[maxn];

int main(){
#ifndef ONLINE_JUDGE
	freopen("uva.txt", "rt", stdin);
#endif
	memset(segT, 63, sizeof(segT));
	int m; scii(n, m);
	lp(i, n) sci(a[i+1]);
	lp(i, m){
		int l, r; scii(l, r);
		q[l].push_back({ r, i });
	}
	for (int i = n; i > 0; i--){
		if (last.find(a[i]) != last.end())
			nxt[i] = last[a[i]];
		else nxt[i] = -1;
		last[a[i]] = i;
	}
	for (int i = n; i > 0; i--){
		if (nxt[i] != -1){
			update(nxt[i], nxt[i] - i);
		}
		for (auto qi : q[i]){
			ans[qi.second] = query(i, qi.first);
		}
	}
	lp(i, m){
		if (ans[i] == 1061109567) ans[i] = -1;
		pri(ans[i]);
	}
}

