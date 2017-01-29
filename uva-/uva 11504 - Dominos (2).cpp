#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;


const int MAX = 100500;

stack<int> st;
bool inStack[MAX];
int dfsn[MAX], lowLink[MAX], ndfs, scc, m, n;
vector<int> adj[MAX], p[MAX];

void targan(int u){
	dfsn[u] = lowLink[u] = ndfs++, inStack[u] = true;
	st.push(u);
	for (auto v : adj[u]) 
		if (dfsn[v] == -1) {
			targan(v);
			lowLink[u] = min(lowLink[u], lowLink[v]);
		} else if (inStack[v])
			lowLink[u] = min(lowLink[u], dfsn[v]);
	if (lowLink[u] == dfsn[u]) {
		int x = -1;
		bool f = true;
		while (x != u) {
			x = st.top();	st.pop();
			for (auto v : p[x])
				if (dfsn[v] == -1)
					f = false;
			inStack[x] = false;
		}
		if (st.empty() && f)
			scc++;
	}
	return;
}

int main(){
    freopen("uva.txt","rt",stdin);
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &n, &m);
		ndfs = 0, scc = 0;
		st = stack<int>();
		for (int i = 1; i <= n; i++)
			inStack[i] = false, dfsn[i] = -1, adj[i].clear(), p[i].clear();
		int a, b;
		for (int i = 0; i < m; i++)
			scanf("%d%d", &a, &b), adj[a].push_back(b), p[b].push_back(a);
		for (int i = 1; i <= n; i++)
			if (dfsn[i] == -1)
				targan(i);
		printf("%d\n", scc);
	}
}
