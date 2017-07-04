#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
using namespace std;

vector<int> path;

int n, m;

int di[] = { -1, 1, -2, 2, -2, 2, -1, 1 };
int dj[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int cnt;


bool vis[55][55];

bool rec(int i, int j){
	cnt++;
	path.push_back(i); path.push_back(j);
	if (cnt == n*m){
		for (int i = 0; i < path.size(); i += 2)
			printf("%c%d", (path[i + 1] + 'A'), path[i] + 1);
		puts("");
		return 1;
	}
	for (int k = 0; k < 8; k++){
		int ni = i + di[k];
		int nj = j + dj[k];
		if (ni < 0 || nj < 0 || nj >= m || ni >= n || vis[ni][nj]) continue;
		vis[ni][nj] = 1;
		if (rec(ni, nj)) return 1;
		vis[ni][nj] = 0;
	}
	path.pop_back(); path.pop_back();
	cnt--;
	return 0;
}

bool solve(){
	memset(vis, 0, sizeof(vis));
	path.clear();
	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++){
		cnt = 0;
		vis[i][j] = 1;
		if (rec(i, j)) return 1;
		vis[i][j] = 0;
	}
	return 0;
}

int main(){
    freopen("uva.txt","rt",stdin);
	int T;  scanf("%d", &T);
	while (T--){
		scanf("%d%d", &n, &m);
		if (!solve()) puts("-1");
	}
}

