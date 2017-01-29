#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<queue>
using namespace std;

struct pos{
    int x;
    int y;
    int di;
};

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int vis[105][105][2];
char grid[105][105];
int posx[2],posy[2];
int n,m,cow,cost;

inline bool valid(int i,int j){
    return (i >= 0 && j >= 0 && i < n && j < m && grid[i][j] != '*');
}

void solve(){
    queue<pos> q;
    int nx,ny,ndi;
    vis[posx[0]][posy[0]][0] = vis[posx[0]][posy[0]][1] = 0; // mark our start with distance 0
    for(int k=0;k<4;k++){
        nx = posx[0]+dx[k]; // laser can move in four directions
        ny = posy[0]+dy[k];
        ndi = (k < 2 ? 0:1); // it's direction will be 0 if it's moves vertically and 1 if moves horizontally
        if(valid(nx,ny) )
            q.push({nx,ny,ndi}), vis[nx][ny][ndi] = 0; // we can go there with cost 0
    }
    while(!q.empty()){
        pos u = q.front();
        q.pop();
        if(u.di == 0){ // if we are moving vertically
            for(int k=0;k<4;k++){
                nx = u.x + dx[k];
                ny = u.y + dy[k];
                ndi = (k < 2 ? 0:1); // if we are going vertically then make ndi = 1, else ndi = 0
                cost = (k < 2 ? 0:1); // if we are going horizontally then we have cost = 1
                if(valid(nx,ny) && vis[nx][ny][ndi] > vis[u.x][u.y][u.di]+cost)
                    vis[nx][ny][ndi] =  vis[u.x][u.y][u.di]+cost, q.push({nx,ny,ndi});
            }
        }else{ // if we moving horizontally
            for(int k=0;k<4;k++){
                nx = u.x + dx[k];
                ny = u.y + dy[k];
                ndi = (k < 2 ? 0:1);// if we are going horizontally  then make ndi = 1, else ndi = 0
                cost = (k < 2 ? 1:0);// if we are going vertically  then make cost = 1
                if(valid(nx,ny) && vis[nx][ny][ndi] > vis[u.x][u.y][u.di]+cost )
                    vis[nx][ny][ndi] =  vis[u.x][u.y][u.di]+cost, q.push({nx,ny,ndi});
            }
        }
    }

    printf("%d\n",min(vis[posx[1]][posy[1]][0],vis[posx[1]][posy[1]][1]));
}

int main(){
    scanf("%d%d",&m,&n);
    for(int i=0;i<n;i++){
        scanf("%s",grid+i);
        for(int j=0;j<m;j++){
            if(grid[i][j] == 'C')
                posx[cow] = i, posy[cow++] = j; // get positions of cows
            vis[i][j][0] = vis[i][j][1] = (1<<10); // initialize vis
        }
    }
    solve();
}
