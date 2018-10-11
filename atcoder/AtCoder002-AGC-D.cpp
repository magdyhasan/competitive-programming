/*
	first notice that if we have number of queries smaller
	we can do something like this:
	for each query, let's search for the max edge added on the graph 
	after fixing edge with DSU we can calcuate how many vertices u,v can reach easily 

	but this will time out when q <= 1e5 and m <= 1e5

	we can solve it with parallel binary search
	main idea, is for each query we calcuating same check function with same edge multiple times
	so instead of doing binary search for query and then in binary search building DSU
	we will run all binary search for all queiries in same time, at most in log(Q)
	so we will loop multiple times and while building DSU over edges
	if we are at i-th edge, we check if there's some query that needed to do BS on this i-th edge
	and if so we update it's result
*/
#include<bits/stdc++.h>
using namespace std;

#define all(v)           ((v).begin()), ((v).end())
#define sz size()
#define clr(v,d)         memset(v,d,sizeof(v))
#define lp(i, n)         for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define sci(a)	scanf("%d",&a)
#define scii(a, b)	scanf("%d%d",&a, &b)
#define pri(a)	printf("%d\n",a)

const int maxn = 300500;

struct edge{
	int u, v;
} ed[300500];

struct no{
	int u, v, x, lo, hi;
} q[maxn];


int pa[maxn], ra[maxn];

void init(int n){
	iota(pa, pa + n + 1, 0);
	fill(ra, ra + n + 1, 1);
}

int par(int x){
	return (x == pa[x]) ? x : pa[x] = par(pa[x]);
}

void merge(int u, int v){
	u = par(u), v = par(v);
	if (u != v){
		pa[v] = u;
		ra[u] += ra[v];
	}
}

vector<int> toCheck[maxn];



int main(){
    freopen("uva.txt","rt",stdin);
	int n, m;
	scanf("%d %d", &n, &m);
	iota(pa, pa + n + 1, 0);
	for (int i = 0; i < m; i++){
		scanf("%d%d", &ed[i].u, &ed[i].v);
		ed[i].u--; ed[i].v--;
	}
	int qs; scanf("%d", &qs);
	for (int i = 0; i < qs; i++) {
		scanf("%d%d%d", &q[i].u, &q[i].v, &q[i].x);
		q[i].u--;
		q[i].v--;
		q[i].lo = 0, q[i].hi = m - 1;
	}
	bool ch = 1;
	while (ch){
		ch = 0;
		for (int i = 0; i < m; i++) toCheck[i].clear();
		for (int i = 0; i < qs; i++) {
			// if there's some query that hasn't finish BS
			if (q[i].lo != q[i].hi){
				// add it to needed BS of size (q[i].lo + q[i].hi) >> 1
				toCheck[(q[i].lo + q[i].hi) >> 1].push_back(i);
			}
		}
		// initialise DSU
		init(n);
		for (int i = 0; i < m; i++){
			merge(ed[i].u, ed[i].v);
			// iterate over the queries need to do BS on i-th edge
			for (auto j : toCheck[i]){
				ch = 1;
				int u = par(q[j].u), v = par(q[j].v);
				int tot = (u == v) ? ra[u] : ra[v] + ra[u];
				//update BS for this query
				if (q[j].x <= tot) q[j].hi = i;
				else q[j].lo = i + 1;
			}
		}
	}
	lp(i, qs) pri(q[i].lo+1);
}
