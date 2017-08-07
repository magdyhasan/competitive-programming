#include<bits/stdc++.h>
using namespace std;


const int maxn = 300500;

int lowLink[maxn], dfsn[maxn], inStack[maxn], comp[maxn], compsz[maxn], inDeg[maxn];
int ndfs, sc;


vector<int> adj[maxn];

stack<int> st;

void targan(int u){
	dfsn[u] = lowLink[u] = ndfs++, inStack[u] = true, st.push(u);
	for (auto v : adj[u]){
		if (dfsn[v] == -1) {
			targan(v);
			lowLink[u] = min(lowLink[u], lowLink[v]);
		}
		else if (inStack[v]) // if a cycle 
			lowLink[u] = min(lowLink[u], dfsn[v]);
	}
	if (lowLink[u] == dfsn[u]) { // if this a root of a new component 
		int x = -1;
		compsz[sc] = 0;
		while (x != u) {
			x = st.top();	st.pop();
			inStack[x] = false;
			comp[x] = sc;
			compsz[sc] ++;
		}
		sc++;
	}
}


bool vis[maxn];

int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	while (T--){
		int n; scanf("%d", &n);
		ndfs = sc = 0;
		for (int i = 0; i <= n;i++) 
			adj[i].clear(), inStack[i] = 0, lowLink[i] = 0, dfsn[i] = -1, inDeg[i] = 0, vis[i] = 0;
		for (int i = 1; i <= n; i++){
			int cnt, j; scanf("%d", &cnt);
			while (cnt--){
				scanf("%d", &j);
				adj[j].push_back(i);
			}
		}
		for (int i = 1; i <= n; i++) if (dfsn[i] == -1)
			targan(i);
		for (int i = 1; i <= n; i++) 
			for (int j : adj[i])
				if (comp[i] != comp[j])
			inDeg[comp[j]]++;
		int ret = 0;
		for (int i = 1; i <= n; i++) if (inDeg[comp[i]] == 0){
			queue<int> q; q.push(i);
			int cnt = 0;
			vis[i] = 1;
			while (!q.empty()){
				int u = q.front(); q.pop();
				cnt++;	
				for (int v : adj[u]) if (!vis[v])
					q.push(v), vis[v] = 1;
			}
			if (cnt == n)
				ret = max(ret, compsz[comp[i]]);
		}
		printf("%d\n", ret);
	}
}
