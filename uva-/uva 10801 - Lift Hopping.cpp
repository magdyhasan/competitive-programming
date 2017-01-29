#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

typedef pair<int,int> pii;
#define cost first
#define id second

vector< vector< pii > > floor(105); // adjacent list
int d[105];
int T[10];
int n,k,to;
char temp[1005];

void dijkstra(){
    fill(d,d+105,(1<<30));
    d[0] = 0;
    priority_queue< pii ,vector<pii> , greater<pii> > pq;
    pq.push({0,0});
    while(!pq.empty()){
        pii u = pq.top();
        pq.pop();
        if(d[u.id] < u.cost)
            continue;
        for(auto v:floor[u.id]){
            int vCost = ( u.id == 0 ? 0:60)+u.cost+v.first*(abs(v.id-u.id)); // cost of going from u to v
            if(d[v.id] > vCost)
                d[v.id] = vCost, pq.push({vCost,v.id});
        }
    }
    if(d[k] == (1<<30))
        puts("IMPOSSIBLE");
    else
        printf("%d\n",d[k]);
}

int main(){
    while(scanf("%d%d",&n,&k) != EOF){
        for(int i=0;i<n;i++)
            scanf("%d",T+i);
        floor = vector< vector< pii > >  (105);
        gets(temp);
        for(int i=0;i<n;i++){
            gets(temp);
            vector<int> vec;
            int pos = 0, tpos = 0;
            while(sscanf(temp+tpos,"%d%n",&to,&pos) == 1){ // real all integers from temp
                vec.push_back(to);
                tpos += pos;
            }
            for(int v1=0;v1<vec.size();v1++) // make bidirectional edge between all vec
                for(int v2=v1+1;v2<vec.size();v2++)
                    floor[vec[v1]].push_back({T[i],vec[v2]}),
                    floor[vec[v2]].push_back({T[i],vec[v1]});
        }
        dijkstra();
    }
}
