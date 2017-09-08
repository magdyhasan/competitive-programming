#include<bits/stdc++.h>
using namespace std;

struct node{
	int a, b, c, p, r;
	node(int _a=0,int _b=0,int _c=0,int _p=0,int _r=0):a(_a), b(_b), c(_c), p(_p), r(_r) {}
} edge[100];

struct no{
	int co, u, msk;
	no(int a, int b, int c) : co(a), u(b), msk(c){}
	bool operator < (const no & a) const{
		return co < a.co;
	}
};

int d[13][(1 << 13)];

int main(){
    freopen("uva.txt","rt",stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++){
		scanf("%d%d%d%d%d", &edge[i].a, &edge[i].b, &edge[i].c, &edge[i].p, &edge[i].r);
		edge[i].p = min(edge[i].p, edge[i].r);
	}
	for (int i = 0; i < 13; i++) for (int j = 0; j < (1 << 13); j++) d[i][j] = 2147483647;
	d[1][0] = 0;
	priority_queue<no, vector<no>> q; 
	q.push({ 0, 1, 2 });
	while (!q.empty()){
		no u = q.top(); q.pop();
		//moving to another node 
		for (int i = 0; i < m; i++) if (edge[i].a == u.u){
			int cost = u.co + ((u.msk&(1 << edge[i].c)) ? edge[i].p : edge[i].r);
			int nmsk = u.msk | (1 << edge[i].b);
			if (d[edge[i].b][nmsk] > cost)
				q.push({ cost, edge[i].b, nmsk }), d[edge[i].b][nmsk] = cost;
		}
	}
	int ret = -1;
	for (int i = 0; i < (1 << (n + 1)); i++) if (d[n][i] != 2147483647 && (ret == -1 || ret > d[n][i]))
		ret = d[n][i]; 
	if (ret == -1) puts("impossible");
	else printf("%d", ret);
}
