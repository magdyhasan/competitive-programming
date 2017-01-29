#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<map>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;



map<string, int> nameId;
vector<string> name;

int n, m, idCnt;
vector<int> adj[30];
int dfsn[30], lowLink[30], ndfs;
stack<int> st;
bool inStack[30];


void targan(int u){
	dfsn[u] = lowLink[u] = ndfs++, inStack[u] = true, st.push(u);
	for (auto v : adj[u])
		if (dfsn[v] == -1) {
			targan(v);
			lowLink[u] = min(lowLink[u], lowLink[v]);
		} else if (inStack[v])
			lowLink[u] = min(lowLink[u], dfsn[v]);
	if (lowLink[u] == dfsn[u]) {
		int x = -1;
		while (x != u) {
			x = st.top();	st.pop();
			inStack[x] = false;
			printf("%s", name[x].c_str());
			if (x != u)
				printf(", ");
			else
				puts("");
		}
	}
}

int main(){
    freopen("uva.txt","rt",stdin);
	int tc = 0;
	while (1) {
		scanf("%d%d", &n, &m);
		if (n == 0 && m == 0)	 break;
		idCnt = ndfs = 0;
		if (tc++)
			puts("");
		printf("Calling circles for data set %d:\n", tc);
		st = stack<int>();
		for (int i = 0; i < 30; i++)
			adj[i].clear(), dfsn[i] = -1, inStack[i] = 0;
		nameId.clear();
		name.clear();
		char a[30], b[30];
		for (int i = 0; i < m; i++) {
			scanf("%s%s", a, b);
			if (nameId.count(a) == 0)
				nameId[a] = idCnt++, name.push_back(a);
			if (nameId.count(b) == 0)
				nameId[b] = idCnt++, name.push_back(b);
			int aa = nameId[a];
			int bb = nameId[b];
			adj[aa].push_back(bb);
		}
		for (int i = 0; i < n; i++)
			if (dfsn[i] == -1)
				targan(i);
	}

}
