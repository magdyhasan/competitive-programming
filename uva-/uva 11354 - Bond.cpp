/*
	if we had only one query, we can use BS, to fix maximum edge on graph and build graph with this constraint
	and see if 2 nodes in same component using DSU

	because we have many queries this standard parallel BS
	where when building our graph, we do check for BS of all quries on this build
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

struct node{
	int s, t, i, lo, hi;
	node(int a = 0, int b = 0, int c = 0, int d = 0, int e = 0) : s(a), t(b), i(c), lo(d), hi(e) {}
} q[maxn];

struct edge{
	int u, v, c;
	edge(int a = 0, int b = 0, int d = 0) : u(a), v(b), c(d) {}
	bool operator < (const edge &ot) const {
		return c < ot.c;
	}
} ed[maxn];


int pa[maxn];

void init(int n){
	iota(pa, pa + n + 1, 0);
}

int par(int x){
	return (x == pa[x]) ? x : pa[x] = par(pa[x]);
}

void merge(int u, int v){
	u = par(u), v = par(v);
	if (u != v){
		pa[v] = u;
	}
}

vector<int> toCheck[maxn];

int main() {
	freopen("in.in", "r", stdin);
	bool tes = 0;
	while (scii(n, m) == 2){
		if (tes) puts("");
		tes = 1;
		int u, v, c;
		lp(i, m){
			scii(ed[i].u, ed[i].v);
			sci(ed[i].c);
		}
		sort(ed, ed + m);
		int qs; sci(qs);
		int si, ti;
		lp(i, qs){
			scii(q[i].s, q[i].t);
			q[i].i = i;
			q[i].lo = 0;
			q[i].hi = m - 1;
		}
		bool ch = 1;
		while (ch){// parallel BS
			ch = 0;
			for (int i = 0; i < m; i++) toCheck[i].clear();
			for (int i = 0; i < qs; i++) {
				if (q[i].lo != q[i].hi)
					toCheck[(q[i].lo + q[i].hi) >> 1].push_back(i);
			}
			init(n);
			for (int i = 0; i < m; i++){
				merge(ed[i].u, ed[i].v);
				for (auto j : toCheck[i]){
					ch = 1;
					if (par(q[j].s) == par(q[j].t)) q[j].hi = i;
					else q[j].lo = i + 1;
				}
			}
		}
		lp(i, qs) pri(ed[q[i].lo].c);
	}
}