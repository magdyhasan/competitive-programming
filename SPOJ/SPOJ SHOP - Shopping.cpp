#include<stdlib.h>
#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
using namespace std;

typedef pair<int,pair<int,int>> ppi;
#define mp(a,b,c) make_pair(a,make_pair(b,c))
#define cost first
#define X second.first
#define Y second.second

char x[26][26];
int d[26][26];
int n,m,sx,sy;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

inline bool isValid(int i,int j){
    return (i >=0 && j >= 0 && i < n && j < m && x[i][j] != 'X');
}

void dijkstra(){
    priority_queue< ppi , vector<ppi> , greater<ppi> > q;
    q.push(mp(0,sx,sy));
    d[sx][sy] = 0; // we are in start with cost 0
    while(!q.empty()){
        ppi u = q.top();
        q.pop();
        if(d[u.X][u.Y] < u.cost) // if there's a way to u better than this one
            continue;

        for(int i=0;i<4;i++){ // try four directions
            int nx = u.X+dx[i];
            int ny = u.Y+dy[i];
            if(x[nx][ny] == 'D'){ // if we reached destination
                printf("%d\n",u.cost);
                return;
            }
            if(isValid(nx,ny) && d[nx][ny] > u.cost+(x[nx][ny]-'0'))
                d[nx][ny] = u.cost+(x[nx][ny]-'0'), q.push(mp(d[nx][ny],nx,ny));
        }
    }
}

int main(){
    while(scanf("%d%d",&m,&n)){
        if(n == 0 && m == 0)
            break;
        for(int i=0;i<n;i++){
            scanf("%s",x+i);
            for(int j=0;j<m;j++){
                if(x[i][j] == 'S')
                    sx = i, sy = j; // get start position
                d[i][j] = (1<<30); // initial value for all cells with inf
            }
        }
        dijkstra();
    }
}
