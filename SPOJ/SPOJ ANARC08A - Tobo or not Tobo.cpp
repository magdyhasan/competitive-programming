#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<queue>
using namespace std;


int vis[9][9][9][9][9][9][9][9][9];
struct board{
    int nu[9];
    board (){}
    board(int a,int b,int c,int d,int e,int f,int g,int h,int i){
        nu[0] = a;
        nu[1] = b;
        nu[2] = c;
        nu[3] = d;
        nu[4] = e;
        nu[5] = f;
        nu[6] = g;
        nu[7] = h;
        nu[8] = i;
    }
};

int da[]={0,1,3,4};
int db[]={1,2,4,5};
int dc[]={3,4,6,7};
int dd[]={4,5,7,8};

char str[11];
int moves;
int mx = 0;

void solve(){
    queue< board > q;
    q.push(board{0,1,2,3,4,5,6,7,8}); // starting board
    vis[0][1][2][3][4][5][6][7][8] = 1;
    while(!q.empty()){
        board u = q.front();
        q.pop();
        for(int k=0;k<4;k++){
            int ta = da[k], tb = db[k], tc = dc[k], td = dd[k];
            board v = u;

            v.nu[ta] = u.nu[tc]; // rotate clockwise
            v.nu[tb] = u.nu[ta];
            v.nu[tc] = u.nu[td];
            v.nu[td] = u.nu[tb];

            if(!vis[v.nu[0]][v.nu[1]][v.nu[2]][v.nu[3]][v.nu[4]][v.nu[5]][v.nu[6]][v.nu[7]][v.nu[8]]){ // check if vis
                vis[v.nu[0]][v.nu[1]][v.nu[2]][v.nu[3]][v.nu[4]][v.nu[5]][v.nu[6]][v.nu[7]][v.nu[8]]
                = vis[u.nu[0]][u.nu[1]][u.nu[2]][u.nu[3]][u.nu[4]][u.nu[5]][u.nu[6]][u.nu[7]][u.nu[8]]+1,
                q.push(v);
                mx = max(mx,vis[v.nu[0]][v.nu[1]][v.nu[2]][v.nu[3]][v.nu[4]][v.nu[5]][v.nu[6]][v.nu[7]][v.nu[8]]);
            }
            v = u;

            v.nu[ta] = u.nu[tb]; // rotate anti-clockwise
            v.nu[tb] = u.nu[td];
            v.nu[tc] = u.nu[ta];
            v.nu[td] = u.nu[tc];
            if(!vis[v.nu[0]][v.nu[1]][v.nu[2]][v.nu[3]][v.nu[4]][v.nu[5]][v.nu[6]][v.nu[7]][v.nu[8]]){ // check if vis
                vis[v.nu[0]][v.nu[1]][v.nu[2]][v.nu[3]][v.nu[4]][v.nu[5]][v.nu[6]][v.nu[7]][v.nu[8]]
                = vis[u.nu[0]][u.nu[1]][u.nu[2]][u.nu[3]][u.nu[4]][u.nu[5]][u.nu[6]][u.nu[7]][u.nu[8]]+1,
                q.push(v);
                mx = max(mx,vis[v.nu[0]][v.nu[1]][v.nu[2]][v.nu[3]][v.nu[4]][v.nu[5]][v.nu[6]][v.nu[7]][v.nu[8]]);
            }
        }
    }
    return;
}

int main(){
    //freopen("ci.in","rt",stdin);
    int tc = 0;
    solve(); // generate all possible moves
    while(scanf("%s",str) && str[1] > '0'){
        moves = str[0]-'0';
        board v;
        for(int i=1;i<10;i++) // get the number of the board
            v.nu[i-1] = (str[i]-'0'-1);
        int ts = vis[v.nu[0]][v.nu[1]][v.nu[2]][v.nu[3]][v.nu[4]][v.nu[5]][v.nu[6]][v.nu[7]][v.nu[8]];
        ts--;
        if(ts > moves)
            printf("%d. %d\n",++tc,-1);
        else
            printf("%d. %d\n",++tc,ts);
    }
}
