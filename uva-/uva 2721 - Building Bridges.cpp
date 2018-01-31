/*
	find all connected components

	for each component find all posiible other components that can be connected to ( call this edges )

	now build MST
*/
#include<bits/stdc++.h>
using namespace std;

int n, m;

char g[105][105];
int cn[105][105];
int cc[5005][5005];
int ccnt;

void dfs(int i, int j, int nu){
	if (i < 0 || j < 0 || i >= n || j >= m || g[i][j] != '#' || cn[i][j] != -1) return;
	cn[i][j] = nu;
	for (int dx = -1; dx <= 1; dx++) for (int dy = -1; dy <= 1; dy++)
		if (dx != 0 || dy != 0)
			dfs(i + dx, j + dy, nu);
}
struct edge{
	int i, j, c;
	edge(int a = 0, int b = 0, int d = 0) :i(a), j(b), c(d) {}
	bool operator < (const edge &other){
		if (c != other.c) return c < other.c;
		return i < other.i;
	}
};

int p[10005];
int par(int x){
	return (x == p[x]) ? x : p[x] = par(p[x]);
}

int main(){
    freopen("uva.txt","rt",stdin);
	int tc = 0;
	while (scanf("%d%d", &n, &m) && n){
		if (tc) puts("");
		for (int i = 0; i < n; i++) 
			scanf("%s", g + i);
		memset(cn, -1, sizeof(cn));
		ccnt = 0;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
			if (g[i][j] == '#' && cn[i][j] == -1)
				dfs(i, j, ccnt++);
		memset(cc, 63, sizeof(cc));
		printf("City %d\n", ++tc);
		if (ccnt <= 1) {
			puts("No bridges are needed."); continue;
		}
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++){
			if (g[i][j] == '.') continue;
			for (int di = -1; di <= 1; di++){
				if (di + i < 0 || di + i >= n) continue;
				for (int k = j + 1; k < m; k++) if (g[i + di][k] == '#' && cn[i + di][k] != cn[i][j]){
					cc[cn[i + di][k]][cn[i][j]] = min(cc[cn[i + di][k]][cn[i][j]], k - j - 1);
					cc[cn[i][j]][cn[i + di][k]] = min(cc[cn[i][j]][cn[i + di][k]], k - j - 1);
				}
			}
			for (int dj = -1; dj <= 1; dj++){
				if (dj + j < 0 || dj + j >= m) continue;
				for (int k = i + 1; k < n; k++) if (g[k][j + dj] == '#' && cn[k][j + dj] != cn[i][j]){
					cc[cn[k][j + dj]][cn[i][j]] = min(cc[cn[k][j + dj]][cn[i][j]], k - i - 1);
					cc[cn[i][j]][cn[k][j + dj]] = min(cc[cn[i][j]][cn[k][j + dj]], k - i - 1);
				}
			}
		}
		vector<edge> ed;
		for (int i = 0; i < ccnt; i++) for (int j = i + 1; j < ccnt; j++) if (cc[i][j] != 1061109567)
			ed.push_back({ i, j, cc[i][j] });
		sort(ed.begin(), ed.end());
		int added = 0, cost = 0;
		for (int i = 0; i < ccnt; i++) p[i] = i;
		for (auto i : ed){
			int u = i.i, v = i.j;
			u = par(u), v = par(v);
			if (u != v){
				p[v] = u;
				added++;
				cost += i.c;
			}
		}
		if (added == 0) puts("No bridges are possible.");
		else printf("%d bridge%s of total length %d\n", added, (added==1) ? "":"s", cost);
		if (added + 1 < ccnt) printf("%d disconnected groups\n", ccnt - added);
	}
}
