#include<iostream>
#include<stdio.h>
#include<cstring>
#include<vector>
#include<sstream>
#include<utility>
#include<queue>
using namespace std;

typedef pair<int,int> pii;
#define mp(a,b) make_pair(a,b)
#define cost first
#define id second

vector<pii> adj[10005];
int d[10005];
int u, v, cost, n, mx;

int BFS(int s,bool one){
    queue<int> q;
    q.push(s);
    for(int i=0;i<=n;i++)
        d[i] = (1<<25);
    d[s] = 0;
    while(!q.empty()){ // normal BFS
        int u = q.front();
        q.pop();
        for(auto v:adj[u])
            if(d[v.id] > d[u]+v.cost){
                d[v.id] = d[u]+v.cost;
                q.push(v.id);
            }
    }
    pii mx = {0,-1};
    for(int i=0;i<=n;i++) // find max path
        if(d[i] > mx.first && d[i] != (1<<25))
            mx.first = d[i], mx.second = i;
    if(!one) // if one == 0 then i first founded the farthest node from any random node
        return BFS(mx.second,1);
    else // now how from the farthest node we found we now find the farthest node from this node
        return mx.first; // this is the longest path
}



int main(){
    string line;
    while(getline(cin,line)){
        if(line.size() == 0){
            cout << BFS(u,0) << '\n';
            for(int i=0;i<10005;i++)
                adj[i].clear();
            continue;
        }
        istringstream(line) >> u >> v >> cost;
        n = max(n,max(u,v));
        adj[u].push_back(mp(cost,v));
        adj[v].push_back(mp(cost,u));
    }
    cout << BFS(u,0) << '\n';
}
