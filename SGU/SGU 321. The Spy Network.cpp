/*
	notice that it's always better to make edges protected that are close to root 
	because changing edge closer to root will effect many paths of other nodes so it's always better to change it

	so now let's root tree at vertex 1, and find depth for all nodes
	we know if node u is at dep[u] from root then it need at least (dep[u]+1)/2 protected edges in it's path to root
	so for each node from bottom to top, there's 2 cases:
	1- we can go up without changing this edge because we can still make edges in top protected and it's better to delay it
	2- we have to change this edge now or else we will violate our condition

	this can be done by dfs easily
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
#define scii(a, b)	scanf("%d%d",&a, &b)
#define pri(a)	printf("%d\n",a)


const int maxn = 300500;



vector<pair<int, pair<int, int>>> adj[maxn];

char st[30050];
vector<int> ret;

int dfs(int u, int dp = 0){
	int ned = (dp + 1) / 2;
	for (auto v : adj[u]){
		int tned = dfs(v.first, dp + 1);
		tned -= v.second.first;
		if (tned > dp){
			ret.push_back(v.second.second);
			tned--;
		}
		ned = max(ned, tned);
	}
	return ned;
}


int main() {
	int n; sci(n);
	int u, v, c;
	lp(i, n - 1){
		scii(u, v);
		scanf("%s", st);
		c = 1;
		if (st[0] == 'a'){
			c = 0;
			scanf("%s", st);
		}
		adj[v].push_back({ u, { c, i + 1 } });
	}
	dfs(1);
	sort(ret.begin(), ret.end());
	pri(ret.size());
	for (auto i : ret) printf("%d ", i);
}