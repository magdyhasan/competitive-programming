#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;

int n;
char x[84][84];
bool vis[85][85][2];

inline bool isValid(int i,int j){ // check if out of board
    return (i < n && j < n && i >=0 && j >= 0);
}

bool DFS(int i,int j,bool move,char player){
    if(!isValid(i,j) || vis[i][j][move]) // if already visited or out of board
        return 0;
    if( (player != x[i][j] && !move) || (move && player != x[i][j] && x[i][j] != 'U') ) // if i stand on cell not like me or 'U' and don't have move
        return 0;
    if(player != x[i][j] && x[i][j] == 'U' && move) // if standing on 'U' and have move
        move = 0;
    vis[i][j][move] = 1;
    if( (player == 'W' && j == n-1) || (player == 'B' && i == n-1) ) // if i'm in the last column or row
        return 1;

    return ( DFS(i+1,j,move,player) || DFS(i-1,j,move,player) || DFS(i,j+1,move,player) || DFS(i,j-1,move,player) ); // try all possible moves
}

int main(){
    int i;
    while(scanf("%d",&n)){
        if(n == 0)
            break;
        for(i=0;i<n;i++)
            scanf("%s",x[i]);
        bool play = 0;
        // white with no moves
        memset(vis,0,sizeof(vis));
        for(i=0;i<n;i++)// he can start anywhere from the first column
            play |= DFS(i,0,0,'W');
        if(play){
            puts("White has a winning path.");
            continue;
        }
        // black with no moves
        memset(vis,0,sizeof(vis));
        for(i=0;i<n;i++) // he can start anywhere from the first row
            play |= DFS(0,i,0,'B'); // he does n't have any move now
        if(play){
            puts("Black has a winning path.");
            continue;
        }
        // white with 1 moves
        memset(vis,0,sizeof(vis));
        for(i=0;i<n;i++)
            play |= DFS(i,0,1,'W'); // now he can make a move
        if(play){
            puts("White can win in one move.");
            continue;
        }
        // black with 1 moves
        memset(vis,0,sizeof(vis));
        for(i=0;i<n;i++)
            play |= DFS(0,i,1,'B'); // now he can make a move
        if(play){
            puts("Black can win in one move.");
            continue;
        }
        puts("There is no winning path.");
    }
}
