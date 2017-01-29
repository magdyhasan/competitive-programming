#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<utility>
using namespace std;

typedef pair<int, int> node;
#define mn(a,b)	 make_pair(a,b)	
#define mxa first
#define mxb second

int n;
int arr[400000];
node seg[400000];

node merge(node &a, node &b){
	node ret;
	ret.mxa = max(a.mxa, b.mxa);
	ret.mxb = min(max(a.mxa, b.mxb), max(b.mxa, a.mxb));
	return ret;
}

void build_tree(int idx = 1, int l = 0, int r = n - 1){
	if (l == r) {
		seg[idx].mxa = arr[l], seg[idx].mxb = 0;
		return;
	}
	int mid = (l + r) / 2;
	build_tree(idx * 2, l, mid);
	build_tree(idx * 2 + 1, mid + 1, r);
	seg[idx] = merge(seg[idx * 2], seg[idx * 2 + 1]);
	return;
}

void update(int x, int y, int idx = 1, int l = 0, int r = n - 1){
	if (l == r) {
		seg[idx].mxa = y, seg[idx].mxb = 0;
		return;
	}
	int mid = (l + r) / 2;
	if (x <= mid)
		update(x, y, idx*2, l, mid);
	else
		update(x, y, idx * 2 + 1, mid + 1, r);
	seg[idx] = merge(seg[idx * 2], seg[idx * 2 + 1]);
}

node query(int x, int y, int idx = 1, int l = 0, int r = n - 1){
	if (y < l || x > r)	return mn(0, 0);
	if (x <= l && y >= r)	return seg[idx];
	int mid = (l + r) / 2;
	node a = query(x, y, idx * 2, l, mid);
	node b = query(x, y, idx * 2 + 1, mid + 1, r);
	return merge(a, b);
}

int main(){
    freopen("uva.txt","rt",stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)	scanf("%d", arr + i);
	int q;	scanf("%d", &q);
	build_tree();
	for (int i = 0; i < q; i++) {
		char chq[2];	scanf("%s", chq);
		int l, r;	scanf("%d%d", &l, &r);	l--;
		if (chq[0] == 'Q') {
			node ret = query(l, r - 1);
			printf("%d\n", ret.mxa + ret.mxb);
		}
		else
			update(l, r);
	}
}
