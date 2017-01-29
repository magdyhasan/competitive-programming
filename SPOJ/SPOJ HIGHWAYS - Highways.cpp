#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<utility>
#include<queue>
#include<cstring>
using namespace std;

const int inf = (int)1e9;
typedef pair<int,int> pii;
#define mp(a,b) make_pair(a,b)
#define id second
#define cost first

vector<pair<int,int>> adj[100005];
int d[100005];
bool mark[100005];

int main(){
    int T;
    scanf("%d",&T);
    int n,m,S,D,from,to,cost;
    for(int ca=1;ca<=T;ca++){
        scanf("%d%d%d%d",&n,&m,&S,&D);
        for(int i=0;i<=n;i++)
            adj[i].clear(),d[i] = inf;
        while(m--){
            scanf("%d%d%d",&from,&to,&cost);
            adj[from].push_back(mp(cost,to));
            adj[to].push_back(mp(cost,from));
        }
        priority_queue<pii,vector<pii>,greater<pii>> q;
        q.push(mp(0,S));
        d[S] = 0;
        memset(mark,0,sizeof(mark));
        while(!q.empty()){ // Dijkstra
            pii cur = q.top();
            q.pop();
            if(mark[cur.id])
                continue;
            mark[cur.id] = 1;
            for(auto x:adj[cur.id])
                if(d[x.id] > cur.cost+x.cost){
                    d[x.id] = cur.cost+x.cost;
                    q.push(mp(d[x.id],x.id));
                }
        }
        if(d[D] != inf)
            printf("%d\n",d[D]);
        else
            puts("NONE");
    }
}
