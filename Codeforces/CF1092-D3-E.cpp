/*
	for each tree in the forest, find the one with maximum diameter
	now make this as center for mergeing all other trees, and clearly this optimal

	but which nodes to merge on ?
	it's always better to merge on center of tree, since it'll always make diamter less

	so just find centers of all trees of the forest and connect them

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

int n, m;
vector<int> adj[maxn];



int d[2][maxn];

int BFS(int s, int i){
	queue<int> q;
	q.push(s);
	memset(d[i], 63, sizeof d[i]);
	d[i][s] = 0;
	int la = s;// maximum distanc node
	while (!q.empty()){ // normal BFS
		int u = q.front();
		q.pop();
		for (auto v : adj[u]){
			if (d[i][v] > d[i][u] + 1){
				d[i][v] = d[i][u] + 1;
				la = v;
				q.push(v);
			}
		}
	}
	return la;
}
bool vis[maxn];



vector<int> cur;

void dfs(int u, int p = -1){
	vis[u] = 1;
	cur.push_back(u);
	for (int v : adj[u]) if (!vis[v])
		dfs(v, u);
}


int main() {
	//freopen("in.in", "r", stdin);	
	sci(n); sci(m);
	lp(i, m){
		int a, b; scii(a, b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	set<pair<int, int>> comps;
	lpi(i, 1, n + 1) if (!vis[i]){// each component
		cur.clear();
		dfs(i);
		int u = BFS(i, 1);//2-way BFS to find diameter and center
		int v = BFS(u, 0);
		BFS(v, 1);
		int ds = d[0][v], cen;
		for (int no : cur) if (d[0][no] == ds / 2 && d[1][no] == ds - ds / 2)
			cen = no;
		comps.insert({ -ds, cen });
	}
	vector<pair<int, int>> ed;
	int mxd = comps.begin()->second;
	comps.erase(comps.begin());
	for (auto it : comps){
		ed.push_back({ mxd, it.second });
		adj[mxd].push_back(it.second);
		adj[it.second].push_back(mxd);
	}
	int u = BFS(BFS(mxd, 1), 0);
	pri(d[0][u]);
	for (auto i : ed) printf("%d %d\n", i.first, i.second);
}