#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> adjMax;
vector<int> vis, colAssign, rowAssign;

bool canMatch(int i) // O(E)
{
	for (int j = 0; j<adjMax[i].size(); ++j) if (adjMax[i][j] && !vis[j]) {
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
    freopen("uva.txt","rt",stdin);
	int T;
	scanf("%d", &T);
	while (T--){
		int p, n;
		scanf("%d%d", &p, &n);
		adjMax = vector <vector<int>>(n, vector<int>(p, 0));
		for (int i = 0; i < p; i++){
			int tcnt, tv;	 scanf("%d", &tcnt);

			for (int j = 0; j < tcnt; j++){
				scanf("%d", &tv);
				adjMax[tv - 1][i] = 1;
			}
		}
		if (bipartiteMatching() == p) puts("YES");
		else puts("NO");
	}
}
