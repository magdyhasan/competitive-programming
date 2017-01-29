#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;

struct Edge{
	int d, u, v;
	Edge() {}
	Edge(int a, int b, int c) : d(a), u(b), v(c) {}
	bool operator < (const Edge &a)const{
		return d < a.d;
	}
};

int x[600], y[600];
int p[600], c_rank[600], forests;
Edge edges[250005];
int S, P;

void init(){ // initialize 
	for (int i = 0; i < P+50; i++)
		p[i] = i, c_rank[i] = 1;
	forests = P;
}

int par(int _x){ // find pare of compnonent of x
	return (p[_x] == _x) ? _x : p[_x] = par(p[_x]);
}


bool link(int _x, int y){ // make x,y in same compnonent
	_x = par(_x);
	y = par(y);
	if (_x != y) {
		if (c_rank[_x] > c_rank[y])
			swap(_x, y);
		p[_x] = y;
		if (c_rank[_x] == c_rank[y])	c_rank[y]++;
		forests--;
	}
	return _x != y;
}




int dist(int x1, int y1, int x2, int y2){ // calculate distance between 2 points
	int dx = x2 - x1;
	int dy = y2 - y1;
	return (dx*dx + dy*dy);
}

int main(){
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &S, &P);
		init();
		int edges_nu = 0;
		for (int i = 0; i < P; i++)
			scanf("%d%d", x + i, y + i);
		for (int i = 0; i < P; i++)
			for (int j = i + 1; j < P; j++) 
				edges[edges_nu++] = { dist(x[i], y[i], x[j], y[j]), i, j }; // get distance between all pairs
		sort(edges, edges + edges_nu); // sort edges according to distance
		int take_edge = 0;
		int ans = 0;

		while (forests > S ){ // build compnonents untill there's only number of forests == number of satelliet to connect this forests with
			if (link(edges[take_edge].u, edges[take_edge].v))  // if we need to take this edge
				ans = edges[take_edge].d;
			take_edge++;
		}
		printf("%.2lf\n", sqrt(ans*1.0));
	}
}
