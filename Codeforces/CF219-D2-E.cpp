/*
	We need to support this types of operations:
	- maximum empty range between cars
	- finding which index has start of maximum empty range
	- adding new car which decrase an empty range
	all this operations can be achieved with segment tree
	where we keep maximum empty length, and length of empty length to left, and length of empty lenfth to right

	*alternative solutions is just to keep all empty intervals but tricky implmentation
	here's an awsome implmentation of this idea: http://codeforces.com/contest/219/submission/2057598
*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 800500;

struct node{
	int mxln, sl, sr, ln;
}tr[maxn];

int n;

inline void merge(node &c, node &a, node &b){
	c.ln = a.ln + b.ln;

	c.mxln = max(a.mxln, b.mxln);
	c.mxln = max(c.mxln, a.sr + b.sl);

	c.sl = a.sl;
	if (a.sl == a.ln) c.sl += b.sl;

	c.sr = b.sr;
	if (b.sr == b.ln) c.sr += a.sr;
}

void build(int idx = 1, int l = 1, int r = n){
	if (l == r){
		tr[idx].mxln = tr[idx].sl = tr[idx].sr = tr[idx].ln = 1;
		return;
	}
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	build(lidx, l, mid);
	build(ridx, mid + 1, r);
	merge(tr[idx], tr[lidx], tr[ridx]);
}

void insert(int x, int y, int idx = 1, int l = 1, int r = n){
	if (l == r){
		tr[idx].mxln = tr[idx].sl = tr[idx].sr = y;
		return;
	}
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	if (x <= mid) insert(x, y, lidx, l, mid);
	else insert(x, y, ridx, mid + 1, r);
	merge(tr[idx], tr[lidx], tr[ridx]);
}

int query(int ln, int idx = 1, int l = 1, int r = n){
	if (l == r) return l;
	if (l == 1 && tr[idx].sl >= ln)
		return 1;
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	if (tr[lidx].mxln + 1 >= ln * 2)
		return query(ln, lidx, l, mid);
	if (tr[lidx].sr + tr[ridx].sl + 1 >= ln * 2)
		return mid - tr[lidx].sr + ln;
	return query(ln, ridx, mid + 1, r);
}

int pos[1000500];

int main(){
	int m; scanf("%d%d", &n, &m);
	build();
	while (m--){
		int ti, id;
		scanf("%d%d", &ti, &id);
		if (ti == 1){
			int mx = max((tr[1].mxln + 1) / 2, max(tr[1].sl, tr[1].sr));
			int idx = query(mx);
			insert(idx, 0);
			pos[id] = idx;
			printf("%d\n", idx);
		}
		else{
			insert(pos[id], 1);
		}
	}
}