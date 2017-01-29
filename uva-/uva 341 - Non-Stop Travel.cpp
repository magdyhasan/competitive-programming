#include<stdlib.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int inf = (int)1e9;

#define delay first
#define id second

int n,cases;
vector< vector<int> > adj(15);
int cost[15][15];
int prv[15];

void printpath(int s,int t){
    if(s == t){
        cout << " " << s;
        return;
    }
    printpath(prv[s],t);
    cout << " " << s;
}

void dijkstra(int s,int target){
    memset(prv,-1,sizeof(prv));
    int d[15] = {};
    for(int i=0;i<15;i++)
        d[i] = inf;

    priority_queue< pair<int,int> ,vector<pair<int,int>> ,greater<pair<int,int>> > q;
    q.push(make_pair(0,s));
    d[s] = 0;

    while(!q.empty()){
        pair<int,int> u = q.top();
        q.pop();
        if(u.id == target)
            break;
        for(auto v:adj[u.id])
            if(d[v] > d[u.id]+cost[u.id][v]){
                d[v] = d[u.id]+cost[u.id][v];
                prv[v] = u.id;
                q.push(make_pair(d[v],v));
            }
    }
    cout << "Case " << ++cases << ": Path = " ;
    printpath(target,s);
    cout << "; " << d[target] << " second delay" << '\n';
}

int main(){
    cin.sync_with_stdio(false);cin.tie(NULL);

    while(cin >> n){
        if(n == 0)
            break;
        int i,t,j,to,co,from;
        for(i=0;i<=n;i++)
            adj[i].clear();

        for(i=0;i<=n;i++)
            for(j=0;j<=n;j++)
                cost[i][j] = inf;

        for(i=1;i<=n;i++){
            cin >> t;
            for(j=0;j<t;j++){
                cin >> to >> co;
                adj[i].push_back(to);
                cost[i][to] = co;
            }
        }
        cin >> from >> to;
        dijkstra(from,to);
    }
}
