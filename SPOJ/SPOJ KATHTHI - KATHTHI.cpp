#include<bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

char g[1005][1005];
int n, m;
int v[1005][1005];

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

#define pii pair<int,int>

int bfs(){
	memset(v, 63, sizeof v);
	deque<pii> q;
	q.push_front({ 0, 0 });
	v[0][0] = 0;
	while (!q.empty()){
		int i = q.front().first;
		int j = q.front().second;
		q.pop_front();
		for (int k = 0; k < 4; k++){
			int ni = i + dx[k], nj = j + dy[k];
			if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
			int c = (g[i][j] != g[ni][nj]);
			if (v[i][j] + c < v[ni][nj]){
				v[ni][nj] = v[i][j] + c;
				if (c) q.push_back({ ni, nj });
				else q.push_front({ ni, nj });
			}
		}
	}
	return v[n - 1][m - 1];
}

int main(){

	int tc; scanf("%d", &tc);
	while (tc--){
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) scanf("%s", g + i);
		printf("%d\n", bfs());
	}
}