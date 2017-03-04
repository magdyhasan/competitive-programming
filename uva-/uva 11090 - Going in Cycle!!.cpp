#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

struct Node{
	int u, v;
	double co;
} edge[100500];

int n, m;
double d[55];

const double EPS = 1e-8;

bool isNegativeCycle(double mi){
	for (int i = 0; i < m; i++) edge[i].co -= mi;
	for (int i = 0; i <= n; i++) d[i] = -12345678.;
	bool cyc = 0;
	int u, v;
	double cost;
	for (int step = 1; step <= n; step++) // go n-1 steps and in the n steps if there's a shortest path it mean there's a positive cycle
		for (int i = 0; i < m; i++) {
			u = edge[i].u;
			v = edge[i].v;
			cost = edge[i].co;
			if (d[v] > d[u] + cost) {
				if (step == n) {
					cyc = true;
					break;
				}
				d[v] = d[u] + cost;
			}
		}
	for (int i = 0; i < m; i++) edge[i].co += mi;
	return cyc;
}

int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++){
		printf("Case #%d: ", tc);
		scanf("%d%d", &n, &m);
		int u, v, c;
		for (int i = 0; i < m; i++){
			scanf("%d%d%d", &u, &v, &c);
			edge[i] = { u, v, double(c) };
		}
		double l = 0, r = 123456789999.;
		for (int st = 0; st < 500; st++){
			double m = (l + r) / 2.;
			if (isNegativeCycle(m)) r = m;
			else l = m;
		}
		if (fabs(l - 123456789999.) < EPS) puts("No cycle found.");
		else printf("%.2lf\n", l);
	}
}
