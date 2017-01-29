#include<stdlib.h>
#include<stdio.h>
using namespace std;

struct edge{
	int U, V, COST;
	edge() {}
	edge(int a, int b, int c) :U(a), V(b), COST(c) {}
};

edge edges[2050];
int d[1050];
int n, m, u, v, cost;

void bellman_ford(){
	for (int i = 0; i <= n; i++) // initialize distance with infinite
		d[i] = (1 << 30);
	d[0] = 0; 
	for (int step = 1; step <= n; step++) // go n-1 steps and in the n steps if there's a shortest path it mean there's a negative cycle
		for (int i = 0; i < m; i++) {
			u = edges[i].U;
			v = edges[i].V;
			cost = edges[i].COST;
			if (d[u] != (1 << 30) && d[v] > d[u] + cost) {
				if (step == n) {
					puts("possible");
					return;
				}
				d[v] = d[u] + cost;
			}
		}
	puts("not possible");
	return;
}

int main(){
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++)
			scanf("%d%d%d", &edges[i].U, &edges[i].V, &edges[i].COST); // read al edges
		bellman_ford();
	}
}
