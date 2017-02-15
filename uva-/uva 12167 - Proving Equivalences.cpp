#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

const int maxn = 20500;

int dfsn[maxn], lowLink[maxn], inStack[maxn], comp[maxn];
int inD[maxn], outD[maxn];

int ndfs, sc, n, m;
vector<int> adj[maxn];
stack<int> st;

void targan(int u){
	dfsn[u] = lowLink[u] = ndfs++, inStack[u] = true, st.push(u);
	for (auto v : adj[u])
		if (dfsn[v] == -1) {
			targan(v);
			lowLink[u] = min(lowLink[u], lowLink[v]);
		}
		else if (inStack[v]) // if a cycle 
			lowLink[u] = min(lowLink[u], dfsn[v]);
	if (lowLink[u] == dfsn[u]) { // if this a root of a new component 
		int x = -1;
		while (x != u) {
			x = st.top();	st.pop();
			inStack[x] = false;
			comp[x] = sc;
		}
		sc++;
	}
}

int main(){
    freopen("uva.txt","rt",stdin);
	int T, u, v;
	scanf("%d", &T);
	while (T--){
		scanf("%d%d", &n, &m);
		for (int i = 0; i <= n; i++) dfsn[i] = -1, inD[i] = outD[i] = inStack[i] = 0, adj[i].clear();
		for (int i = 0; i < m; i++){
			scanf("%d%d", &u, &v);
			adj[u].push_back(v);
		}
		ndfs = sc = 0;
		st = stack<int>();
		for (int i = 1; i <= n; i++) if (dfsn[i] == -1) targan(i);
		for (int i = 1; i <= n; i++)
			for (int j : adj[i])
				if (comp[i] != comp[j])
					inD[comp[j]]++, outD[comp[i]]++;
		int x = 0, y = 0;
		for (int i = 0; i < sc; i++) {
			if (inD[i] == 0) x++;
			if (outD[i] == 0) y++;
		}
		if (sc == 1) puts("0");
		else printf("%d\n", max(x, y));

	}
}
