#include<bits/stdc++.h>
using namespace std;


int n, m, q;

int a[128][128];
bool vis[128][128];

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

vector<int> cnt(){
	memset(vis, 0, sizeof(vis));
	vector<int> ret;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (a[i][j] && !vis[i][j]){
		queue<int> qu; qu.push(i); qu.push(j);
		int cur = 0;
		vis[i][j] = 1;
		while (!qu.empty()){
			int x = qu.front(); qu.pop();
			int y = qu.front(); qu.pop();
			cur++;
			for (int k = 0; k < 4; k++){
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny] || !a[nx][ny]) continue;
				qu.push(nx); qu.push(ny);
				vis[nx][ny] = 1;
			}
		}
		ret.push_back(cur);
	}
	sort(ret.begin(), ret.end());
	return ret;
}

int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	while (T--){
		scanf("%d%d%d", &m, &n, &q);
		int x, y;
		memset(a, 0, sizeof(a));
		for (int i = 0; i < q; i++) {
			scanf("%d%d", &y, &x); 
			a[x][y] = 1;
		}
		vector<int> b1 = cnt();
		memset(a, 0, sizeof(a));
		for (int i = 0; i < q; i++) {
			scanf("%d%d", &y, &x);
			a[x][y] = 1;
		}
		vector<int> b2 = cnt();
		puts(b1 == b2 ? "YES" : "NO");
	}
}
