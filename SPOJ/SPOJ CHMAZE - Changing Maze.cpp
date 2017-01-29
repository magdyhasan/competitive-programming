#include<stdlib.h>
#include<stdio.h>
#include<queue>
#include<utility>
using namespace std;

const int inf = (int)1e9;

char maze[12][22][22]; // first diminision
int d[12][22][22];
int n,m,pat,ca;

typedef pair<int,pair<int,int> > ppii;
#define mp(a,b,c) make_pair(a,make_pair(b,c))
#define x second.first
#define y second.second

int dx[] = {1,-1,0,0,0};
int dy[] = {0,0,1,-1,0};

inline bool isValid(int i,int j){
    return (i >=0 && j >= 0 && i < n && j < m);
}

int main(){
    while(scanf("%d%d%d",&n,&m,&pat)){
        int i,j,p;
        if(n == 0 && m == 0 && pat == 0)
            break;
        for(p=0;p<pat;p++)
            for(i=0;i<n;i++)
                scanf("%s",maze[p][i]);
        for(p=0;p<12;p++)
            for(i=0;i<22;i++)
                for(j=0;j<22;j++)
                    d[p][i][j] = inf;
        queue<ppii> q;
        q.push(mp(0,0,0));
        d[0][0][0] = 0;
        int out = -1;
        while(!q.empty()){ // just normal BFS to try all moves
            ppii cur = q.front();
            q.pop();
            if(cur.x == n-1 && cur.y == m-1){
                out = d[cur.first][cur.x][cur.y];
                break;
            }
            int nx,ny,np;
            for(i=0;i<5;i++){
                nx = cur.x + dx[i];
                ny = cur.y + dy[i];
                np = (cur.first+1)%pat;
                if(isValid(nx,ny) && maze[np][nx][ny] != '1' && d[cur.first][cur.x][cur.y]+1 < d[np][nx][ny]){
                    d[np][nx][ny] = d[cur.first][cur.x][cur.y]+1;
                    q.push(mp(np,nx,ny));
                }
            }
        }
        if(out == -1)
            printf("Case %d: Luke and Leia cannot escape.\n",++ca);
        else
            printf("Case %d: Luke and Leia can escape in %d steps.\n",++ca,out);
    }
}
