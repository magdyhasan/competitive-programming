#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int dx[] = { 1, 1, -1, -1, 2, 2, -2, -2 };
int dy[] = { 2, -2, 2, -2, 1, -1, 1, -1 };

int d[10][10];

bool isValid(int r, int c){
	return (r >= 0 & c >= 0 && r < 8 && c < 8);
}

int BFS(int sr, int sc, int tr, int tc){
	memset(d, -1, sizeof(d));
	d[sr][sc] = 0; // distance to source == 0
	queue<int> q;	
	q.push(sr); q.push(sc);
	while (!q.empty()){
		int r = q.front(); q.pop(); // we are at (r,c)
		int c = q.front(); q.pop();
		if (r == tr && c == tc) return d[r][c];
		for (int k = 0; k < 8; k++){ // try all 8 moves
			int nr = r + dx[k]; // new row
			int nc = c + dy[k]; // new column
			if (!isValid(nr, nc)) continue; // if out of boar
			if (d[nr][nc] == -1) // if we didn't already visit it
				d[nr][nc] = d[r][c] + 1, q.push(nr), q.push(nc);
		}
	}
	return -1;
}

char st1[5], st2[5];

int main(){
    freopen("uva.txt","rt",stdin);
	while (scanf("%s%s", st1, st2) != EOF){
		int mov = BFS(st1[1] - '1', st1[0] - 'a', st2[1] - '1', st2[0] - 'a');
		printf("To get from %s to %s takes %d knight moves.\n", st1, st2, mov);
	}
}
