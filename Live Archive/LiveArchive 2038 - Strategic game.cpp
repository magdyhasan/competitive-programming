#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 300500;


int dp1[maxn], dp2[maxn];
vector<int> adj[maxn];
int n;

void rec(int u, int p){
	int s1 = 1, s2 = 0;
	for (int v : adj[u]) if (v != p){
		rec(v, u);
		s1 += min(dp2[v],dp1[v]);
		s2 += dp1[v];
	}
	dp1[u] = s1;
	dp2[u] = s2;
}


int main(){
    freopen("uva.txt","rt",stdin);
	while (scanf("%d", &n) == 1){
		int u, v, m;
		for (int i = 0; i <= n; i++) adj[i].clear();
		for (int i = 0; i < n; i++){
			scanf("%d:(%d)", &u, &m);
			while (m--){
				scanf("%d", &v);
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
		}
		rec(0, -1);
		printf("%d\n", min(dp1[0], dp2[0]));
	}
}
