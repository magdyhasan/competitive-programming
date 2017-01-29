#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;

int arr[50500], n;


typedef pair<pair<int, int>, pair<int, int>> node;
#define mn(a,b,c,d) node(make_pair(a,b),make_pair(c,d))
#define Sum first.first 
#define Pre first.second 
#define Suf second.first 
#define Mx second.second 

node seg[200500];

node merge(node &a, node &b){
	node ret;
	ret.Sum = a.Sum + b.Sum;
	ret.Pre = max(a.Pre, a.Sum + b.Pre);
	ret.Suf = max(b.Suf, b.Sum + a.Suf);
	ret.Mx = max(max(a.Mx, b.Mx), max(ret.Sum, a.Suf + b.Pre));
	return ret;
}

void build_tree(int idx = 1, int l = 0, int r = n - 1){
	if (l == r) {
		seg[idx].Sum = seg[idx].Pre = seg[idx].Suf = seg[idx].Mx = arr[l];
		return;
	}
	int mid = (l + r) / 2;
	build_tree(idx * 2, l, mid);
	build_tree(idx * 2 + 1, mid + 1, r);
	seg[idx] = merge(seg[idx * 2], seg[idx * 2 + 1]);
	return;
}


node query(int x, int y, int idx = 1, int l = 0, int r = n - 1){
	if (x > r || l > y)	return mn(0, 0, 0, 0);
	if (x <= l && r <= y)	return seg[idx];
	int mid = (l + r) / 2;
	if (y <= mid)
		return query(x, y, idx * 2, l, mid);
	if (x > mid)
		return query(x, y, idx * 2 + 1, mid + 1, r);
	node a = query(x, y, idx * 2, l, mid);
	node b = query(x, y, idx * 2 + 1, mid + 1, r);
	return merge(a, b);
}

int main(){
	freopen("uva.txt", "rt", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)	scanf("%d", arr + i);
	build_tree(1, 0, n - 1);
	int q;	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int l, r;	scanf("%d%d", &l, &r);	l--;	r--;
		printf("%d\n", query(l, r, 1, 0, n - 1).Mx);
	}
}
