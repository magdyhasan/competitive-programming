/*
in MST, edges between all pairs are minimum, so our answer is just maximum of path in MST

build MST, then let's build sparse table for finding k-th parent and maximum edge in path to k-th parent

now we can easily answer queries using this 2 tables, by finding lca
*/
#include <bits/stdc++.h>	
using namespace std;


#define all(v)           ((v).begin()), ((v).end())
#define sz size()
#define clr(v,d)         memset(v,d,sizeof(v))
#define lp(i, n)         for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define sci(a)	scanf("%d",&a)
#define scll(a)	scanf("%lld",&a)
#define scii(a, b)	scanf("%d%d",&a, &b)
#define pri(a)	printf("%d\n",a)
#define prll(a)	printf("%lld\n",a)


const int maxn = 300500;

typedef long long ll;

typedef pair<int, int> pii;

int n, m;
vector<pii> adj[maxn];

int pa[maxn];

void init(int n){
	iota(pa, pa + n + 1, 0);
}

int getpar(int x){
	return (x == pa[x]) ? x : pa[x] = getpar(pa[x]);
}

bool merge(int u, int v){
	u = getpar(u), v = getpar(v);
	if (u != v){
		pa[v] = u;
		return 1;
	}
	return 0;
}

struct edge{
	int u, v, c;
	edge(int a = 0, int b = 0, int d = 0) : u(a), v(b), c(d) {}
	bool operator < (const edge &ot) const {
		return c < ot.c;
	}
} ed[maxn];

const int L = 19;

int h[maxn], par[maxn][L];
int mx[maxn][L];

void dfs(int u, int p = -1){// build sparse table with additional max on path
	h[u] = (~p ? h[p] + 1 : 0);
	par[u][0] = p;
	for (int i = 1; i < L&& par[u][i - 1] != -1; i++){
		par[u][i] = par[par[u][i - 1]][i - 1];
		mx[u][i] = max(mx[u][i - 1], mx[par[u][i - 1]][i - 1]);
	}
	for (auto v : adj[u]) if (v.first - p){
		mx[v.first][0] = v.second;
		dfs(v.first, u);
	}
}

int lca(int u, int v){
	if (h[v] > h[u]) swap(u, v);
	for (int i = L - 1; i >= 0; i--) if (h[u] - (1 << i) >= h[v])
		u = par[u][i];
	if (u == v) return u;
	for (int i = L - 1; i >= 0; i--) if (par[u][i] != -1 && par[u][i] != par[v][i])
		u = par[u][i], v = par[v][i];
	return par[u][0];
}

int get(int u, int v){// fiind max edge on path from u to v
	int ret = 0;
	for (int i = L - 1; i >= 0; i--) if (h[u] - (1 << i) >= h[v]){
		ret = max(ret, mx[u][i]);
		u = par[u][i];
	}
	return ret;
}



int main() {
	//freopen("in.in", "r", stdin);	
	bool tes = 0;
	while (scii(n, m) == 2){
		if (tes) puts("");
		tes = 1;
		int u, v, c;
		lp(i, n + 1) adj[i].clear();
		lp(i, m){
			scii(ed[i].u, ed[i].v);
			sci(ed[i].c);
		}
		sort(ed, ed + m);
		init(n);
		lp(i, m){// build MST
			if (merge(ed[i].u, ed[i].v)){
				adj[ed[i].u].push_back({ ed[i].v, ed[i].c });
				adj[ed[i].v].push_back({ ed[i].u, ed[i].c });
			}
		}
		clr(par, -1);
		dfs(1);// build sparse table
		int qs; sci(qs);
		int si, ti;
		lp(i, qs){
			scii(si, ti);
			int lc = lca(si, ti);
			pri(max(get(si, lc), get(ti, lc)));
		}
	}
}