#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> adjMax;
vector<int> vis, colAssign, rowAssign;

bool canMatch(int i,int notj = -1) // O(E)
{
	for (int j = 0; j<adjMax[i].size(); ++j) if (adjMax[i][j] && !vis[j]) {
		if (notj != -1 && notj == j) continue;
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
	int maxFlow = 0, rows = adjMax.size(), cols = adjMax[0].size();
	colAssign = vector<int>(cols, -1), rowAssign = vector<int>(rows, -1);

	for (int i = 0; i < rows; ++i) {
		vis = vector<int>(cols, 0);
		if (canMatch(i))
			maxFlow++;
	}
	return maxFlow;
}

int a[300500];

int main(){
    freopen("uva.txt","rt",stdin);
	int n; scanf("%d", &n);
	adjMax.resize(n);
	for (int i = 0; i < n; i++) adjMax[i].resize(n);
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)adjMax[i][j] = 0;
	for (int i = 0; i < n; i++){
		scanf("%d", a + i);
	}
	for (int t = 0; t < n; t++){
		int l, r; scanf("%d%d", &l, &r);
		for (int i = 0; i < n; i++) if (a[i] >= l&&a[i] <= r)
			adjMax[t][i] = 1;
	}	
	if (bipartiteMatching() != n) puts("Let's search for another office.");
	else{
		for (int i = 0; i < n; i++) for (int j = i + 1; j < n;j++)
			if (adjMax[i][rowAssign[j]] && adjMax[j][rowAssign[i]]){
				puts("Ask Shiftman for help."); return 0;
			}
		puts("Perfect!");
		for (int i = 0; i < n; i++) printf("%d ", rowAssign[i] + 1);
	}
}

