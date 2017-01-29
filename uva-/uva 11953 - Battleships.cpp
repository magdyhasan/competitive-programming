#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;

int n,li;
char grid[105][105];
bool vis[105][105];

void flood_fill(int i,int j){
    if(i < 0 || j < 0 || i >= n || j >= n || (grid[i][j] != 'x' && grid[i][j] != '@' ) || vis[i][j] )
        return; // if we are not in part of ship then stop || out of bound || already visited

    li += grid[i][j] == 'x'; // if we any live part then we count this component alive ship
    vis[i][j] = 1;

    flood_fill(i+1,j);
    flood_fill(i-1,j);
    flood_fill(i,j+1);
    flood_fill(i,j-1);
}


int main(){
    int T,ca = 0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int ret = 0;
        for(int i=0;i<n;i++)
                scanf("%s",&grid[i]);

        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                li = 0; // base case in flood-fill will handle all cases
                flood_fill(i,j);
                if(li) // for each component that has a live part count it as ship
                    ret++;
            }
        printf("Case %d: %d\n",++ca,ret);
    }
}
