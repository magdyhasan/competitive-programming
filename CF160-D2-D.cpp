/*
  main idea is that to consider subsets of edges of same weight
  now for a fixed weight, we have some edges:
  -if any edge of this joing any component then answer for this one is at least "at least one"
  -to get the "any" edges, they're just the bridges of the current component graph
  -other edges are "none
*/
#include<bits/stdc++.h>
using namespace std;


#define lp(i, n)         for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define sci(a)	scanf("%d",&a)
#define scll(a)	scanf("%lld",&a)
#define scii(a, b)	scanf("%d%d",&a, &b)
#define pri(a)	printf("%d\n",a)
#define prll(a)	printf("%lld\n",a)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)



const double eps = 1e-8;

typedef  long long ll;

const ll mod = 1e9+7;

const int inf = 1<<30;
const int maxn = 1000500;//2e5+5;
const double EPS = 1e-7;


struct edge{
    int u,v,id;
};


vector<pair<int,int>> adj[maxn];



int p[maxn];

int par(int x){
    return (x == p[x] ? x:p[x]=par(p[x]));
}


vector<edge> e[maxn];

int n;
int dfs_low[maxn], dfs_num[maxn], dfs_n;
int mark[maxn];
int ans[maxn];
int cnt;

void find_bridges(int u, int peid){
    dfs_low[u] = dfs_num[u] = ++dfs_n;
    mark[u] = cnt;
    for (auto [v,vid] : adj[u])	if (vid != peid){
        if (mark[v] != cnt) {
            find_bridges(v, vid);
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
            //printf("%d %d %d\n",u,v,vid);
            if (dfs_low[v] == dfs_num[v]){
               // printf("brdige %d\n",vid);
                ans[vid] = 2;
            }
        }
        else
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
    return;
}

char pr[3][24] = {"none","at least one","any"};

void solve() {
    int m; scii(n,m);
    lp(i,m){
        int u,v,w; scii(u,v); sci(w);
        e[w].push_back({u,v,i});
    }
    lp(i,n+1) p[i] = i;
    lp(we,maxn){
        for(auto ed:e[we]){
            int u = par(ed.u), v= par(ed.v);
            adj[u].clear();
            adj[v].clear();
            if(u!=v){
                ans[ed.id] = 1;
                //printf("at least %d\n",ed.id);
            }
        }
        for(auto ed:e[we]){
            int u = par(ed.u), v= par(ed.v);
            if(u!=v){
                adj[u].push_back({v,ed.id});
                adj[v].push_back({u,ed.id});
            }
        }
        ++cnt; dfs_n = 0;
        for(auto ed:e[we]){
            int u = par(ed.u), v= par(ed.v);
            if(u!=v){
                if(mark[u]!=cnt)
                    find_bridges(u,-1);
                if(mark[v]!=cnt)
                    find_bridges(v,-1);
            }
        }
        for(auto ed:e[we]){
            int u = par(ed.u), v= par(ed.v);
            if(u!=v){
                p[v] = u;
            }
        }
    }
    lp(i,m){
        puts(pr[ans[i]]);
        //pri(ans[i]);
    }
}


int main(){
    freopen("in.txt","r",stdin);
    int tc = 1;
    //sci(tc);
    lp(tt,tc){
//        printf("Case %d:\n",tt+1);
        solve();
    }
}
