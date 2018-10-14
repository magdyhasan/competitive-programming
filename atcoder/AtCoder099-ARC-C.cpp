/*
we're looking for a set of nodes that are fully connected
in other words, every node in one set we will make should've direct edge with each other node
instead of trying to find such nodes that have direct edges with each node in same component,
let's look at the complement graph
if two nodes have edge in complomnent graph, they can't be in same set, since they have no direct edge in original graph
so let's do bipartite mathcing for each component and if some component is bipartite then answer is -1
else we now have have some components each can be divied into two sets
question now is just what set in each component to match with other set in other components,
this can be done via dp,
let dp[i][], having i components so far, we can have any number of nodes equal to j, where dp[i][j] = 1
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



typedef long long ll;

const int maxn = 500500;

bool ad[1005][1005];

vector<int> adj[maxn];

int cnt[1005][2];
int col[1005];
int comps;

bool dfs(int u, int cl){
	col[u] = cl;
	++cnt[comps][cl - 1];// count number of nodes with color cl
	for (int v : adj[u]) {
		if (col[v] == cl)	return 0;
		if (!col[v]){
			if (!dfs(v, 3 - cl)) return 0;
		}
	}
	return 1;
}

int dp[1005][1005];

int main(){
	ios::sync_with_stdio(0);
	int n, m, u, v;
	cin >> n >> m;
	lp(i, m){
		cin >> u >> v;
		--u; --v;
		ad[u][v] = ad[v][u] = 1;
	}
	// build complment graph
	lp(i, n) lp(j, n) if (i != j && !ad[i][j])
		adj[i].push_back(j);
	// test each component for bipartite
	lp(i, n)if (!col[i]){
		if (!dfs(i, 1)) {
			cout << "-1";
			return 0;
		}
		comps++;
	}
	//do dp 
	dp[0][0] = 1;
	lp(i, comps) lp(j, n) if (dp[i][j]){
		// if we're at component i, and going to component i+1, we can add to previous dp[i][j], cnt[i][0] and cnt[i][1]
		dp[i + 1][j + cnt[i][0]] = dp[i + 1][j + cnt[i][1]] = 1;
	}
	int ret = n*n;
	lp(i, n + 1) if (dp[comps][i])// if we could reach i nodes to be in same component
		// if i nodes on set and n-i on other set
		ret = min(ret, i*(i - 1) / 2 + (n - i)*(n - i - 1) / 2);
	cout << ret;
}