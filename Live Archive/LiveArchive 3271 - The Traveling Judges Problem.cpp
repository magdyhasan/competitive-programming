/*
	since number of nodes < 20 we can try all subset of nodes

	if we have subset of nodes we can build MST of this subset and find it's cost, but this subset
	of nodes has to contain all nodes of our judges and our destination so this MST will always has solution

	now find MST that minimize total distance and has fewest number of nodes

	after we have such MST we, we know between all nodes there's only one path, so just construct all paths in MST with simple BFS

	and now build answer given info about paths

*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 300500;
typedef pair<int, int> pii;


int n, m, ta, nj;
vector<int> adj[24], tadj[24];
int js[24], p[24], vis[24], nxt[24];

int par(int x){
	return (p[x] == x) ? x : p[x] = par(p[x]);
}

struct edge{
	int u, v, c;
	edge(int a = 0, int b = 0, int c = 0) :u(a), v(b), c(c) {}
	bool operator < (const edge & other){
		if (c != other.c) return c < other.c;
		return u < other.u;
	}
};


int main(){
    freopen("uva.txt","rt",stdin);
	int tc = 0;
	while (scanf("%d", &n)){
		if (n == -1) break;
		scanf("%d%d", &ta, &m); ta--;
		vector<edge> ed;
		for (int i = 0; i < m; i++){
			int u, v, c; scanf("%d%d%d", &u, &v, &c);
			ed.push_back({ u - 1, v - 1, c });
		}
		scanf("%d", &nj);
		int allmsk = 1 << ta;
		for (int i = 0; i < nj; i++){
			scanf("%d", js + i); js[i]--;
			allmsk |= 1 << js[i];
		}
		sort(ed.begin(), ed.end());
		int co = 123456789, bno = n;
		for (int nmsk = 0; nmsk < 1<<n; nmsk++) {
			if ((nmsk&allmsk) != allmsk) continue;
			int no = 0;
			for (int i = 0; i < 24; i++) {
				tadj[i].clear(), p[i] = i;
				no += (nmsk&(1 << i))?1:0;
			}
			int curco = 0, nf = no;
			for (auto i : ed) if ((nmsk&(1<<i.u)) && (nmsk&(1<<i.v)))  {
				int u = i.u, v = i.v;
				u = par(u); v = par(v);
				if (u != v){
					curco += i.c;
					p[v] = u;
					nf--;
					tadj[i.u].push_back(i.v);
					tadj[i.v].push_back(i.u);
				}
			}
			if (nf == 1 && (curco < co || (curco == co && no < bno))){
				co = curco;
				bno = no;
				for (int i = 0; i < 24; i++) adj[i] = tadj[i];
			}
		}
		memset(vis, 0, sizeof(vis));
		queue<int> q; q.push(ta);
		vis[ta] = 1;
		while (!q.empty()){
			int u = q.front(); q.pop();
			for (int v : adj[u]) if (!vis[v]){
				vis[v] = 1; q.push(v); nxt[v] = u;
			}
		}
		printf("Case %d: distance = %d\n", ++tc, co);
		for (int i = 0; i < nj; i++){
			printf("   %d", js[i] + 1);
			int x = nxt[js[i]];
			while (x != ta)	{
				printf("-%d", x + 1);
				x = nxt[x];
			}
			printf("-%d\n", ta + 1);
		}
		puts("");
	}
}
