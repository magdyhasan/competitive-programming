#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;

int Ca, Cb, N, ret, fa, fb;
short vis[1001][1001], st[1001][1001][3];

void dfs(int a, int b, int moves, int cmd, int la, int lb){
	if (vis[a][b] <= moves)
		return;
	vis[a][b] = moves, st[a][b][0] = cmd, st[a][b][1] = la, st[a][b][2] = lb;
	if (a == N || b == N) {
		if (ret > moves)
			ret = moves, fa = a, fb = b;
		return;
	}
	dfs(Ca, b, moves + 1, 0, a, b); // fill a
	dfs(a, Cb, moves + 1, 1, a, b); // fill b
	dfs(0, b, moves + 1, 2, a, b); // empty a
	dfs(a, 0, moves + 1, 3, a, b); // empty b
	int w = min(Cb - b, a);
	dfs(a - w, b + w, moves + 1, 4, a, b);
	w = min(Ca - a, b);
	dfs(a + w, b - w, moves + 1, 5, a, b);
	return;
}


void print(int a, int b){
	if (st[a][b][0] == -1)
		return;
	print(st[a][b][1], st[a][b][2]);
	switch (st[a][b][0]) {
		case 0:puts("fill A"); break;
		case 1:puts("fill B"); break;
		case 2:puts("empty A"); break;
		case 3:puts("empty B"); break;
		case 4:puts("pour A B"); break;
		case 5:puts("pour B A"); break;
	}
	return;
}

int main(){
    freopen("uva.txt","rt",stdin);
	while (scanf("%d%d%d", &Ca, &Cb, &N) == 3) {
		ret = 10000000;
		memset(vis, 63, sizeof(vis));
		dfs(0, 0, 0, -1, 0, 0);
		print(fa, fb);
		puts("success");
	}
}
