#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
using namespace std;

bool vis[256];
int edj[256][256];
vector< vector<int> > adj(256);
int n,m,idx,nodes,edges;

void dfs(int u){
    if(vis[u]) // if we already have this node in this component
        return;
    vis[u] = 1; // mark it as a node in our component
    nodes++; // we have new node
    for(auto v:adj[u]) // for each adjacent node for node u
        if(edj[u][v] > 0){ // if we have an edge between u and v
            edj[u][v]--; // we now have used this edge on our component
            edj[v][u]--;
            edges++; // and we have one more edge
            dfs(v);
        }
    return;
}

int solve(){
    int ret = 1; // we already have the outer face
    for(int i=0;i<n;i++) // make each component by DFS
        if(!vis[i]){ // if it's not visited then it's not in any previous component
            nodes = edges = 0; // initialize number of nodes and edges for this new component
            dfs(i); // get all nodes of this component
            ret += 1+edges-nodes; // by euler's formula (n-m+f=2 with the outer) we have f = 1+m-n (without the outer face)
        }
    return ret;
}

int main(){
    while(cin >> n >> m){
        memset(vis,0,sizeof(vis));
        memset(edj,0,sizeof(edj));
        for(int i=0;i<n;i++)
            adj[i].clear();
        map<string,int> ma; // map every character(string) to a number
        ma.clear();
        idx = 0; // start indexing from 0
        string u,v;
        int p,q;
        for(int i=0;i<m;i++){
            cin >> u >> v;
            if(ma.count(u) == 0) // if the character doesn't have index make one for them
                ma[u] = idx++;
            if(ma.count(v) == 0) // if the character doesn't have index make one for them
                ma[v] = idx++;
            p = ma[u];
            q = ma[v];
            adj[p].push_back(q); // make adjacency list
            adj[q].push_back(p); // we have undirected edges
            edj[p][q]++; // increase the number of edges between this two vertex
            edj[q][p]++;
        }
        cout << solve() << '\n';
    }

}
