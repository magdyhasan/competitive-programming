#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<utility>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

const int maxn = 105;

int head[maxn];

struct edge{
	int u, v, l, t;
	int nxt;
} edge[10500];
int e;


void addEdge(int u, int v, int l, int t){
	edge[e].u = u, edge[e].v = v, edge[e].l = l, edge[e].t = t;
	edge[e].nxt = head[u], head[u] = e++;
}


int dp[105][10500];
int n, m, k;

int rec(int u, int rem){
	if (u == n) return 0;
	int &ret = dp[u][rem];
	if (ret != -1) return ret;
	ret = 123456789;
	for (int i = head[u]; i != -1; i = edge[i].nxt)
		if (edge[i].t <= rem)
			ret = min(ret, rec(edge[i].v, rem - edge[i].t) + edge[i].l);
	return ret;
}



int main(){
    freopen("uva.txt","rt",stdin);
    int tc;
    scanf("%d",&tc);
    while(tc--){
		e = 0;
		memset(head, -1, sizeof(head));
		memset(dp, -1, sizeof(dp));
        scanf("%d%d%d",&k,&n,&m);
        while(m--){
			int u, v, l, t;
			scanf("%d%d%d%d", &u, &v, &l, &t);
			addEdge(u, v, l, t);
        }
		int ret = rec(1, k);
		if (ret != 123456789) printf("%d\n", ret);
		else puts("-1");
    }
}
