#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int d[1005][1005];


int n, m, ba;


int is, js, it, jt;

bool isValid(int i, int j){
	return (i >= 0 && j >= 0 && i < n && j < m);
}

int di[] = { 1, -1, 0, 0 };
int dj[] = { 0, 0, 1, -1 };

int dd, td;
int vis[1005][1005];

bool can(int dmx){
	queue<int> q;
	q.push(is); q.push(js);
	memset(vis, -1, sizeof(vis));
	if (d[is][js] < dmx) return 0;
	vis[is][js] = 0;
	while (!q.empty()){
		int i = q.front(); q.pop();
		int j = q.front(); q.pop();
		if (i == it && j == jt) {
			td = vis[i][j];
			return 1;
		}
		for (int k = 0; k < 4; k++){
			int ni = i + di[k];
			int nj = j + dj[k];
			if (!isValid(ni, nj) || d[ni][nj] < dmx || vis[ni][nj] != -1) continue;
			q.push(ni); q.push(nj);
			vis[ni][nj] = vis[i][j] + 1;
		}
	}
	return 0;
}

int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	while (T--){
		memset(d, -1, sizeof(d));
		scanf("%d%d%d", &ba, &n, &m);
		scanf("%d%d%d%d", &is, &js, &it, &jt);
		int x, y;
		queue<int> q;
		for (int i = 0; i < ba; i++){
			scanf("%d%d", &x, &y);
			q.push(x); q.push(y);
			d[x][y] = 0;
		}
		while (!q.empty()){
			int i = q.front(); q.pop();
			int j = q.front(); q.pop();
			for (int k = 0; k < 4; k++){
				int ni = i + di[k];
				int nj = j + dj[k];
				if (!isValid(ni, nj) || d[ni][nj] != -1) continue;
				q.push(ni); q.push(nj);
				d[ni][nj] = d[i][j] + 1;
			}
		}
		int l = 0, r = n + m + 50, ans;
		while (l <= r){
			int mid = (l + r + 1) / 2;
			if (can(mid)) ans = mid, l = mid + 1, dd = td;
			else r = mid - 1;
		}
		printf("%d %d\n", ans, dd);
	}
}

