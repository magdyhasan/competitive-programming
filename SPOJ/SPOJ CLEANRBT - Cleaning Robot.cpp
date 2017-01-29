/**
    BFS/bitMasking
*/
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<utility>
#include<map>
using namespace std;

typedef pair<int,pair<int,int>> piii;
#define X first
#define Y second.first
#define dirt second.second
#define mp(a,b,c) make_pair(a,make_pair(b,c))

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

map<int,int> id[25];
int n,m,d[25][25][2049],sx,sy,dirty; // 2049 becayse we have 10 option for dirties ( 2^10 ) bits for each dirty id
char x[25][25];

inline bool isValid(int i,int j){
    return (i >= 0 && j >= 0 && i < n && j < m);
}


int main(){
    while(scanf("%d%d",&m,&n)){
        if(n == 0 && m == 0)
            break;
        dirty = 0;
        int bit = 0;
        for(int i=0;i<25;i++)
            id[i].clear();
        for(int i=0;i<n;i++){
            scanf("%s",x+i);
            for(int j=0;j<m;j++){
                if(x[i][j] == 'o')
                    sx = i, sy = j;
                else if(x[i][j] == '*'){
                    bit |= (1<<dirty);  // turn this dirty bits on
                    id[i][j] = dirty++; // give this dirty at [i][j] an idea
                }
                for(int k=0;k<2049;k++) // initialize d
                    d[i][j][k] = (1<<30);
            }
        }
        queue<piii> q; // normal BFS
        q.push(mp(sx,sy,bit));
        d[sx][sy][bit] = 0;
        bool done = 0;
        while(!q.empty()){
            piii cur = q.front();
            q.pop();
            if(cur.dirt == 0 ){ // if we cleared all dirties we are done
                printf("%d\n",d[cur.X][cur.Y][cur.dirt]);
                done = 1;
                break;
            }
            for(int k=0;k<4;k++){ // try four directions
                int nx = cur.X + dx[k];
                int ny = cur.Y + dy[k];
                int ndirt = cur.dirt;
                if(!isValid(nx,ny) || x[nx][ny] == 'x')
                    continue;
                if(x[nx][ny] == '*'){ // if we are going to dirty cell
                    if(ndirt&(1<<(id[nx][ny]))) // if we haven't already cleaned it already
                        ndirt &= ~(1<<(id[nx][ny])); // clear it ( turn it's bit off )
                }
                if(d[nx][ny][ndirt] > d[cur.X][cur.Y][cur.dirt]+1)
                    d[nx][ny][ndirt] = d[cur.X][cur.Y][cur.dirt]+1, q.push(mp(nx,ny,ndirt));
            }
        }
        if(!done)
            puts("-1");
    }
}
