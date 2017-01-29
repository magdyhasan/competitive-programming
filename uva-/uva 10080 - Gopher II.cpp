#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;

int g[205][205], gt[205];
double gopher_x[105], gopher_y[105], hole_x, hole_y;
int ml[205], mr[205];
bool used[205];
int n, m, s, v;

double dist(double x1, double y1, double x2, double y2){
	double dx = x2 - x1;
	double dy = y2 - y1;
	return sqrt(dx*dx + dy*dy);
}

bool dfs(int u){
	for (int i = 0; i < gt[u]; i++) {
		int ne = g[u][i]; // gobher u can go to hole ne
		if (!used[ne]) { // if he hasn't try to go hole ne yet
			used[ne] = 1;
			if (!mr[ne] || dfs(mr[ne])) { // if hole ne hasn't been assigned to any gopher yet || we can assign the one on the ne to another hole
				mr[ne] = u; // mark hole ne with gobher u
				ml[u] = ne; // mark gobher u with hole ne
				return 1; // we have assigned him a hole successfully
			}
		}
	}
	return 0;// we couldn't assign him to any hole
}

int main(){
	while (scanf("%d%d%d%d",&n,&m,&s,&v) != EOF) {
		memset(gt, 0, sizeof(gt));
		memset(ml, 0, sizeof(ml));
		memset(mr, 0, sizeof(mr));
		for (int i = 1; i <= n; i++)
			scanf("%lf%lf", gopher_x + i, gopher_y + i);
		for (int i = 1; i <= m; i++) {
			scanf("%lf%lf", &hole_x, &hole_y);
			for (int j = 1; j <= n; j++) {
				double i_j = dist(gopher_x[j], gopher_y[j], hole_x, hole_y);
				if (i_j <= s*v) // if gobher j can go to hole i in <= s
					g[j][gt[j]++] = i;
			}
		}
		int matched = 0;
		for (int i = 1; i <= n;i++) // try to match 
			if (!ml[i]) { // if it hasn't been matched to anything yet
				memset(used, 0, sizeof(used));
				if (dfs(i)) // if we could match it
					matched++;
			}
		printf("%d\n", n-matched);
	}
}
