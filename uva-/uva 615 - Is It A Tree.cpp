#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<map>
#include<vector>
#include<set>
using namespace std;

map<int, vector<int> > adj;
map<int,bool> vis;
map<int,int> par;
set<int> nodes;
int cases,edges;
bool tree;

void dfs(int u){
    if(vis[u]){ // if a node is already visited then it's not a tree
        tree = 0;
        return;
    }
    vis[u] = 1;
    for(auto v:adj[u]) // visit all children
        dfs(v);
}

void solve(){
    tree = 0;
    vis = map<int,bool> ();
    int root = -1, a ;

    for(auto x:par) // check degree of all edges
        if(x.second == 0) // if it's indegree == 0 then it's root
            root++,a=x.first; // we do root++ because if we have more than one root ( root > 0 ) it's not a tree
        else if(x.second > 1) // if there's a node with indegree > 1, then not a tree
            root += 2; // we increasing root here just to mark we have indegree > 1 ( instead of making another variable )

    if(root == 0){ // we have only 1 root and no indegree > 1
        tree = 1;
        dfs(a);
    }
    for(auto x:nodes) // check to see if all tree is connected
        if(vis[x] == 0) // if some node not visited then it's not a tree
            tree = 0;
    if(edges != nodes.size()-1 ) // if number of vertex != number of edges -1 ( because tree has n-1 edges) then it's not a tree
        tree = 0;
    if(tree) // now just check
        printf("Case %d is a tree.\n",++cases);
    else
        printf("Case %d is not a tree.\n",++cases);
}

void read(int to,int from){
    adj[from].push_back(to); // make edge between from and to
    nodes.insert(from );    nodes.insert(to); // insert nodes ( in a set to check if it's already there )
    edges++; // we have new edge
    par[to] += 1; // the to vertex have new indegree
    par[from] += 0; // the from vertex have no indegree ( have outdegree and we don't care about that )
}

int main(){
    int to , from;
    while(scanf("%d%d",&from,&to)){
        if(to < 0 && from < 0)
            break;
        if(to == 0 && from == 0){// the definition of a tree in the problem say that if no nodes then it's a tree
            printf("Case %d is a tree.\n",++cases);
            continue;
        }
        // initialize
        adj = map<int, vector<int> > ();
        par = map<int,int>();
        edges = 0;
        nodes.clear();
        read(to,from);
        while(scanf("%d%d",&from,&to) ){ // read all edges
            if(to == 0 && from == 0)
                break;
            read(to,from);
        }
        solve();
    }
}
