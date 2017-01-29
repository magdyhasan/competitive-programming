#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<map>
#include<string>
using namespace std;

map<string,int> id;
bool adj[105][105];
string na[105];
int edges, ca =0,t,i,j,prv,nevent,n,msg,k,nu;
char event[12],event2[12];

void init(){
    id.clear();
    memset(adj,0,sizeof(adj));
}

void read(){
    n = nu = 1;
    for(i=0;i<edges;i++){
        scanf("%d",&t);
        prv = 0;
        for(j=0;j<t;j++){
            scanf("%s",event);
            id[event] = n++;
            na[nu++] = event;
            nevent = id[event];
            adj[prv][nevent] = 1;
            prv = nevent;
        }
    }
    scanf("%d",&msg);
    for(i=0;i<msg;i++){
        scanf("%s%s",event,event2);
        adj[ id[event] ][ id[event2] ] = 1;
    }
}

void floyd(){
    for(k=1;k<n;k++)
        for(i=1;i<n;i++)
            for(j=1;j<n;j++)
                adj[i][j] |= (adj[i][k]&adj[k][j]);
}

int main(){
    while(scanf("%d",&edges)){
        if(edges == 0)
            break;
        init();
        read();
        floyd();
        string res = "";
        int con = 0; // keep track of how many pairs Concurrent
        for(i=1;i<n;i++) // find any pair that's not adjacent
            for(j=i+1;j<n;j++)
                if(adj[i][j] == 0 && adj[j][i] == 0){
                    con++;
                    if(con <= 2) // we only have to output only 2 pair ( even if there's more )
                        res += "("+na[i]+","+na[j]+") ";
                }
        if(con) // if there's some pair Concurrent
            printf("Case %d, %d concurrent events:\n%s\n", ++ca, con,res.c_str());
        else
            printf("Case %d, no concurrent events.\n", ++ca);
    }
}
