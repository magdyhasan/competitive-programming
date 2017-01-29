#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

char land;
char x[25][25];
bool vis[25][25];
int n,m,posX,posY;

int mod(int j){ // to wrap around columns
    return ((j%m)+m)%m;
}

int flood_fill(int i,int j){
    if(i < 0 || i >= n || vis[i][j] || x[i][j] != land)
        return 0;
    vis[i][j] = 1;
    int ret = 1; // now he have 1 new area
    ret += flood_fill(i+1,j); // try four directions
    ret += flood_fill(i-1,j);
    ret += flood_fill(i,mod(j+1));
    ret += flood_fill(i,mod(j-1));
    return ret;
}

int main(){
    while(scanf("%d%d",&n,&m) != EOF){
        memset(vis,0,sizeof(vis));

        for(int i=0;i<n;i++)
            scanf("%s",x+i);
        scanf("%d%d",&posX,&posY);

        land = x[posX][posY]; // get his standing position char ( any char else is water )
        flood_fill(posX,posY); // mark his standing area as visited

        int mx = 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(!vis[i][j]) // any are that's not visited he can take
                    mx = max(mx,flood_fill(i,j));
        printf("%d\n",mx);
    }
}
