#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 100500;



int d[maxn], h[maxn];
vector<int> adj[maxn];

void dfs(int u, int p) {
	d[u] = 0;
	h[u] = 0;
	int mxh = -1;
	int mxd = 0;
	for (int v : adj[u]) if (v != p) {
		dfs(v, u);
		d[u] = max(d[u], mxh + h[v] + 2);
		mxh = max(mxh, h[v]);
		mxd = max(mxd, d[v]);
	}
	h[u] = mxh + 1;
	d[u] = max(d[u], mxd);
}


int main(){
    freopen("uva.txt","rt",stdin);
	int T;	scanf("%d", &T);
	while (T--){
		int n;	scanf("%d", &n);
		for (int i = 0; i < n; i++) adj[i].clear();
		for (int i = 0; i < n; i++) {
			int nu;	scanf("%d", &nu);
			for (int j = 0; j < nu; j++){
				int to;	scanf("%d", &to); to--;
				adj[i].push_back(to);
			}
		}
		dfs(0, -1);
		printf("%d\n", 2 * (n - 1) - d[0]);
	}
}
