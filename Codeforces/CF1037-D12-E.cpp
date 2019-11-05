/*
  Let's start from end, and instead remove edges instead of adding them
  Let's have a set of(deg[u],u), now if smallest vertex in this set < k, then remove it
  and decrement all nodes adjacent to this node
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

vector<pair<int,int>> adj[maxn];


int deg[maxn];
int a[maxn], b[maxn];
bool rm[maxn];
set<pair<int,int>> s;
int k;


void sub(int v){
    if(deg[v]<k) return ;
    auto it = s.find({deg[v],v});
    int td = it->first, tv = it->second;
    s.erase(it);
    s.insert({--deg[v],v});
}

void ex(){
    while(!s.empty()){
        int d = (*s.begin()).first, u = (*s.begin()).second;
        if(d >= k) return ;
        s.erase(s.begin());
        for(auto v:adj[u]) if(!rm[v.second]){
            sub(v.first);
            rm[v.second] = 1;
        }
    }
}


int ans[maxn];
void p(){
    puts("-----------------------------");
    for(auto i:s){
        printf("%d %d\n",i.second,i.first);
    }
    puts("");
}

void solve() {
    int n,m; scii(n,m); sci(k);
    lp(i,m){
        scii(a[i],b[i]);
        adj[a[i]].emplace_back(b[i],i);
        adj[b[i]].emplace_back(a[i],i);
        deg[a[i]]++;
        deg[b[i]]++;
    }
    lp(i,n)
        s.insert({deg[i+1],i+1});
    ex();
    for(int i=m-1;i>=0;i--){
        ans[i] = s.size();
        if(!rm[i]){
            rm[i] = 1;
            sub(a[i]);
            sub(b[i]);
            ex();
        }
    }
    lp(i,m) pri(ans[i]);
}


int main(){
    freopen("in.txt","r",stdin);
    int tc = 1;
    //sci(tc);
    while(tc--){
        solve();
    }
}
