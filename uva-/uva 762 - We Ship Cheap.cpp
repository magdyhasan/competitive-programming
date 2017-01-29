#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<map>
#include<vector>
#include<string>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
#define MAX 1111

map<string,int> id;
string cities[MAX];
vector< vector<int> > adj(MAX);
int n,m,u,v,d[MAX],prv[MAX];
char a[MAX],b[MAX];

void solve(){
    for(int i=0;i<=n;i++)
        d[i] = (1<<30), prv[i] = -1;

    queue<int> q; // BFS
    q.push(u);
    d[u] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(cur == v)
            break;
        for(auto x:adj[cur])
            if(d[x] == (1<<30))
                q.push(x), d[x] = d[cur]+1, prv[x] = cur;
    }
    if(d[v] == (1<<30)) // if no path for v
        puts("No route");
    else{
        vector< pair<int,int> > path;
        while(prv[v] != -1){ // reconstruct path from u to v
            path.push_back({prv[v],v});
            v = prv[v];
        }
        reverse(path.begin(),path.end());
        for(auto x:path)
            printf("%s %s\n",cities[x.first].c_str(),cities[x.second].c_str());
    }
}

int main(){
    int tc = 0;
    while(scanf("%d",&m)!=EOF){
        adj = vector< vector<int> > (MAX);
        id.clear();
        if(tc++)
            puts("");
        n = 0;
        while(m--){
            scanf("%s%s",a,b);
            if(id.count(string(a)) == 0 ) // make an idea for the city
                id[string(a)] = n, cities[n++] = string(a);
            if(id.count(string(b)) == 0 )
                id[string(b)] = n, cities[n++] = string(b);

            u = id[string(a)];
            v = id[string(b)];
            adj[u].push_back(v); // make bidirectional edge
            adj[v].push_back(u);
        }
        scanf("%s%s",a,b);

        if(id.count(string(a)) == 0 )
            id[string(a)] = n, cities[n++] = string(a);
        if(id.count(string(b)) == 0 )
            id[string(b)] = n, cities[n++] = string(b);

        u = id[string(a)];
        v = id[string(b)];
        solve();
    }
}
