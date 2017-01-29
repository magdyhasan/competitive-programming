#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<utility>
#include<algorithm>
using namespace std;

typedef pair<int, int> node;
#define mn(a,b) make_pair(a,b)
#define o first
#define c second

int n;

char st[120000];
node seg[120000];

node merge(node &a, node &b){
	node ret;
	int match = min(a.o, b.c);
	ret.o = a.o + b.o - match;
	ret.c = a.c + b.c - match;
	return ret;
}

void build_tree(int idx = 1, int l = 0, int r = n - 1){
	if (l == r) {
		seg[idx].o = (st[l] == '('), seg[idx].c = (st[l] == ')');
		return;
	}
	int mid = (l + r) / 2;
	build_tree(idx * 2, l, mid);
	build_tree(idx * 2 + 1, mid + 1, r);
	seg[idx] = merge(seg[idx * 2], seg[idx * 2 + 1]);
	return;
}


void update(int x, int idx = 1, int l = 0, int r = n - 1){
	if (l == r) {
		swap(seg[idx].o, seg[idx].c);
		return;
	}
	int mid = (l + r) / 2;
	if (x <= mid)
		update(x, idx * 2, l, mid);
	else
		update(x, idx * 2 + 1, mid + 1, r);
	seg[idx] = merge(seg[idx * 2], seg[idx * 2 + 1]);
	return;
}


int main(){
    freopen("uva.txt","rt",stdin);
	for (int tc = 1; tc <= 10; tc++) {
		printf("Test %d:\n", tc);
		scanf("%d", &n);
		scanf("%s", st);
		build_tree(); 
		int q;	scanf("%d", &q);
		for (int i = 0; i < q; i++) {
			int k;	scanf("%d", &k);
			if (k)	update(k - 1);
			else	printf("%s\n", (seg[1].c == 0 && seg[1].o == 0) ? "YES" : "NO");
		}
	}
}
