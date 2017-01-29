#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
#include<queue>
using namespace std;


typedef pair<int,int> pii;
#define mp(a,b) make_pair(a,b)
#define cost first
#define id second

vector< vector<pii> > adj(200005);
int d[200005];
int n,m,S,T,a,b,c;

void dijkstra(){
    fill(d,d+n+1,(1<<30));
    priority_queue< pii,vector<pii>,greater<pii> > pq;
    pq.push(mp(0,S));
    d[S] = 0;
    while(!pq.empty()){
        pii u = pq.top();
        pq.pop();
        if(u.id == T){ // we reached target
            printf("%d\n",u.cost);
            return; // terminate
        }
        if(d[u.id] < u.cost)
            continue;
        for(auto v:adj[u.id])
            if(d[v.id] > u.cost+v.cost)
                d[v.id] = u.cost+v.cost, pq.push(mp(d[v.id],v.id));
    }
    puts("unreachable"); // we couldn't reach target
    return;
}

int main(){
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        printf("Case #%d: ",t);
        scanf("%d%d%d%d",&n,&m,&S,&T);
        adj = vector< vector<pii> > (n+1);
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            adj[a].push_back(mp(c,b)); // bidirectional edges
            adj[b].push_back(mp(c,a));
        }
        dijkstra();
    }
}
