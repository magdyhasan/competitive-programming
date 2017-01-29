#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<utility>
#include<queue>
using namespace std;

typedef pair<int,pair<int,int> > ppi;
#define mp(a,b,c) make_pair(a,make_pair(b,c))

#define toll first
#define dist second.first
#define id second.second


vector< vector<ppi> > adj(105);
int k,n,m,S,D,L,T;
int d[105];

bool operator>(ppi n1,ppi n2){}

void dijkstra(){
    priority_queue< ppi, vector<ppi> , greater< ppi> > pq;
    fill(d,d+n+1,(1<<30));
    pq.push(mp(0,0,1));
    while(!pq.empty()){
        ppi u = pq.top();
        pq.pop();
        if(d[u.id] <= u.dist)
            continue;
        d[u.id] = u.dist;
        for(auto v:adj[u.id])
            if( v.toll+u.toll <= k  )
                pq.push(mp(v.toll+u.toll,u.dist+v.dist,v.id));
    }
    if(d[n] != (1<<30))
        printf("%d\n",d[n]);
    else
        puts("-1");
    return;
}

int main(){
    //freopen("ci.in","rt",stdin);
    int tc;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d%d",&k,&n,&m);
        while(m--){
            scanf("%d%d%d%d",&S,&D,&L,&T);
            adj[S].push_back(mp(T,L,D));
        }
        dijkstra();
    }
}
