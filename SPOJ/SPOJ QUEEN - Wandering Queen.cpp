/*
	For each cell try to go to all cells in same directions
	for each cell mark in vis[] if you visited this cell before from what direction so if you came from another direction with same cost as an eariler direction, you sitll try this direction
	Like in this case: 
	  012345
	0 F.....
	1 .XXXX.
	2 XX....
	3 S..XX.
	4 ......
	if you reached (2,5) from (2,3) you mark it visited by cost 2 from direction right
	But optimal is from (4,4) with direction up ( if you didn't save direction when you reach it from (4,4) and not check which direction you reached it from, you would skip this direction)
*/

#include<stdlib.h>
#include<stdio.h>
#include<queue>
#include<utility>
using namespace std;


typedef pair<int,int> pos;
#define mp(a,b) make_pair(a,b)
#define X first
#define Y second

// 8-directions
int dx[]={1,1,1,0,0,-1,-1,-1};
int dy[]={-1,0,1,-1,1,-1,0,1};

char x[1005][1005];
int d[1005][1005];
int done[1005][1005];
int n,m,sx,sy,tx,ty;

inline bool valid(int i,int j){
    return (i >= 0 && j >= 0 && i < n && j < m );
}

void solve(){
    queue< pos > q;
    q.push(mp(sx,sy));
    d[sx][sy] = 0;
	done[sx][sy] = 255;
    while(!q.empty()){
        pos u = q.front();
        q.pop();
        if(u.X == tx && u.Y == ty){
            printf("%d\n",d[u.X][u.Y]);
            return;
        }
        for (int i=0;i<8;i++){
            int di =1,nx,ny;
            while(1){
                nx = u.X+dx[i]*di;
                ny = u.Y+dy[i]*di;
                if (valid(nx,ny)&&x[nx][ny]!='X' && !(done[nx][ny]&(1<<i))){
                    if(!done[nx][ny])
					  d[nx][ny] = d[u.X][u.Y]+1, q.push(mp(nx,ny));
					done[nx][ny] |= (1 << i);
                }
                else
                    break;
                di++;
            }
        }
    }
    puts("-1");
    return;
}

int main(){
	freopen("uva.txt", "rt", stdin);
    int tc;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%s",x+i);
            for(int j=0;j<m;j++){
                if(x[i][j] == 'S')
                    sx = i, sy = j;
                if(x[i][j] == 'F')
                    tx = i, ty = j;
                d[i][j] = (1<<30);
                done[i][j] = 0;
            }
        }
        solve();
    }
}
