#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int n,m;
char x[104][104];
bool vis[104][104][16];

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

map<char,int> key; // assign number to every key


struct pos{
    int x,y; /// our position (i,j)
    int mask; /**
                if we have b key then bit one (2^0) will be on,
                if we have y key then bit two (2^1) will be on,
                if we have r key then bit three (2^2) will be on,
                if we have g key then bit four (2^3) will be on,
              */
    int steps; /// number of steps we take to get in this position
};

bool isValid(int i,int j){ /// check if in the board
    return (i < n && j < m && i >= 0 && j >= 0);
}


int main(){
    cin.sync_with_stdio(false);cin.tie(NULL);
    key['b'] = 0;
    key['y'] = 1;
    key['r'] = 2;
    key['g'] = 3;

    key['B'] = 0;
    key['Y'] = 1;
    key['R'] = 2;
    key['G'] = 3;

    while(cin >> n >> m){
        if(n == 0 && m == 0)
            break;
        memset(vis,0,sizeof(vis));
        queue<pos> q;
        int si,sj;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                cin >> x[i][j];
                if(x[i][j] == '*') /// get the starting position
                    si = i , sj = j;
            }
        pos cur = {si,sj,0,0}; // start from the starting position with steps 0
        q.push( cur );
        bool out = 0; /// mark if we got out
        while(!q.empty()){
            cur = q.front();
            q.pop();
            if(x[ cur.x ][ cur.y ] == 'X'){ /// if we got out
                out = 1;
                break;
            }
            for(int k=0;k<4;k++){ /// try 4 moves
                int nx = cur.x + dx[k]; /// new x
                int ny = cur.y + dy[k]; /// new y
                if(!isValid(nx,ny) || x[nx][ny] == '#' || vis[nx][ny][cur.mask]) /// if we are going to non-valid place or visited place or #
                    continue;
                if(x[nx][ny] == 'b' || x[nx][ny] == 'y' || x[nx][ny] == 'r' || x[nx][ny] == 'g'){ /// if we gonna take a key
                    vis[nx][ny][ (cur.mask|(1<<(key[x[nx][ny]]))) ] = 1; /// turn the key bit on
                    q.push( {nx,ny,(cur.mask|(1<<(key[x[nx][ny]]))),cur.steps+1} );
                }
                else if(x[nx][ny] == 'B' || x[nx][ny] == 'Y' || x[nx][ny] == 'R' || x[nx][ny] == 'G'){/// if we are at door
                    if( (cur.mask)&(1<<(key[x[nx][ny]])) ){ /// check if we have the key for this door
                        vis[nx][ny][cur.mask] = 1;
                        q.push( {nx,ny,cur.mask,cur.steps+1} );
                    }
                }
                else if(x[nx][ny] == '.' || x[nx][ny] == 'X' || x[nx][ny] == '*'){/// if we going to exit or empty place
                    vis[nx][ny][cur.mask] = 1;
                    q.push( {nx,ny,cur.mask,cur.steps+1} );
                }
            }
        }
        if(out)
            cout << "Escape possible in " << cur.steps << " steps." << '\n';
        else
            cout << "The poor student is trapped!" << '\n' ;
    }
}
