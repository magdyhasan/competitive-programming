/*
	first let's root the tree at vertex 1 and calucate answer for this rooted tree
	also calcuate sv[u], that repesent sum of all a[v], such that v is children of u, when rooted at vertex 1

	now think about what happens when change root from 1 to some adjacent vertex, using edge(u,v)
	4 things will happen:

	-decraase our answer by all a[v] in this subtree, because root is now closer to this subtree
	-because tree is rooted at v now, sv[u] decrases by sv[v], because u doesn't have v as it's children anymore
	-now we moved away from new vertex u children, so we add all a[u] once again
	-now vertex v is root, so it has u as children

	using this, we can obatin answer for all nodes
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


const int maxn = 2000500;

typedef long long ll;

int n;
int a[maxn];
ll sv[maxn];
vector<int> adj[maxn];

ll ret, cur;


void dfs(int u, int p = -1, int h = 0){
	sv[u] = 1LL * a[u];
	cur += sv[u] * h;
	for (int v : adj[u]) if (v != p){
		dfs(v, u, h + 1);
		sv[u] += sv[v];
	}
}

void rec(int u, int p = -1){
	ret = max(ret, cur);
	for (int v : adj[u]) if (v != p){

		cur -= sv[v];// decraase our answer by all a[v] in this subtree
		sv[u] -= sv[v];//because tree is rooted at v now, sv[u] decrases by sv[v], because u doesn't have v as it's children anymore
		cur += sv[u];//now we moved away from new vertex u children, so we add all a[u] once again
		sv[v] += sv[u];// now vertex v is root, so it has u as children

		rec(v, u);
		//undo our previous operations
		sv[v] -= sv[u];
		cur -= sv[u];
		sv[u] += sv[v];
		cur += sv[v];
	}
}


int main() {
	//freopen("in.in", "r", stdin);	
	sci(n);
	lp(i, n) sci(a[i + 1]);
	lp(i, n - 1){
		int a, b; scii(a, b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	rec(1);
	prll(ret);
}