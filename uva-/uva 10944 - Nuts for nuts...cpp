#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;

int n, m;

struct state{
	int i, j, msk;
	state(int a = 0, int b = 0, int c = 0) :i(a), j(b), msk(c){}
	bool isValid(){
		return (i >= 0 && j >= 0 && i < n && j < m);
	}
};

int d[20][20][(1 << 16)];
char gr[20][20];

int dx[] = { 0, 0, -1, -1, -1, 1, 1, 1 },
	dy[] = { 1, -1, 0, 1, -1, -1, 0, 1 };

int main(){
    freopen("uva.txt","rt",stdin);
	while (scanf("%d%d", &n, &m) == 2){
		map<int, int> mn;
		int cnt = 0;
		for (int i = 0; i < n; i++) scanf("%s", gr[i]);
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (gr[i][j] == '#')
			mn[i * 20 + j] = cnt++;
		int si, sj;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (gr[i][j] == 'L')
			si = i, sj = j;
		memset(d, 63, sizeof(d));
		d[si][sj][0] = 0;
		queue<state> q;	q.push({ si, sj, 0 });
		while (!q.empty()){
			state u = q.front(); q.pop();
			for (int k = 0; k < 8; k++){
				state v = { u.i + dx[k], u.j + dy[k], u.msk };
				if (!v.isValid()) continue;
				if (gr[v.i][v.j] == '#') v.msk |= (1 << mn[v.i * 20 + v.j]);
				if (d[v.i][v.j][v.msk] > d[u.i][u.j][u.msk] + 1)
					d[v.i][v.j][v.msk] = d[u.i][u.j][u.msk] + 1, q.push(v);
			}
		}
		printf("%d\n", d[si][sj][(1 << cnt)-1]);
	}
}
