#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

long long adj[35][35];

int main(){
    int m,to,from,n,tc=-1;
    while(scanf("%d",&m) != EOF){
        n = 0;
        memset(adj,0,sizeof(adj));
        printf("matrix for city %d\n",++tc);
        while(m--){
            scanf("%d%d",&to,&from);
            adj[to][from] = 1;
            n = max(n,max(to,from));
        }
        for(int k=0;k<=n;k++)
            for(int i=0;i<=n;i++)
                for(int j=0;j<=n;j++)
                    adj[i][j] += adj[i][k]*adj[k][j];

        for(int k=0;k<=n;k++)
            if(adj[k][k]) // if there's path from node to itself .. then by this node as intermediate node we have infinite paths
                for(int i=0;i<=n;i++)
                    for(int j=0;j<=n;j++)
                        if(adj[i][k] && adj[k][j]) // if k can be used as intermediate between i,j
                            adj[i][j] = -1;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++){
                printf("%d",adj[i][j]);
                if(j != n)
                    putchar(' ');
                else
                    puts("");
            }
    }
}
