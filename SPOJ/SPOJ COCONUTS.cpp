#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

const int inf = (int)1e9;
const int MAXN = 305;

int cap[305][305], prv[MAXN], flow[305][305];
vector< vector<int> > adj(305);
int n,m,f1,f2;


bool augment(){
	memset(prv, -1, sizeof(prv));
	queue<int> q;	q.push(0);
	while (!q.empty()){
		int u = q.front();	 q.pop();
		if (u == n+1) break;
		for (int v : adj[u])
			if (flow[u][v] < cap[u][v] && prv[v] == -1)
				q.push(v), prv[v] = u;
	}
	if (prv[n+1] == -1)	return false;
	int t = n+1;
	while (t != 0){
		int pr = prv[t];
		flow[pr][t] ++;
		flow[t][pr] --;
		t = pr;
	}
	return true;
}



int main(){
	freopen("uva.txt", "r", stdin);
    while(scanf("%d%d",&n,&m)){
        if(n == 0 && m == 0)
            break;
        memset(cap,0,sizeof(cap));
		memset(flow, 0, sizeof(flow));
		adj = vector< vector<int> >(305);
        int vote;
        for(int i=1;i<=n;i++){
			scanf("%d", &vote);
            if(vote)
                cap[0][i] = 1,adj[0].push_back(i);
            else
                cap[i][n+1] = 1,adj[i].push_back(n+1);
        }
        for(int i=0;i<m;i++){
			scanf("%d%d", &f1, &f2);
            cap[f1][f2] = cap[f2][f1] = 1;
            adj[f1].push_back(f2);
            adj[f2].push_back(f1);
        }
		int ret = 0;
		while (augment()) ret++;
		printf("%d\n", ret);
    }
}
