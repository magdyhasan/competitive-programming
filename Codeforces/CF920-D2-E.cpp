/*
  because this about connected components in undirected graph
  let's start from a node, we know which nodes doesn't have edges with this node, which means all other nodes have edges with this node
  but we can't do this naivley for each node or it will be n^2
  Let's keep the set of unused nodes and when we are dfsing some node let's add all other nodes from this set that are not adjacent to this one
  and then remove them from this set, using this idea solution will be n+m
  and we are creating components as maximum as we can which is the answer
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
const int maxn = 1<<22;//2e5+5;
const double EPS = 1e-7;


vector<int> no[maxn], adj[maxn];
set<int> av;
int cn;

void dfs(int u,int p){
    int i = 0;
    ++cn;
    for(int v:av) if(v != p){
        while(i < no[u].size() && no[u][i] < v) ++i;
        if(i == no[u].size() || no[u][i] != v){
            adj[u].push_back(v);
        }else {
            ++i;
        }
    }
    for(auto v:adj[u])
        av.erase(v) ;
    for(auto v:adj[u])
        dfs(v,u) ;
}

void solve() {
    int n,m; scii(n,m);
    lp(i,m){
        int u,v; scii(u,v);
        no[u].push_back(v);
        no[v].push_back(u);
    }
    lpi(i,1,n+1 ) sort(no[i].begin(),no[i].end()), av.insert(i);
    vector<int> cc;
    while(!av.empty()){
        cn = 0;
        int u = *av.begin(); av.erase(av.begin());
        dfs(u, -1);
        cc.push_back(cn);
    }
    sort(cc.begin(),cc.end());
    pri(cc.size());
    for(int i:cc) printf("%d ",i);
}


int main(){
   // freopen("in.txt","r",stdin);
    int tc = 1;
    //sci(tc);
    lp(tt,tc){
//        printf("Case %d:\n",tt+1);
        solve();
    }
}
 
