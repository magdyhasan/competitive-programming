#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

int adj[105][105];
int n,lt;

struct edge{
    int u,v,latency;
    edge (int a,int b,int c) : u(a),v(b),latency(c) {}
};


bool operator <(edge &a,edge &b){
    if(a.u != b.u)
        return a.u < b.u;
    if(a.v != b.v)
        return a.v < b.v;
    return a.latency < b.latency;
}


void solve(){
    vector<edge> ret;
    int e = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
    if(k != i && k != j && adj[i][j] > adj[i][k]+adj[k][j]){ // check if there's an shorter path than what's given
        puts("Need better measurements.\n");
        return;
    }

    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            bool f = 1;
            for(int k=1;k<=n;k++) // check if path from i to j go directly from i t j or through some vertex k
                if(k != i && k != j && adj[i][j] == adj[i][k]+adj[k][j])
                    f = 0;
            if(f && i != j) // if path from i to j
                ret.push_back({i,j,adj[i][j]}), e++;
        }
    sort(ret.begin(),ret.end()); // sort according to problem decryption
    printf("%d\n",e);
    for(auto x:ret)
        printf("%d %d %d\n",x.u,x.v,x.latency);
    puts("");
}

int main(){
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        memset(adj,0,sizeof(adj));
        printf("Case #%d:\n",t);
        scanf("%d",&n);
        for(int i=2;i<=n;i++)
            for(int j=1;j<i;j++){
                scanf("%d",&lt);
                adj[i][j] = adj[j][i] = lt;
            }
        solve();
    }
}
