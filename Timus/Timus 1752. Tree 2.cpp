#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

const int maxn = 200500, L = 19;

int h[maxn], par[maxn][20];
vector<int> adj[maxn];



int n, q;

void dfs(int u, int p = -1){
	h[u] = (~p ? h[p] + 1 : 0);
	par[u][0] = p;
	for (int i = 1; i < L; i++)
		par[u][i] = par[par[u][i - 1]][i - 1];
	for (int v : adj[u]) if (v - p)
		dfs(v, u);
}

int lca(int u, int v){
	if (h[v] > h[u]) swap(u, v);
	for (int i = L; i >= 0; i--) if (h[u] - (1 << i) >= h[v])
		u = par[u][i];
	if (u == v) return u;
	for (int i = L; i >= 0; i--) if (par[u][i] != -1 && par[u][i] != par[v][i])
		u = par[u][i], v = par[v][i];
	return par[u][0];
}

int umx, vmx;
int d[maxn];
void BFS(int s, bool one){
	queue<int> q;
	q.push(s);
	for (int i = 0; i <= n; i++)
		d[i] = (1 << 25);
	d[s] = 0;
	while (!q.empty()){ // normal BFS
		int u = q.front();
		q.pop();
		for (auto v : adj[u])
			if (d[v] > d[u] + 1){
				d[v] = d[u] + 1;
				q.push(v);
			}
	}
	int mx = -1, mxi;
	for (int i = 0; i <= n; i++) // find max path
		if (d[i] > mx && d[i] != (1 << 25))
			mx = d[i], mxi = i;
	if (!one) // if one == 0 then i first founded the farthest node from any random node
		umx = mxi, BFS(mxi, 1);
	else // now how from the farthest node we found we now find the farthest node from this node
		vmx = mxi; // this is the longest path
}

int diLCA(int u, int v){
	return h[u] + h[v] - 2 * h[lca(u, v)];
}

int getKthParent(int u, int k){
	for (int i = L; i >= 0; i--)
		if ((1 << i) <= k)
			u = par[u][i], k -= (1 << i);
	return u;
}

int main(){
    freopen("uva.txt","rt",stdin);
	scanf("%d%d", &n, &q);
	int u, v, du;
	for (int i = 1; i < n; i++) 
		scanf("%d%d", &u, &v), adj[u].push_back(v), adj[v].push_back(u);
	dfs(1);
	BFS(1, 0);
	while (q--)	{
		scanf("%d%d", &u, &du);
		int t1 = diLCA(u, umx), t2 = diLCA(u, vmx);
		int nmx = (diLCA(u, umx) > diLCA(u, vmx) ? umx : vmx);
		if (diLCA(u, nmx) < du) puts("0");
		else{
			int unmxLCA = lca(u, nmx);
			if (diLCA(u, unmxLCA) >= du) printf("%d\n", getKthParent(u, du));
			else printf("%d\n", getKthParent(nmx, diLCA(nmx, u) - du));
		}
	}
}
