#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int adj[205][205];
int x[205],y[205];
int n;

inline int square(int x){
    return (x*x);
}

int main(){
    int tc = 0;
    while(scanf("%d",&n)){
        if(n == 0)
            break;
        for(int i=0;i<n;i++)
            scanf("%d%d",x+i,y+i);

        for(int i=0;i<n;i++) // calculate distance for all stones
            for(int j=i+1;j<n;j++)
                adj[i][j] = adj[j][i] = square(x[i]-x[j])+square(y[i]-y[j]);

        for(int k=0;k<n;k++) // floyd-warshall to find max-min
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    adj[i][j] = min(adj[i][j],max(adj[i][k],adj[k][j]));
        printf("Scenario #%d\nFrog Distance = %.3f\n\n",++tc,sqrt((double)adj[0][1]));
    }
}
