/*
 * for updating ranges we use segment tree with lazy prop
 *
 * since array b is fixed, we need cnt of specific element in range
 * we can use map in each segment tree node
 *
 * now when we change range to x
 * we just check how many times x appears in b in this range
 */
#include <bits/stdc++.h>
using namespace std;


#define all(v)          ((v).begin()), ((v).end())
#define sz size()
#define clr(v,d)         memset(v,d,sizeof(v))
#define lp(i, n)         for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define sci(a)	scanf("%d",&a)
#define scii(a, b)	scanf("%d%d",&a, &b)
#define pri(a)	printf("%d\n",a)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)


const int maxn = 300500;
typedef long long ll;


struct node{
	unordered_map<int,int> ma;
	int si, lz;
} se[maxn];

int a[maxn], b[maxn];
int n;

inline void merge(int idx,int lidx,int ridx, bool upm = 0){
	if(upm){
		//se[idx].ma.clear();
		for(auto i:se[lidx].ma)
			se[idx].ma[i.first] += i.second;
		for(auto i:se[ridx].ma)
			se[idx].ma[i.first] += i.second;
	}
	se[idx].si = se[lidx].si + se[ridx].si;
	se[idx].lz = -1;
}


void build(int idx = 1, int l = 0, int r = n - 1){
	if (l == r){
		//se[idx].ma.clear();
		++se[idx].ma[b[l]];
		se[idx].lz = -1;
		se[idx].si = a[l] == b[l];
		return;
	}
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	build(lidx, l, mid);
	build(ridx, mid + 1, r);
	merge(idx,lidx,ridx, 1);
}
void push(int idx,int l,int r){
	if (se[idx].lz != -1){
		if(se[idx].ma.find(se[idx].lz) != se[idx].ma.end())
			se[idx].si = se[idx].ma[se[idx].lz];
		else
			se[idx].si = 0;
		if (l != r){
			se[idx << 1].lz = se[idx].lz;
			se[(idx << 1) | 1].lz = se[idx].lz;
		}
		se[idx].lz = -1;
	}
}


void updateSeg(int x, int y, int v, int idx = 1, int l = 0, int r = n - 1){
	push(idx, l, r);
	if (x > r || y < l) return;
	if (x <= l && y >= r){
		//printf("up %d %d %d %d %d\n",l,r,v,se[1].si,se[idx].ma[v]);
		se[idx].lz = v;
		push(idx, l, r);
		return;
	}
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	updateSeg(x, y, v, lidx, l, mid);
	updateSeg(x, y, v, ridx, mid + 1, r);
	merge(idx,lidx,ridx);
}

int main() {
	freopen("in.txt","r",stdin);
	int tc; sci(tc);
	while(tc--){
		for(int i=0;i<maxn;i++) se[i].ma.clear();
		int q; scii(n,q);
		lp(i,n) sci(a[i]);
		lp(i,n) sci(b[i]);
		build();
		//pri(se[1].si);
		//pri(se[1].ma[1]);
		int tx,ty,tz;
		while(q--){
			sci(tx); scii(ty,tz);
			int pr = se[1].si;
			int ql = max(0,(pr^tx)-1), qr = min((pr^ty)-1,n-1), qv = pr^tz;
			//printf("%d %d %d\n",ql,qr,qv);
			updateSeg(ql,qr,qv);
			pri(se[1].si);
		}
	}
}
