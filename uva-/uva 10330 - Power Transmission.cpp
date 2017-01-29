#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int cap[250][250],d[250],prv[250];
bool vis[250];
int n,m,cp,to,from,S,D,sink;

int max_flow(){
    int mxflow = 0;
    while(1){ // find path with Dijkstra O(n^2)
        for(int i=0;i<=sink;i++) // initialize
            d[i] = cap[0][i], prv[i] = 0, vis[i] = 0;
        vis[0] = 1;
        int cur = 0;
        while(1){
            int mx = 0, mxi;
            for(int i=0;i<=sink;i++) // find node that's not visited and not marked before
                if(!vis[i] && d[i] > mx)
                    mx = d[mxi=i];
            if(mx == 0 || mxi == sink) // if no new node or we reach sink then stop ( we found path)
                break;
            vis[cur = mxi] = 1; // mark this node
            for(int i=0;i<=sink;i++) // relax other nodes
                if(min(d[cur],cap[cur][i]) > d[i]) // if flow from cur to i > flow of 0 to i make path from cur to i
                    d[i] = min(d[cur],cap[cur][i]), prv[i] = cur;
        }
        if(d[sink] == 0) // if no path found to sink
            break;
        int tp = sink;
        while(tp != 0){ // reconstruct the path and subtract our new flow
            cap[prv[tp]][tp] -= d[sink];
            cap[tp][prv[tp]] += d[sink];
            tp = prv[tp];
        }
        mxflow += d[sink]; // we now have new flow
    }
    return mxflow;
}

int main(){
    while(scanf("%d",&n) != EOF){
        memset(cap,0,sizeof(cap));
        sink = 2*n+1;
        for(int i=1;i<=n;i++){ // vertex splitting to handle vertex capacity
            scanf("%d",&cp);
            cap[i][i+n] = cp; // we add vertex from i to new vertex (i+n)
        }
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&from,&to,&cp);
            cap[from+n][to] = cp; // make an edge from input(from) -> to.. input from = from+n
        }
        scanf("%d%d",&S,&D); // add edges from our source (0)
        for(int i=0;i<S;i++){
            scanf("%d",&from);
            cap[0][from] = (1<<30); // we can have infinite power from source to the connected vertex
        }
        for(int i=0;i<D;i++){ // add edges to sink
            scanf("%d",&to);
            cap[to+n][sink] = (1<<30); // we can have infinite power through our edges to sink
        }
        printf("%d\n",max_flow());
    }
}
