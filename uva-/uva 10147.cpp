#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;

struct edge{
	int to, from, cost;
	bool operator < (const edge &a) const {
		return cost < a.cost;
	}
};


int n, m, nuOfEdges, to1, from1;
int x[800], y[800], p[800], ra[800];
edge edges[650000];

void init(){
	nuOfEdges = 0;
	for (int i = 0; i <= n; i++)
		p[i] = i, ra[i] = 1;
}

int par(int u){
	return (u == p[u]) ? u : p[u] = par(p[u]);
}

bool link(int u, int v){ // disjoint-set
	u = par(u);
	v = par(v);
	if (u != v) {
		if (ra[u] > ra[v])	swap(u, v);
		p[u] = v;
		if (ra[u] == ra[v])	ra[v]++;
	}
	return u != v;
}

int distance(int x1, int y1, int x2, int y2){
	int dx = x2 - x1;
	int dy = y2 - y1;
	return dx*dx + dy*dy;
}

int main(){
    freopen("uva.txt","rt",stdin);
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		init();
		for (int i = 1; i <= n; i++)
			scanf("%d%d", x + i, y + i);
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				edges[nuOfEdges++] = edge{ i, j, distance(x[i], y[i], x[j], y[j]) }; // make all possilbe roads
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &to1, &from1);
			link(to1, from1); // add already exist roads to the union
		}
		sort(edges, edges + nuOfEdges); // sort roads with lesser lenght first
		bool f = 0;
		for (int i = 0; i < nuOfEdges; i++)
			if (link(edges[i].from, edges[i].to)) {	 // if this roads have to be built 
				f = 1;
				printf("%d %d\n", edges[i].from, edges[i].to);
			}
		if (f == false)
			puts("No new highways need");
		if (tc)
			puts("");
	}
}
