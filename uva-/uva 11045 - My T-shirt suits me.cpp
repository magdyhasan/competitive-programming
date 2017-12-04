#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> vis, colAssign, rowAssign;

bool canMatch(int i) // O(E)
{
	for (int j = 0; j<adj[i].size(); ++j) if (adj[i][j] && !vis[j]) {
		vis[j] = 1;
		if (colAssign[j] < 0 || canMatch(colAssign[j])) {
			colAssign[j] = i, rowAssign[i] = j;
			return true;
		}
	}
	return false;
}


int bipartiteMatching()	// O(EV)
{	// In case spares graph, use adjList
	vector< pair<int, int> > matches;
	int maxFlow = 0, rows = adj.size(), cols = adj[0].size();
	colAssign = vector<int>(cols, -1), rowAssign = vector<int>(rows, -1);

	for (int i = 0; i<rows; ++i) {
		vis = vector<int>(cols, 0);
		if (canMatch(i))
			maxFlow++;
	}
	return maxFlow;
}


int ma(string st){
	if (st == "XXL") return 0;
	if (st == "XL") return 1;
	if (st == "L") return 2;
	if (st == "M") return 3;
	if (st == "S") return 4;
	if (st == "XS") return 5;
}

string a[64][2];

char st[1000], st2[1000];

int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	while (T--){
		int n, m; 
		scanf("%d%d", &n, &m);
		adj = vector<vector<int>>(m, vector<int>(n, 0));
		for (int i = 0; i < m; i++){
			scanf("%s%s", st, st2);
			a[i][0] = st, a[i][1] = st2;
		}
		n /= 6;
		for (int j = 0; j < n; j++){
			for (int i = 0; i < m; i++)
				adj[i][ma(a[i][0]) + j * 6] = 1, adj[i][ma(a[i][1]) + j * 6] = 1;
		}
		puts((bipartiteMatching() == m) ? "YES" : "NO");
	}
}
