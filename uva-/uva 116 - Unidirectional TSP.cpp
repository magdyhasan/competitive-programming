#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;

int dx[]={-1,0,1};

int grid[12][105],dp[12][105],path[12][105];
int n,m,col;

int rec(int i,int j){
    if(j == m)
        return 0;
    int &ret = dp[i][j];
    if(ret != -1)
        return ret;
    ret = (1<<30);
    for(int k=0;k<3;k++){
        int nx = ((i+dx[k])%n+n)%n; // new movements
        int ny = j + 1;
        int t = rec(nx,ny)+grid[i][j]; // try moving this direction
        if(t < ret || ( t == ret && path[i][j] > nx ) ) // if we get better distance or same distance but lexicographically lower row
            ret = t, path[i][j] = nx;
    }
    return ret;
}

int main(){
    while(scanf("%d%d",&n,&m) != EOF){
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d",&grid[i][j]),dp[i][j] = -1;

        int ret = (1<<30),start;
        for(int i=0;i<n;i++){ // try starting from each row and column 0
            int t = rec(i,0);
            if(t < ret) // if we have a better path
                ret = t, start = i; // start is which row we start from
        }
        col = 0;
        while(col != m){ // now for each column get where on which row we was
            printf(col == m-1 ?"%d\n":"%d ",start+1);
            start = path[start][col++]; // go to next column
        }
        printf("%d\n",ret);
    }
}
