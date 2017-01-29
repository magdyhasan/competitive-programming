/*
    idea: BFS with multi-sources to all other positions so we find all SP for all 0's positions from all 1's positions
    .. it's just the same as the normal BFS (1-m) but here instead of pushing 1 position ( source ) we push all 1's positions
*/
#include<stdlib.h>
#include<stdio.h>
#include<queue>
#include<map>
#include<utility>
#include<cstring>
using namespace std;

#define X first
#define Y second
#define mp(a,b) make_pair(a,b)

const int inf = (int)1e9;

char x[200][200];

int n,m;
int d[200][200];

int dx[]={1,-1,0,0}; // move in four directions
int dy[]={0,0,1,-1};


int main(){
    int T,i,j,k;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            scanf("%s",&x[i]); // read each row as a string
        queue< pair< int,int > > q;
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                if(x[i][j] == '1') // we push all the ones so we can do BFS from multi-sources
                    d[i][j] = 0,q.push(mp(i,j));
                else
                    d[i][j] = inf; // initialize all distance to inf
        while(!q.empty()){
            pair<int,int> cur = q.front();
            q.pop();
            for(k=0;k<4;k++){ // go in four directions
                int nx = cur.X+dx[k];
                int ny = cur.Y+dy[k];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && d[nx][ny] > d[cur.X][cur.Y]+1 ){ // if we have better distance for the next position
                    d[nx][ny] = d[cur.X][cur.Y]+1;
                    q.push(mp(nx,ny));
                }
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++)
                printf("%d ",d[i][j]);
            puts("");
        }
    }
}
