#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;


#define inf 1e9

int n,m,i,j,k,s,t;
int to[10005],from[10005];

double adj[105][105],temp[10005],dis[10005];
int path [105][105];


int main(){
    while(scanf("%d%d",&n,&m) == 2 ){
        scanf("%d%d",&s,&t);
        for(i=0;i<=n;i++)
            for(j=0;j<=n;j++)
                path[i][j] = j, adj[i][j] = inf;
        for(i=0;i<m;i++){ // store all edges
            scanf("%d%d%lf%lf",to+i,from+i,temp+i,dis+i);
            adj[to[i]][from[i]] = min(adj[to[i]][from[i]],temp[i]); // make the adj is the minimum according to temperature
            adj[from[i]][to[i]] = min(adj[from[i]][to[i]],temp[i]);
        }
        // floyd to find path with minimum temperature
        for(k=1;k<=n;k++)
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    adj[i][j] = min(adj[i][j],max(adj[i][k],adj[k][j])); // find min temperature in a path

        double mi = adj[s][t]; // min temperature in the best path
        for(i=0;i<=n;i++) // now we will make adj is th minimum according to distance only if the path is less than mi
            for(j=0;j<=n;j++)
                adj[i][j] = inf;
        // now find minimum distance for all paths that have temperature less than or equal to the minimum temperature
        for(i=0;i<m;i++)
            if( temp[i] < mi+1e-6 ){ // only take this edge if it's temperature less than pr equal to mi
                adj[to[i]][from[i]] = min(adj[to[i]][from[i]],dis[i]);
                adj[from[i]][to[i]] = min(adj[from[i]][to[i]],dis[i]);
            }
        // again floyd to minimize distance with building the path
        for(k=1;k<=n;k++)
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    if(adj[i][j] > adj[i][k]+adj[k][j]){
                        adj[i][j] = adj[i][k]+adj[k][j];
                        path[i][j] = path[i][k];
                    }
        int ss = s;
        printf("%d",s);
        while(ss != t){ // reconstruct the path
            printf(" %d",path[ss][t]);
            ss = path[ss][t];
        }
        puts("");
        printf("%.1f %.1f\n",adj[s][t],mi);
    }
}
