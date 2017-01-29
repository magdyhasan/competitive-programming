#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

double adj[25][25][25];
int path[25][25][25];
int n;
double cost;

void printPath(int i,int j,int step){
    if(step == 1){
        printf("%d",i);
        return;
    }
    printPath(i,path[i][j][step],step-1);
    printf(" %d",path[i][j][step]);
    return;
}

int main(){
    while(scanf("%d",&n) != EOF){
        memset(adj,0,sizeof(adj));

        for(int i=1;i<=n;i++){
            adj[i][i][1] = 1; // initialize all edges from i to i with length 1 to have profit 1
            for(int j=1;j<=n;j++)
                if(i == j)  continue;
                else    scanf("%lf",&cost),adj[i][j][1] = cost, path[i][j][1] = 1;
        }

        for(int steps=2;steps <= n;steps++) // we add length of our path
            for(int k=1;k<=n;k++)
                for(int i=1;i<=n;i++)
                    for(int j=1;j<=n;j++)
                        if(adj[i][j][steps] < adj[i][k][steps-1]*adj[k][j][1])
                            adj[i][j][steps] = adj[i][k][steps-1]*adj[k][j][1], path[i][j][steps] = k;

        for(int steps=2;steps <= n;steps++)
            for(int i=1;i<=n;i++)
                if(adj[i][i][steps] > 1.01){ // if it has profit more than 1 percent
                    printPath(i,i,steps);
                    printf(" %d\n",i);
                    goto done;
                }
        puts("no arbitrage sequence exists");
        done:;
    }
}
