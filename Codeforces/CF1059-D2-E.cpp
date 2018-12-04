/*
	Let's think from leafs to root

	if from some leaf we can make longer path to a node, it's better to take this path
	since we are covering more nodes

	so for every node from bottom, we either make it start of path, or it's included in maximum path from one of it's children

	so now we need to find for each node, highest node it can reach in tree with constraints

	this can be done in simple DFS with sparse table
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

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

const int maxn = 300500;
const int L = 19;

int p[maxn][L];
ll w[maxn];
ll su[maxn];
int up[maxn], dep[maxn];
int n, Le;

ll S;
vector<int> adj[maxn];

void pre(int u){
	su[u] += w[u];
	for (int i = 1; i < L && p[u][i - 1] > 1; i++)
		p[u][i] = p[p[u][i - 1]][i - 1];
	int curl = Le - 1;
	up[u] = u;
	for (int l = L - 1; l >= 0; l--) if (curl >= (1 << l) && p[up[u]][l] && su[u] - su[p[up[u]][l]] + w[p[up[u]][l]] <= S){
			curl -= 1 << l;
			up[u] = p[up[u]][l];
	}
	for (int v : adj[u]){
		su[v] += su[u];
		dep[v] = dep[u] + 1;
		pre(v);
	}
}

int ret;

int solve(int u){
	int mx = -1;
	for (int v : adj[u]){
		int td = solve(v);
		if (td == v) continue;
		if (mx == -1 || dep[td] < dep[mx])
			mx = td;
	}
	if (mx == -1){
		++ret;
		mx = up[u];
	}
	return mx;
}


int main(){
    freopen("uva.txt","rt",stdin);
	scii(n, Le); scll(S);
	bool f = 0;
	lp(i, n){
		scll(w[i+1]);
		if (w[i + 1] >S) f = 1;
	}
	if (f) { puts("-1"); return 0; }
	lp(i, n - 1){
		sci(p[i + 2][0]);
		adj[p[i + 2][0]].push_back(i+2);
	}
	pre(1);
	solve(1);
	pri(ret);
}
