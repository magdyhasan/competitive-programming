#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<utility>
using namespace std;

typedef pair<int, int> edge;
#define mp(a,b) make_pair(a,b)

int di[1005];
bool vis[1005];

edge edges[10500];

int n, energy[1005], nuOfadj, to, m;

bool out(int u){
	if (u == n)
		return 1;
	vis[u] = 1;
	for (int i = 0; i < m; i++) {
		edge v = edges[i];
		if (v.first == u && vis[v.second] == false && out(v.second))
			return 1;
	}
	return 0;
}


bool cycle(){
	for (int i = 0; i < m; i++) {
		edge u = edges[i]; // if there's a cycle on this edge and this cycle can reach the out
		if (di[u.first] > 0 && di[u.first] + energy[u.second] > di[u.second] && out(u.first))
			return 1;
	}
	return 0;
}

int main(){
	while (scanf("%lld",&n)) {
		if (n == -1)
			break;
		memset(vis, 0, sizeof(vis));
		m = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", energy + i, &nuOfadj);
			for (int j = 0; j < nuOfadj; j++)
				scanf("%d", &to), edges[m++] = { i, to }; // read all edges
		}
		di[1] = 100;
		for (int j = 2; j <= n; j++) // initialize
			di[j] = -(1 << 29);
		for (int k = 0; k < n - 1; k++) // bellman-ford
			for (int i = 0; i < m; i++) {
				edge u = edges[i];
				if (di[u.first] > 0)
					di[u.second] = max(di[u.second], di[u.first] + energy[u.second]);
			}

		if (di[n] > 0 || cycle()) // if there's a path to n with energy > 0 || there's a positive cycle
			puts("winnable");
		else
			puts("hopeless");
	}
}
