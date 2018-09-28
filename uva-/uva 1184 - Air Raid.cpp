/*
	problem is to find minimum number of paths to cover all nodes

	so it's just a minimum path cover algoirthm
	
	which is N - maximumMactching
*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 300500;


vector<vector<int>> adjMax;
vector<int> vis, colAssign, rowAssign;

bool canMatch(int i){ // O(E)
	for (int j = 0; j<adjMax[i].size(); ++j) if (adjMax[i][j] && !vis[j]) {
		vis[j] = 1;
		if (colAssign[j] < 0 || canMatch(colAssign[j])) {
			colAssign[j] = i, rowAssign[i] = j;
			return true;
		}
	}
	return false;
}


int bipartiteMatching(){	// O(EV)
	int maxFlow = 0, rows = adjMax.size(), cols = adjMax[0].size();
	colAssign = vector<int>(cols, -1), rowAssign = vector<int>(rows, -1);
	for (int i = 0; i<rows; ++i) {
		vis = vector<int>(cols, 0);
		if (canMatch(i))
			maxFlow++;
	}
	return maxFlow;
}


int main(){
	int tc; scanf("%d", &tc);
	while (tc--){
		int n, m, u, v;
		scanf("%d%d", &n, &m);
		adjMax.clear();
		adjMax.resize(n, vector<int>(n));
		while (m--){
			scanf("%d%d", &u, &v);
			--u; --v;
			adjMax[u][v] = 1;
		}
		printf("%d\n", n - bipartiteMatching());
	}
}