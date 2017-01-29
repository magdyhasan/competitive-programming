#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;

typedef pair<int,int> pii;
#define mp(a,b) make_pair(a,b)
#define id second
#define flow first


bool vis[50];
int cap[50][50];
int d[50],prv[50];

void match(){
    while(1){
        for(int i=0;i<40;i++)
            d[i] = cap[0][i],prv[i] = 0,vis[i] = 0;

        int cur = 0 ;
        vis[cur] = 0;

        while(1){
            int mx = 0, mxi;
            for(int i=0;i<40;i++)
                if(!vis[i] && d[i] > mx )
                    mx = d[i],mxi = i;
            if(mx == 0 || mxi == 37)
                break;
            cur = mxi, vis[cur] = 1;
            for(int i=0;i<40;i++)
                if(min(d[cur],cap[cur][i]) > d[i])
                    d[i] = min(d[cur],cap[cur][i]), prv[i] = cur;

        }

        if(d[37] == 0)
            break;
        int p = 37;
        while(p != 0){
            cap[prv[p]][p] -= d[37];
            cap[p][prv[p]] += d[37];
            p = prv[p];
        }
    }
    return;
}

bool check(){
    for(int i=1;i<27;i++)
        if(cap[0][i])
            return 0;
    return 1;
}

void solve(){
    match();
    if(check()){
        for(int i=27;i<37;i++){
            bool done = 0;
            for(int j=1;j<27;j++)
                if(cap[i][j])
                    putchar((char)(j+'@')),done = 1;
            if(!done)
                putchar('_');
        }
        puts("");
    }else
        puts("!");
}

int main(){
    //freopen("ci.in","rt",stdin);
    char line[25];
    for(int i=27;i<37;i++)
        cap[i][37] = 1;
    while(gets(line)){
        if(strlen(line) == 0){
            solve();
            memset(cap,0,sizeof(cap));
            for(int i=27;i<37;i++)
                cap[i][37] = 1;
            continue;
        }
        int u = line[0]-'@';
        int nu = line[1]-'0';

        cap[0][u] = nu;
        for(int i=3;line[i] != ';';i++)
            cap[u][(line[i]-'0'+27)] = 1;
    }
    solve();
}
