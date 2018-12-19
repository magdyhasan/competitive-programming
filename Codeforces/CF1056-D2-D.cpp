/*
	root the tree at node 1, and for each node
	count how many leafs are in there for it's subtree

	now sort nodes by this number and this the answer
*/
#include<functional>

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

int ma[maxn];

vector<int> adj[maxn];

int z[maxn];

void dfs(int u){
	z[u] = 0;
	for (auto v : adj[u]){
		dfs(v);
		z[u] += z[v];
	}
	if (adj[u].size() == 0) z[u] = 1;
}

int main() {
	int n; sci(n);
	int pi;
	lpi(i, 2, n + 1){
		sci(pi);
		adj[pi].push_back(i);
	}
	dfs(1);;
	priority_queue<int> pq;
	lpi(i, 1, n + 1) pq.push(-z[i]);
	while (!pq.empty()){
		printf("%d ", -pq.top());
		pq.pop();
	}
}