#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct node {
	int l, r;
	int val, cnt;
};

node nodes[31 * 100500];
int n = 1;

inline int GCD(int a, int b){
	if (b == 0)
		return a;
	return GCD(b, a%b);
}

void update(int x, int y, int &idx, int l = 1, int r = 1000000000){
	if (idx == 0) idx = ++n;
	if (l == r){
		nodes[idx].cnt += y;
		if (nodes[idx].cnt == 0) nodes[idx].val = 0;
		else nodes[idx].val = x;
		return;
	}
	int mid = (l + r) >> 1;
	if (x <= mid) update(x, y, nodes[idx].l, l, mid);
	else update(x, y, nodes[idx].r, mid + 1, r);
	nodes[idx].val = GCD(nodes[nodes[idx].l].val, nodes[nodes[idx].r].val);
}

int main(){
    freopen("uva.txt","rt",stdin);
	int q;	scanf("%d", &q);
	int r = 1;
	while (q--){
		char st[10];
		int t;
		scanf("%s%d", st, &t);
		if (st[0] == '+') update(t, 1, r);
		else update(t, -1, r);
		printf("%d\n", nodes[1].val == 0 ? 1 : nodes[1].val);
	}
}
