#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<queue>
using namespace std;

struct pos{
    int x;
    int y;
};

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int vis[105][105];
char grid[105][105];
int posx[2],posy[2];
int n,m,cow,cost;

inline bool valid(int i,int j){
    return (i >= 0 && j >= 0 && i < n && j < m && grid[i][j] != '*' );
}

void solve(){
    queue<pos> q;
    int nx,ny;
    vis[posx[0]][posy[0]] = 0; // mark our start with distance 0
    q.push({posx[0],posy[0]});
    while(!q.empty()){
        pos u = q.front();
        q.pop();
        for(int k=0;k<4;k++){
            int j = 1; // we can fill the whole row/column from this position while there's no stones
            nx = u.x + dx[k]; // try four direction
            ny = u.y + dy[k];
            while(valid(nx,ny)){
                if(vis[nx][ny] > vis[u.x][u.y] + 1)
                    vis[nx][ny] = vis[u.x][u.y] + 1, q.push({nx,ny});
                j++; // go to next cell in the row/column
                nx = u.x + dx[k]*j; // e.g if we was going up by 1 row second time we go by 2 rows and so on
                ny = u.y + dy[k]*j;
            }
        }
    }
    printf("%d\n",vis[posx[1]][posy[1]]-1);
}

int main(){
    scanf("%d%d",&m,&n);
    for(int i=0;i<n;i++){
        scanf("%s",grid+i);
        for(int j=0;j<m;j++){
            if(grid[i][j] == 'C')
                posx[cow] = i, posy[cow++] = j; // get positions of cows
            vis[i][j] = (1<<10); // initialize vis
        }
    }
    solve();
}
