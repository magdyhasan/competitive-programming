#include<bits/stdc++.h>
using namespace std;

const int maxn = 300500;

int p[maxn], a[maxn], vis[maxn];

vector<int> idx[10500];

int par(int x){
	return (x == p[x]) ? x : p[x] = par(p[x]);
}


int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	while (T--){
		int n, m; scanf("%d%d", &n, &m);
		for (int i = 0; i <= n; i++) p[i] = i, vis[i] = 0, idx[i].clear();
		for (int i = 0; i < n; i++) scanf("%d", a + i);
		int u, v;
		for (int i = 0; i < m; i++ ){
			scanf("%d%d", &u, &v); u--; v--;
			u = par(u), v = par(v);
			if (u != v){
				p[u] = v;
			}
		}
		for (int i = 0; i < n; i++) idx[par(i)].push_back(i);
		vector<int> cyc;
		for (int i = 0; i < n; i++) if (idx[i].size()>1) cyc.push_back(i);
		for (int i = 0; i < cyc.size(); i++) {
			vector<int> cur;
			for (int j : idx[cyc[i]]) cur.push_back(a[j]);
			sort(cur.begin(), cur.end());
			int cnt = 0;
			for (int j : idx[cyc[i]]) a[j] = cur[cnt++];
		}
		for (int i = 0; i < n; i++) printf("%d%s", a[i], (i + 1 == n) ? "\n" : " ");
	}
}
