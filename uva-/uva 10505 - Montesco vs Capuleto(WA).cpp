#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> en[256];
int color[256];

bool f;
int A, B;

void dfs(int u,int c){
	if (f)	return; 
	if (c)	B++;
	else	A++;
	color[u] = c;
	for (int v : en[u])
		if (color[v] == -1)
			dfs(v, 1 - c);
	for (int v : en[u])
		if (color[v] == c)
			f = true;
	return;
}

int main(){
    freopen("uva.txt","rt",stdin);
	int tc;	scanf("%d", &tc);
	while (tc--) {
		int n, i, x, y, j;
		scanf("%d", &n);
		for (i = 0; i <= n; i++)	en[i].clear();
		for (i = 0; i < n; i++) {
			scanf("%d", &x);
			for (j = 0; j < x; j++) {
				scanf("%d", &y);
				y--;
				if (y >= n)	continue;
				en[i].push_back(y);
				en[y].push_back(i);
			}
		}
		int ret = 0;
		memset(color, -1, sizeof(color));
		for (i = 0; i < n;i++)
			if (color[i] == -1) {
				f = false;
				A = B = 0;
				dfs(i, 0);
				if (!f)
					ret += max(A, B);
			}
		printf("%d\n", ret);
	}
}
