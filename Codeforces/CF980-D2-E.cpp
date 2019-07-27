/*
 * let's construct n-k nodes with highest value
 * it's always better to add largest node available, even if we'll add many other nodes because of it
 * because 2^i > 2^i-1 + 2^i-2 ....+1
 *
 * so first we always include node n
 * then try maxmimum node without exceeding n-k nodes we adding
 *
 * this can done using LCA
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
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)


const int maxn = 1000500;
typedef long long ll;

const int L = 19;

bool in[maxn];

int h[maxn], par[maxn][L];
vector<int> adj[maxn];

void dfs(int u, int p = -1){
	h[u] = (~p ? h[p] + 1 : 0);
	par[u][0] = p;
	for (int i = 1; i < L&& par[u][i - 1] != -1; i++)
		par[u][i] = par[par[u][i - 1]][i - 1];
	for (int v : adj[u]) if (v - p)
		dfs(v, u);
}

int di(int u){
	int ret = 1;
	for (int i = L - 1; i >= 0; i--) if (h[u] - (1 << i) >= 0 && !in[par[u][i]])
		ret += (1<<i), u = par[u][i];
	return ret;
}



int main() {
	int n,k; scii(n,k);

	lp(i,n-1){
		int u,v; scii(u,v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	in[n] = 1;
	dfs(n);
	int rem = n - k - 1;
	for(int i=n-1;i>0;i--)if(!in[i] && di(i)<=rem){
		int u = i;
		while(!in[u]){
			//pri(u);
			--rem;
			in[u] = 1;
			u = par[u][0];
		}
	//	puts("---");
	}
	for(int i=1;i<=n;i++) if(!in[i])
		printf("%d ",i);
}
