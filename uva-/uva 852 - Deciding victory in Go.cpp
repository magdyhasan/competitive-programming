#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;

char x[12][12];
bool vis[12][12];
int type[12][12];

void flood_fill(int i,int j,char ch){
    if(i < 0 || j < 0 || i > 8 || j > 8 || vis[i][j])
        return;
    if(x[i][j] != ch && x[i][j] != '.') // if not my color
        return;
    if(ch == 'X')
        type[i][j] |= 1; // if it's black turn bit 1 on
    else
        type[i][j] |= 2; // if it's white turn bit 2 on
    vis[i][j] = 1;
    flood_fill(i+1,j,ch); // try four directions
    flood_fill(i-1,j,ch);
    flood_fill(i,j+1,ch);
    flood_fill(i,j-1,ch);
}

int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        for(int i=0;i<9;i++)
            scanf("%s",x+i);
        memset(type,0,sizeof(type));
        int black = 0, white = 0;
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                if(x[i][j] != '.'){ // if it's black or white go mark this area with black or white
                    memset(vis,0,sizeof(vis));
                    flood_fill(i,j,x[i][j]);
                }

        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                if(type[i][j] == 1) // if it was only marked as black ( bit 1 is on )
                    black++;
                else if(type[i][j] == 2) // if it was only marked as white ( bit 2 is on )
                    white++;
        printf("Black %d White %d\n",black,white);
    }
}
