/*
  Let's binary search for the minimum edge values 
  to check this value build graph with edges > k and do topological sort to find if we can make it DAG
  once we find k, let's build graph with topoligical sort and give each node order id
  for remaining edges with value <= k, check if by adding this edge we make cycke and we might reverse it 
*/
#include <bits/stdc++.h>
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



typedef long long ll;

const ll mod = 1e6+3;

const int maxn = 300500;

struct edge{
    int u,v,c;
} ed[maxn];

vector<int> adj[maxn];
bool vi[maxn], ac[maxn];
int n,m;

bool dfs(int u){
    vi[u] = ac[u] = 1;
    for(int v:adj[u]) {
        if(ac[v] || dfs(v))
            return 1;
    }
    ac[u] = 0;
    return 0;
}

bool ch(int k){
    lp(i,n+1) adj[i].clear(), vi[i] = ac[i] = 0;
    lp(i,m) if(ed[i].c>k){
            adj[ed[i].u].push_back(ed[i].v);
        }
    lpi(i,1,n+1) if(!vi[i]){
            if(dfs(i)) return 0;
        }
    return 1;
}

int in[maxn], ord[maxn];

void topo(int k){
    lp(i,n+1) adj[i].clear(), in[i] = 0;
    lp(i,m) if(ed[i].c>k){
        adj[ed[i].u].push_back(ed[i].v);
        in[ed[i].v]++;
    }
    queue<int> q;
    lpi(i,1,n+1) if(in[i]==0)
        q.push(i);
    int cn = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        ord[u] = ++cn;
        for (int v:adj[u])
            if (--in[v] == 0) {
                q.push(v);
            }
    }
}

int main() {
    freopen("in.txt","r",stdin);
    scii(n,m);
    lp(i,m){
        scii(ed[i].u,ed[i].v);
        sci(ed[i].c);
    }
    int l = 0, r = 1e9+50, k = -1;
    while(l<=r){
        int mi = l+(r-l)/2;
        if(ch(mi)) r = mi-1, k = mi;
        else l = mi + 1;
    }
    topo(k);
    vector<int> rv;
    lp(i,m) if(ed[i].c <= k){
        if(ord[ed[i].u]>ord[ed[i].v])
            rv.push_back(i+1);
    }
    printf("%d %d\n",k,rv.size());
    for(int i:rv) printf("%d ",i);
}
















