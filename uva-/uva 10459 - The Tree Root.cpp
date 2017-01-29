#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int d[5002];
int lvl[5002];
vector< vector<int> > adj(5005);
int degree[5005];
int n,nu,v;


vector<int> center(){ // find roots by tree shrinking
    vector<int> ret;
    queue<int> q;
    memset(lvl,0,sizeof(lvl));
    for(int i=1;i<=n;i++)
        if(degree[i] == 1) // push all leafs nodes
            q.push(i);
    int mxlvl = 0; // level we are at
    while(!q.empty()){
        int u = q.front(); // pop that leaf node
        q.pop();
        for(auto v:adj[u]){ // look at the parent of that node
            degree[v]--; // decrease the edge of their parent ( because we just remove one their child )
            if(degree[v] == 1){ // if this parent node have only one node now it becomes leaf node
                q.push(v);
                lvl[v] = lvl[u]+1; // we are now at a higher level
                mxlvl = max(mxlvl,lvl[v]);
            }
        }
    }
    for(int i=1;i<=n;i++)
        if(lvl[i] == mxlvl) // mxlvl is the highest lvl of the tree ( hence that has the root node/s )
            ret.push_back(i);
    return ret;
}

void solve(){
    vector<int> bestRoots = center(); // find the roots of the tree
    queue<int> q;
    for(int i=1;i<=n;i++)
        d[i] = (1<<27);
    for(auto x:bestRoots) //from this root/s we find farthest nodes ( worst nodes )
        q.push(x),d[x]=0;
    int mx = -1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v:adj[u])
            if(d[v] > d[u]+1){
                d[v] = d[u]+1;
                q.push(v);
                mx = max(d[v],mx); // this the longest height from the root
            }
    }
    printf("Best Roots  :");
    for(auto x:bestRoots)
            printf(" %d",x);
    puts("");

    printf("Worst Roots :");
    for(int i=1;i<=n;i++)
        if(d[i] == mx)
            printf(" %d",i);
    puts("");
}

int main(){
    while(scanf("%d",&n)!=EOF){
        adj = vector< vector<int> > (5005);
        for(int i=1;i<=n;i++){
            scanf("%d",&nu);
            degree[i] = nu;
            for(int j=1;j<=nu;j++){
                scanf("%d",&v);
                adj[i].push_back(v);
            }
        }
        solve();
    }
}
