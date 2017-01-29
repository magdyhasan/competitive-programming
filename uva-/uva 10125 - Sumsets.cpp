#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;


int n;
int num[1005];

struct node{
	int i, j, sum;
	node() {}
	node(int a, int b, int c) : i(a), j(b), sum(c) {}
	bool operator < (const node &a) const {
		return sum < a.sum;
	}
};

node l[500000];
int l_cnt;

bool solve(){
	for (int d = n - 1; d >= 0; d--) // try all possible value for d from biggest
		for (int c = 0; c < n; c++) { // try all possible value for c from smallest
			if (d == c)
				continue;
			int low = lower_bound(l, l + l_cnt, node{ c, d, num[d] - num[c] }) - l; // find a+b such that a+b == d-c
			int up = upper_bound(l, l + l_cnt, node{ c, d, num[d] - num[c] }) - l;
			for (int i = low; i < up;i++)
				if (c != l[i].i && c != l[i].j && d != l[i].i && d != l[i].j) { // if a+b == c+d and a,b,c and d are distinct
					printf("%d\n", num[d]);
					return 1;
				}
		}
	return 0;
}

int main(){
	while (scanf("%d",&n) && n) {
		for (int i = 0; i < n; i++)
			scanf("%d", num + i);
		sort(num, num + n);
		l_cnt = 0;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++) // calculate all a+b
				l[l_cnt++] = { i, j, num[i] + num[j] };
		sort(l, l + l_cnt); // sort all a+b
		if (solve() == false)
			puts("no solution");
	}
}
