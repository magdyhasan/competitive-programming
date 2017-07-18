#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

const int maxn = 300500;

map<int, int> p;
int cnt;
int par(int x){
	return (p[x] == 0) ? x : p[x] = par(p[x]);
}

int main(){
    freopen("uva.txt","rt",stdin);
	int n, m; scanf("%d%d", &n, &m);
	int u, v;
	cnt = n;
	for (int i = 0; i < m; i++){
		scanf("%d%d", &u, &v);
		u = par(u), v = par(v);
		if (u != v){
			cnt--;
			p[v] = u;
		}
	}
	printf("%d\n", cnt);
}

