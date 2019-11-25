/*
  Let's build a graph, where nodes are possible starting/ending points of ramps and from 0 and l
  we can run dijktra to find answer
  problem is we need to compress points
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
const int maxn = 2e5+5;


int x[maxn], d[maxn],t[maxn],p[maxn];

vector<int> po;

struct ed{
    int to,co,id;
};

pair<int,int> pa[maxn];
vector<ed> adj[maxn];

ll di[maxn];

void solve() {
    int n,l; scii(n,l);
    lp(i,n){
        scii(x[i],d[i]); scii(t[i],p[i]);
        po.push_back(x[i]+d[i]);
        if(x[i]-p[i]> -1){
            po.push_back(x[i]-p[i]);
        }
    }
    po.push_back(0); po.push_back(l);
    sort(po.begin(),po.end());
    po.erase(unique(po.begin(),po.end()), po.end());
    lpi(i,1,po.size()){
        adj[i-1].push_back({i,po[i]-po[i-1],-1});
        adj[i].push_back({i-1,po[i]-po[i-1],-1});
    }
    lp(i,n)if(x[i]-p[i]>=0){
        int a = lower_bound(po.begin(),po.end(),x[i]-p[i])-po.begin();
        int b = lower_bound(po.begin(),po.end(),x[i]+d[i])-po.begin();
        adj[a].push_back({b,t[i]+p[i],i});
    }
    fill(di,di+maxn,1LL<<60);
    di[0] = 0;
    priority_queue<pair<ll,int>> pq;
    pq.push({0,0});
    while(!pq.empty()){
        int u = pq.top().second; ll co = -pq.top().first;
        pq.pop();
        if(co != di[u]) continue;
        for(auto e:adj[u]) if(di[e.to] > co+e.co){
            di[e.to] = co + e.co;
            pq.push({-di[e.to],e.to});
            pa[e.to] = {u,e.id};
        }
    }
    prll(di[po.size()-1]);
    vector<int> path;
    for(int i=po.size()-1;i;i=pa[i].first){
        if(pa[i].second!=-1){
            path.push_back(pa[i].second);
        }
    }
    pri(path.size());
    reverse(path.begin(),path.end());
    for(int i:path)
        printf("%d ",i+1);
}


int main(){
    freopen("in.txt","r",stdin);
    int tc = 1;
    //sci(tc);
    lp(tt,tc){
        //printf("Case %d:\n",tt+1);
        solve();
    }
}

