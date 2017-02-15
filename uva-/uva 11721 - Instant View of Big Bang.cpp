#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 2005;

int n, m;
int fr[maxn], to[maxn], co[maxn];
int d[maxn], inCycle[maxn];

vector<int> radj[maxn];

void dfs(int u){
	inCycle[u] = true;
	for (int v : radj[u])
		if (!inCycle[v])
			dfs(v);
}

int main(){
    freopen("uva.txt","rt",stdin);
	int T;
	scanf("%d", &T);
	for (int te = 1; te <= T; te++) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i <= n; i++) d[i] = inCycle[i] = 0, radj[i].clear();
		for (int i = 0; i < m; i++)
			scanf("%d%d%d", to + i, fr + i, co + i), radj[fr[i]].push_back(to[i]);
		vector<int> cycle;
		for (int k = 0; k < n; k++){
			for (int i = 0; i < m; i++) if (d[to[i]] > d[fr[i]] + co[i]){
				if (k + 1 == n)
					cycle.push_back(fr[i]);
				else
					d[to[i]] = max(-12345678,d[fr[i]] + co[i]);
			}
		}
		printf("Case %d:", te);
		if (cycle.empty()) puts(" impossible");
		else{
			for (int u : cycle) if (!inCycle[u])  dfs(u);
			for (int i = 0; i < n; i++)
				if (inCycle[i])
					printf(" %d", i);
			puts("");
		}
	}
}
