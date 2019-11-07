/*
  to answer each query we need to know 2 things
  1-if the node recieved the document(v) and they query node(u) in the same component
  2-if the node recieved the document is in subtree of the query node
  
  -1 can be solved easily by builiding DSU on the fly
  -2 let's read all edges and build euler tour of the graph, arrays in[u], ou[u]
  now we just need to check that in[v]>=in[u] && ou[v]<=ou[u], which mean v is in subtree of node u
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


const int maxn = 500500;
const double eps = 1e-8;

typedef  long long ll;

const ll mod = 1e9+7;

int p[maxn];
int par(int x){
    return (x == p[x] ? x:p[x] = par(p[x]));
}


int ty[maxn];
int x[maxn], y[maxn];

vector<int> adj[maxn];
vector<int> doc, qs[maxn];
int docId[maxn];
int in[maxn], ou[maxn], ans[maxn];
int tim;


void dfs(int u){
    in[u] = ++tim;
    for(int v:adj[u])
        dfs(v);
    ou[u] = tim;
}

bool pa(int u, int v) {
    return (in[v]>=in[u] && ou[v]<=ou[u]);
}

void solve() {
    int n,m; scii(n,m);
    lp(i,n+1) p[i] = i;
    lp(i,m){
        sci(ty[i]);
        if(ty[i] == 1){
            scii(x[i],y[i]);
            adj[y[i]].push_back(x[i]);
            p[x[i]] = y[i];
        }else if(ty[i] == 2){
            sci(x[i]);
            docId[i] = doc.size();
            doc.push_back(i);
        }else{
            scii(x[i],y[i]);
            qs[y[i]-1].push_back(i);
        }
    }
    lpi(i,1,n+1) if(par(i) == i)
        dfs(i);
    lp(i,n+1) p[i] = i;
    lp(i,m){
        if(ty[i] == 1){
            p[par(x[i])] = par(y[i]);
        }else if(ty[i] == 2) {
            int u = x[i];
            for(int j:qs[docId[i]]){
                ans[j] = (par(x[j]) == par(u) && pa(x[j],u));
            }
        }
    }
    lp(i,m){
        if(ty[i] == 3){
            puts(ans[i] ? "YES":"NO");
        }
    }
}


int main(){
    freopen("in.txt","r",stdin);
    int tc = 1;
    //sci(tc);
    while(tc--){
        solve();
    }
}
