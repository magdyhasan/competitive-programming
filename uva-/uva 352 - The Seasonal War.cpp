#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;

int n,tc;
char x[30][30];
bool vis[30][30];

int dx[]={1,-1,0,0,1,-1,-1,1};
int dy[]={0,0,1,-1,1,-1,1,-1};

inline bool isValid(int i,int j){
    return (i >=0 && j >= 0 && i < n && j < n);
}

int flood_fill(int i,int j){
    if(vis[i][j] || !isValid(i,j) || x[i][j] == '0')
        return 0;
    bool ret = 1; // we are on a 1 cell
    vis[i][j] = 1;
    for(int k=0;k<8;k++) // try all 4 direction + diagonals
        ret += flood_fill(i+dx[k],j+dy[k]);
    return ret;
}

int main(){
    while(scanf("%d",&n)!=EOF){
        int ret = 0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
                scanf("%s",x+i);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(!vis[i][j])
                    ret += flood_fill(i,j);
        printf("Image number %d contains %d war eagles.\n",++tc,ret);
    }
}
