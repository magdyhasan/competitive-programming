#include<stdlib.h>
#include<stdio.h>
#include<queue>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

bool isValid(int x, int y){
	return (x >= 0 && y >= 0 && x < n && y < m);
}

char g[64][64];
int nxt[64][64][4][2];

int di[64 * 64][10500]; // state for bfs ( where we stand in keyboard, current index in message )
char st[10500];

struct node{
	int xy, idx;
	node(int a, int b) : xy(a), idx(b)	{}
};

int main(){
    freopen("uva.txt","rt",stdin);
	while (scanf("%d%d", &n, &m) == 2){
		for (int i = 0; i < n; i++)
			scanf("%s", g[i]);
		// percompute next of each cell
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) for (int k = 0; k < 4; k++){
			nxt[i][j][k][0] = nxt[i][j][k][1] = -1;
			int ni = i, nj = j;
			while (isValid(ni + dx[k], nj + dy[k]) && g[ni][nj] == g[i][j])
				ni += dx[k], nj += dy[k];
			if (g[ni][nj] == g[i][j]) continue;
			nxt[i][j][k][0] = ni;
			nxt[i][j][k][1] = nj;
		}
		// read message to be typed
		scanf("%s", st);
		int ln = strlen(st);
		st[ln] = '*'; st[ln + 1] = '\0';
		ln++;
		// set BFS
		memset(di, 63, sizeof(di));
		di[0][0] = 0;
		queue<node> q;
		q.push({ 0, 0 });
		node u({ 0, 0 });
		while (!q.empty()){
			u = q.front(); q.pop();
			if (u.idx == ln) { // if we typed the whole message
				printf("%d\n", di[u.xy][ln]);
				break;
			}
			int x = u.xy / m, y = u.xy % m; // current position at keybaord
			if (g[x][y] == st[u.idx]) // if this the needed char 
				di[u.xy][u.idx+1] = di[u.xy][u.idx] + 1, q.push({ u.xy, u.idx + 1 });
			else{// try moving to adjacent keys
				for (int k = 0; k < 4; k++) if(nxt[x][y][k][0] != -1) {
					int nx = nxt[x][y][k][0], ny = nxt[x][y][k][1];
					if (di[nx*m + ny][u.idx] > di[u.xy][u.idx] + 1){
						di[nx*m + ny][u.idx] = di[u.xy][u.idx] + 1;
						q.push({ nx*m + ny, u.idx });
					}
				}
			}
		}
	}
}
