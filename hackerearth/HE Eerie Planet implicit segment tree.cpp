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

struct seg{
	seg *left, *right;
	int mx;
	int lazy;
	seg(int a = 0){
		mx = a;
		lazy = 0;
		left = NULL;
		right = NULL;
	}
} *root;

void push(seg *idx, int l, int r){
	if (idx->lazy){
		idx->mx = max(idx->mx, idx->lazy);
		if (!idx->left) idx->left = new seg(0);
		if (!idx->right) idx->right = new seg(0);
		idx->left->lazy = max(idx->left->lazy,idx->lazy);
		idx->right->lazy = max(idx->right->lazy,idx->lazy);
		idx->lazy = 0;
	}
}


int query(int x, int y, seg *idx = root, int l = 1, int r = 1e9){
	if (x > r || y < l) return 0;
	if (!idx) return 0;
	push(idx, l, r);
	if (x <= l && y >= r) return idx->mx;
	int mid = (l + r) / 2;
	return max(query(x, y, idx->left, l, mid), query(x, y, idx->right, mid + 1, r));
}


seg *update(int x, int y, int v, seg *idx = root, int l = 1, int r = 1e9){
	if (x > r || y < l) return idx;
	if (!idx) idx = new seg(0);
	if (x <= l && y >= r){
		idx->lazy = max(idx->lazy, v);
		push(idx, l, r);
		return idx;
	}
	int mid = (l + r) / 2;
	if (x <= mid) idx->left = update(x, y, v, idx->left, l, mid);
	if (y>mid) idx->right = update(x, y, v, idx->right, mid + 1, r);
	if (idx->left) idx->mx = max(idx->mx, idx->left->mx);
	if (idx->right) idx->mx = max(idx->mx, idx->right->mx);
	return idx;
}



int main(){
	freopen("uva.txt", "rt", stdin);
	root = new seg(0);
	int h, c, q; 
	scanf("%d%d%d", &h, &c, &q);
	int hi, si, ei, ti;
	for (int i = 0; i < c; i++){
		scanf("%d%d%d", &hi, &si, &ei);
		update(si, ei, hi);
	}
	while (q--){
		scanf("%d%d", &hi, &ti);
		puts(query(ti, ti) < hi ? "YES" : "NO");
	}
}