#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


struct node{
	int l, r;
} nu[100500];

void link(int a, int b){
	nu[a].r = b, nu[b].l = a;
}


int main(){
    freopen("uva.txt","rt",stdin);
	int n, m, tc = 0;
	while (scanf("%d%d", &n, &m) == 2){
		for (int i = 1; i <= n; i++) nu[i].l = i - 1, nu[i].r = i + 1;
		nu[n].r = 0, nu[0].r = 1;
		bool re = 0;
		//just simulate
		for (int i = 0; i < m; i++){
			int ty; scanf("%d", &ty);
			if (ty == 4){
				re = !re;
				continue;
			}
			int x, y;	 scanf("%d%d", &x, &y);
			if (ty == 3){
				if (nu[y].r == x) swap(x, y);	// make sure if x,y adjacent, then y is right to x
				if (nu[x].r == y){
					link(nu[x].l, y);
					link(x, nu[y].r);
					link(y, x);
				}
				else{
					int xl = nu[x].l, xr = nu[x].r;
					link(nu[y].l, x);	link(x, nu[y].r);
					link(xl, y); link(y, xr);
				}
				continue;
			}
			if (re) ty = 3 - ty;
			if ((ty == 1 && nu[y].l == x) || (ty == 2 && nu[y].r == x)) continue;
			link(nu[x].l, nu[x].r);
			if (ty == 1){// move x to the left of y
				link(nu[y].l, x);
				link(x, y);
			}
			else{// move x to the right of y
				link(x, nu[y].r);
				link(y, x);
			}
		}
		long long ret = 0;
		int cur = 0;
		int po = 1;
		if (re && n % 2 == 0) po = 0;
		for (int i = 1; i <= n; i++){
			cur = nu[cur].r;
			if (i % 2 == po) ret += cur;
		}
		printf("Case %d: %lld\n", ++tc, ret);
	}
}
