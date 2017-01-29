#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<map>
#include<vector>
#include<queue>
using namespace std;

map<string,int> id;
vector< vector<int> > adj(5002);
bool vis[5005];

int n,m;

int dfs(int u){
    if(vis[u])
        return 0;
    int ret = 1; // now we have a node (u)
    vis[u] = 1;
    for(auto v:adj[u]) // try to go to any adjacent not visited node
        if(!vis[v])
            ret += dfs(v);
    return ret;
}

void solve(){
    int res = 0;
    memset(vis,0,sizeof(bool)*(n+1));
    for(int i=0;i<n;i++)
        if(!vis[i]){// make each possible component
            int t = dfs(i);
            res = max(res,t); // maximize on number of nodes on each component
        }
    printf("%d\n",res);
    return;
}

int main(){
    while(scanf("%d%d",&n,&m)){
        if(n == 0 && m == 0)
            break;
        char st[35],str[35];
        id.clear();
        adj = vector< vector<int> > (n+1);
        for(int i=0;i<n;i++)
            scanf("%s",st),id[st] = i;
        for(int i=0;i<m;i++)
            scanf("%s%s",st,str), adj[id[str]].push_back(id[st]),adj[id[st]].push_back(id[str]);
        solve();
    }
}
