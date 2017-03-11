/*
	to check if valid tree:
	first check symmetry of all nodes and that all nodes distance must be postitive
	get all edges from the matrix and build a spanning tree with kruskal algorithm
	after building tree, calculate all nodes to nodes distance ( O(n^2) by BFS/DFS, O(nlogn) by using LCA )
	then just check if this tree distance match the given ones

	We can prove this tree we built must be same one if exist in matrix because we used all distances on it.
*/


#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define all(v)           ((v).begin()), ((v).end())
#define sz size()
#define clr(v,d)         memset(v,d,sizeof(v))
#define rep(i, v)        for(int i=0;i<(v).sz;++i)
#define lp(i, n)         for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define sci(a)	scanf("%d",&a)
#define scii(a, b)	scanf("%d%d",&a, &b)
#define pri(a)	printf("%d\n",a)
#define prii(a, b)	printf("%d %d\n",a, b)
#define DB1(a)          std::cout<<#a<<"="<<(a)<<endl
#define DB2(a,b)        std::cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<endl
#define DB3(a,b,c)      std::cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<endl
#define DB4(a,b,c,d)    std::cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<endl
#define DB5(a,b,c,d,e)  std::cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<endl
typedef pair<int, int> pii;
typedef long long ll;
const ll  inf = 1000000000000000000LL;
const double EPS = 1e-9;
const ll mod = 1000000007ll;
#define PI acos(-1)

const int maxn = 500500;

int n;
int a[2005][2005];

int p[2005];

int par(int x){
	return (x == p[x]) ? x : p[x] = par(p[x]);
}

struct Node{
	int u, v, c;
	bool operator < (const Node& a) const {
		return c < a.c;
	}
} edge[5000500];

ll d[2005][2005];
vector<pii> adj[2005];

bool vis[2005];

void BFS(int so){
	d[so][so] = 0;
	queue<int> q;	q.push(so);
	memset(vis, 0, sizeof(vis));
	vis[so] = 1;
	while (!q.empty()){
		int u = q.front(); q.pop();
		for (pii ne : adj[u]) if (!vis[ne.fi]){
			q.push(ne.fi);
			d[so][ne.first] = d[so][u] + ne.second, d[ne.first][so] = d[so][ne.first];
			vis[ne.first] = 1;
		}
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("CF.in", "rt", stdin);
#endif	
	sci(n);
	lp(i, n) lp(j, n) sci(a[i][j]);
	bool no = false;
	lp(i, n) lp(j, n){
		if (i == j) no |= a[i][j];
		else no |= a[i][j] == 0;
		no |= a[i][j] != a[j][i];
	}
	if (no){
		puts("NO"); return 0;
	}
	int e = 0;
	lp(i, n) lpi(j, i + 1, n) edge[e++] = { i, j, a[i][j] };
	sort(edge, edge + e);
	lp(i, n) p[i] = i;
	memset(d, -1, sizeof(d));
	lp(ie, e){
		int u = edge[ie].u, v = edge[ie].v, co = edge[ie].c;
		if (par(u) != par(v)){
			p[par(v)] = par(u);
			adj[u].push_back({ v, co });
			adj[v].push_back({ u, co });
		}
	}
	for (int i = 0; i < n; i++) BFS(i);
	for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++)
		if (d[i][j] != a[i][j]){
		puts("NO");	return 0;
		}
	puts("YES");
}