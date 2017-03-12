#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;

struct tile{
	int a, b, c, d;
} tgrid[10], grid[10];

int per[10];

int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++){
		if (tc > 1) puts("");
		for (int i = 0; i < 9; i++)
			scanf("%d%d%d%d", &tgrid[i].a, &tgrid[i].b, &tgrid[i].c, &tgrid[i].d);
		for (int i = 0; i < 9; i++) per[i] = i;
		bool f = false;
		do{
			for (int i = 0; i < 9; i++) grid[i] = tgrid[per[i]];
			bool f2 = true;
			for (int i = 0; i < 9 && f2; i++){
				if (i >= 3 && grid[i - 3].c != grid[i].a) f2 = 0;
				if (i >= 1 && (i % 3) != 0 && grid[i - 1].b != grid[i].d) f2 = 0;
				if (i < 9 && ((i + 1) % 3) != 0 && grid[i].b != grid[i + 1].d) f2 = false;
				if (i + 3 < 9 && grid[i].c != grid[i + 3].a) f2 = false;
			}
			f |= f2;
			if (f2) break;
		} while (next_permutation(per, per + 9));
		if (f) printf("Case %d: YES\n", tc);
		else printf("Case %d: NO\n", tc);
	}
}
