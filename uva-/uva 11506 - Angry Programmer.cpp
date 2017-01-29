#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;

const int inf = (int)1e8;
const int MAX = 110; // max number of nodes

int n,m;
bool vis[MAX];
int cap[MAX][MAX]; // edges between each 2 nodes

int augmentation_path(int v,int maxflow){ // find a path with flow more than 0
    vis[v] = 1; // mark the current node as visit
    if(v == n) // if we reach our target (n) then stop
        return maxflow;
    int newflow = 0; // try to find a flow from this node to target
    for(int u=1;u<=n;u++) // try any node that have an edge with the current node (v) > 0
        if(!vis[u] && cap[v][u] > 0){ // if  u isn't already in the path and there an edge between it and v > 0 then try to make a path with node
            newflow = augmentation_path( u,min(maxflow,cap[v][u]) ); // we try path from here with maxflow equal to minimum edge in this path
            if(newflow > 0){ // we found a path that have flow > 0
                cap[v][u] -= newflow; // now decrease the capacity between (v,u) we already have flow between them = newflow
                cap[u][v] += newflow; // add reversed edge with capacity = newflow according to Ford Fulkerson Algorithm
                break; // stop at current path
            }
        }
    return newflow; // return the flow we have in the path
}

int min_cut(){
    int ret = 0; // try to make a flow
    while(1){
        memset(vis,0,sizeof(vis)); // clear vis
        int flow = augmentation_path(1,inf); // try to get a path with flow > 0
        if(!flow) // if there no path ( flow == 0 ) then boss can't reach central server.
            break;
        ret += flow; // if we found a path then add the cost of destroying it
    }
    return ret; // return the cost for destroying all paths
}



int main(){
    while(1){
        scanf("%d%d",&n,&m); // read numbers
        if(n == 0)
            break;
        memset(cap,0,sizeof(cap));
        for(int i=1;i<=n;i++) // split each city destroy cost as an edge ( 1 has cost 5 .. we split it to 1->5 by cost 6 )
            cap[i][i+n] = inf; // initially all city destroy cost to inf
        for(int i=0;i<n-2;i++){ // read each city destroy cost
            int city,cost;
            scanf("%d%d",&city,&cost);
            cap[city][city+n] = cost;
        }
        for(int i=0;i<m;i++){ // read edges
            int from,to,cost;
            scanf("%d%d%d",&from,&to,&cost);
            cap[from+n][to] = cap[to+n][from] = cost; // now instead of connecting from->to we connect from+n->to .. because from->from+n that's the edge with cost of destroying the city itself
        }
        n *= 2; // now we have edges equal to n*2 because we added a new vertex for each vertex
        printf("%d\n",min_cut());
    }

}
