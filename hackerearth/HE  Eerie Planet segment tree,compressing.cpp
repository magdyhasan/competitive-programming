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


int h[maxn], s[maxn], e[maxn];
int qh[maxn], qt[maxn];
map<int, int> comp;
int tree[maxn*8], lazy[maxn*8];

int cc = 0;

void push(int idx, int l, int r){
	if (lazy[idx]){
		tree[idx] = max(tree[idx], lazy[idx]);
		if (l != r){
			int lidx = idx << 1, ridx = lidx | 1;
			lazy[lidx] = max(lazy[lidx],lazy[idx]);
			lazy[ridx] = max(lazy[ridx],lazy[idx]);
		}
		lazy[idx] = 0;	
	}
}


void update(int x, int y, int v, int idx = 1, int l = 0, int r = cc){
	if (x > r || y < l) return;
	push(idx, l, r);
	if (x <= l && y >= r){
		lazy[idx] = max(lazy[idx], v);
		push(idx, l, r);
		return;
	}
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	if (x <= mid) update(x, y, v, lidx, l, mid);
	if (y>mid) update(x, y, v, ridx, mid + 1, r);
	tree[idx] = max(tree[lidx], tree[ridx]);
}

int query(int x, int y, int idx = 1, int l = 0, int r = cc){
	if (x > r || y < l) return 0;
	push(idx, l, r);
	if (x <= l && y >= r) return tree[idx];
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	return max(query(x, y, lidx, l, mid), query(x, y, ridx, mid + 1, r));
}


int main(){
	freopen("uva.txt", "r", stdin);
	int H, C, Q; 
	scanf("%d%d%d", &H, &C, &Q);
	int hi, si, ei, ti;
	for (int i = 0; i < C; i++){
		scanf("%d%d%d", &h[i], &s[i], &e[i]);
		comp[s[i]];
		comp[e[i]];
	}
	lp(i, Q){
		scanf("%d%d", qh + i, qt + i);
		comp[qt[i]];
	}
	for (auto &i : comp) i.second = ++cc;
	lp(i, C) {
		s[i] = comp[s[i]], e[i] = comp[e[i]];
		update(s[i], e[i], h[i]);
	}
	lp(i, Q) {
		qt[i] = comp[qt[i]];
		puts(query(qt[i], qt[i]) < qh[i] ? "YES" : "NO");
	}
}

