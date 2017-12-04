#include<bits/stdc++.h>
using namespace std;

int n, m;
int li, lj;

char a[16][16], b[16][16];
int d[16][16];

int di[] = { 1, -1, 0, 0 };
int dj[] = { 0, 0, 1, -1 };

bool vis[16][16];


bool check(){
	int lai = -1, laj;
	for (int i = n - 1; i >= 0 && lai == -1; i--) for (int j = 0; j < n; j++) {
		if (a[i][j] == '*'){
			lai = i, laj = j;
			break;
		}
	}
	queue<int> q; q.push(lai); q.push(laj);
	q.push(li); q.push(lj);
	if (lai == -1) return 0;
	a[lai][laj] = '.';
	int addi = 0, addj = 0;
	while (!q.empty()){
		int i = q.front(); q.pop();
		int j = q.front(); q.pop();
		int x = q.front(); q.pop();
		int y = q.front(); q.pop();
		for (int k = 0; k < 4; k++){
			int ni = i + di[k];
			int nj = j + dj[k];
			if (ni < 0 || nj < 0 || ni >= n || nj >= n || a[ni][nj] != '*') {
				if (d[x][y] & (1 << k)) 
					return 0;
				continue;
			}
			if (!(d[x][y] & (1 << k))) continue;
			q.push(ni); q.push(nj);
			q.push(x + di[k]); q.push(y + dj[k]);
			a[ni][nj] = '.';
		}
	}
	return 1;
}

int main(){
    freopen("uva.txt","rt",stdin);
	while (scanf("%d%d", &n, &m) && n){
		li = -1;
		memset(d, 0, sizeof(d));
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; i++) scanf("%s", a + i);
		for (int i = 0; i < m; i++) scanf("%s", b + i);
		for (int i = m - 1; i >= 0 && li == -1; i--) for (int j = 0; j < m; j++) {
			if (b[i][j] == '*'){
				li = i, lj = j;
				break;
			}
		}
		queue<int> q; q.push(li); q.push(lj);
		vis[li][lj] = 1;
		while (!q.empty()){
			int i = q.front(); q.pop();
			int j = q.front(); q.pop();
			for (int k = 0; k < 4; k++){
				int ni = i + di[k];
				int nj = j + dj[k];
				if (ni < 0 || nj < 0 || ni >= m || nj >= m || vis[ni][nj] || b[ni][nj] != '*') continue;
				d[i][j] |= 1 << k;
				q.push(ni); q.push(nj);
				vis[ni][nj] = 1;
			}
		}
		puts(check() && check() ? "1" : "0");
	}
}
