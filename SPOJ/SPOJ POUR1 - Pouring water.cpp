#include<stdlib.h>
#include<stdio.h>
#include<map>
#include<queue>
using namespace std;

struct state{
    int a,b;
    state (int a1,int b1) :a(a1),b(b1) {};
};

map<int,map<int,int>> vis;
int A,B,C,na,nb;

void solve(){
    queue<state> q;
    q.push(state{0,0});
    vis[0][0] = 1;
    while(!q.empty()){
        state cur = q.front();
        q.pop();
        if(cur.a == C || cur.b == C){
            printf("%d\n",vis[cur.a][cur.b]-1);
            return;
        }
        // fill a
        na = A, nb = cur.b;
        if(!vis[na][nb])
            vis[na][nb] = vis[cur.a][cur.b]+1, q.push(state{na,nb});
        // fill b
        na = cur.a, nb = B;
        if(!vis[na][nb])
            vis[na][nb] = vis[cur.a][cur.b]+1, q.push(state{na,nb});
        // empty a
        na = 0, nb = cur.b;
        if(!vis[na][nb])
            vis[na][nb] = vis[cur.a][cur.b]+1, q.push(state{na,nb});
        // empty b
        na = cur.a, nb = 0;
        if(!vis[na][nb])
            vis[na][nb] = vis[cur.a][cur.b]+1, q.push(state{na,nb});
        // pour a into b
        na = 0, nb = cur.b+cur.a;
        if(nb > B)
            na = nb-B, nb = B;
        if(!vis[na][nb])
            vis[na][nb] = vis[cur.a][cur.b]+1, q.push(state{na,nb});
        // pour b into a
        na = cur.a+cur.b, nb = 0;
        if(na > A)
            nb = na-A, na = A;
        if(!vis[na][nb])
            vis[na][nb] = vis[cur.a][cur.b]+1, q.push(state{na,nb});
    }
    puts("-1");
}

int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d%d",&A,&B,&C);
        vis = map<int,map<int,int>> ();
        solve();
    }
}
