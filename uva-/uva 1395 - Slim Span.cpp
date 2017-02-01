#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct edge{
	int to, from, w;
	edge(int a = 0, int b = 0, int c = 0) :to(a), from(b), w(c)	{}
	bool operator < (const edge & e) const {
		return w < e.w;
	}
} edges[5005];

int n, m;
int p[105], r[105];

int par(int x){
	return (x == p[x]) ? x : p[x] = par(p[x]);
}

void uni(int x, int y){
	if (r[y] > r[x]) swap(x, y);
	p[y] = x;
	if (r[x] == r[y]) r[x]++;
}

int solve(int s){
	int mx = 123456789, mi = edges[s].w, cntE = 0;
	for (int i = 0; i <= n; i++) p[i] = i, r[i] = 1;
	for (int i = s; i < m; i++){
		int x = edges[i].from, y = edges[i].to;
		x = par(x), y = par(y);
		if (x != y)
			uni(x, y), cntE++;
		if (cntE + 1 == n){
			mx = edges[i].w;
			break;
		}
	}
	if (mx == 123456789) return mx;
	return mx - mi;
}


int main(){
    freopen("uva.txt","rt",stdin);
	while (scanf("%d%d", &n, &m)){
		if (!n&&!m) break;
		for (int i = 0; i < m; i++) scanf("%d%d%d", &edges[i].from, &edges[i].to, &edges[i].w);
		sort(edges, edges + m);
		int ret = 123456789;
		for (int i = 0; i < m; i++) 
			ret = min(ret, solve(i));
		printf("%d\n", (ret == 123456789 ) ? -1:ret);
	}
}
