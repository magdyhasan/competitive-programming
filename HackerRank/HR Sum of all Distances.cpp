/*
	root the problem at 1, calculate the required distances
	now, from vertex 1(u), when we're rerooting to one of it's adjacent(v), this will happen when using this edge u-v:
	-we are moving away from all u children's except v, so distances increas by (edge cost)*(n-sz[v])
	-cost of subtree v still the same (d1[v.first])
	-we still have cost of children's of u except v minus usage of edge u-v for v subtree (d2[u] - d1[v.first] - 1LL * v.second*z[v.first])
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

int n;

vector<pii> adj[maxn];
ll z[maxn], d1[maxn], d2[maxn];

void dfs1(int u, int p = -1){
	for (auto v : adj[u]) if (v.first != p){
		dfs1(v.first, u);
		z[u] += z[v.first];
		d1[u] += d1[v.first] + 1LL * v.second * z[v.first];
	}
	z[u]++;
}

void dfs2(int u, int p = -1){
	for (auto v : adj[u]) if (v.first != p){
		d2[v.first] = d1[v.first] + v.second * (n - z[v.first]) + (d2[u] - d1[v.first] - 1LL * v.second*z[v.first]);
		dfs2(v.first, u);
	}
}

int main() {
	//freopen("in.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc; cin >> tc;
	while (tc--){
		cin >> n;
		lp(i, n + 1) adj[i].clear(), d1[i] = d2[i] = z[i] = 0;
		int u, v, c;
		lp(i, n - 1){
			cin >> u >> v >> c;
			adj[u].push_back({ v, c });
			adj[v].push_back({ u, c });
		}
		dfs1(1);
		d2[1] = d1[1];
		dfs2(1);
		lp(i, n) pri(d2[i + 1]);
	}

}