/*
  store queries at each vertex
  now build segment tree over euler walk 
  now dfs the tree, when going through an edge, two things happen.
  -we move away from all other nodes that's not children of us, we can do that range update with segment tree
  -all our children, we move close to them, thus we decrase distance to them by that edge, again by segment tree
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

const int maxn = 500500;


int n,q;

vector<pair<int,int>> adj[maxn];
int in[maxn], ou[maxn];
ll w[maxn];
bool leaf[maxn];
int id = 1;

ll segT[maxn * 4], lazy[maxn * 4];

void push(int idx,int l,int r){
    if (lazy[idx]){
        segT[idx] += lazy[idx];
        if (l != r){
            lazy[idx << 1] += lazy[idx];
            lazy[(idx << 1) | 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }
}

void updateSeg(int x, int y, int v, int idx = 1, int l = 1, int r = n){
    push(idx, l, r);
    if (x > r || y < l) return;
    if (x <= l && y >= r){
        lazy[idx] += v;
        push(idx, l, r);
        return;
    }
    int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
    updateSeg(x, y, v, lidx, l, mid);
    updateSeg(x, y, v, ridx, mid + 1, r);
    segT[idx] = min(segT[lidx], segT[ridx]);
}

ll querySeg(int x, int y, int idx = 1, int l = 1, int r = n){
    if (x > r || y < l) return 9223372036854775807LL;
    push(idx, l, r);
    if (x <= l && y >= r) return segT[idx];
    int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
    return min(querySeg(x, y, lidx, l, mid), querySeg(x, y, ridx, mid + 1, r));
}

void build(int idx = 1, int l = 1, int r = n){
    if (l == r){
        segT[idx] = w[l];
        return;
    }
    int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
    build(lidx, l, mid);
    build(ridx, mid + 1, r);
    segT[idx] = min(segT[lidx], segT[ridx]);
}


void dfs(int u, ll we,int p = -1){
    if(adj[u].size() == 1 && u != 1)
        leaf[u] = 1;
    in[u] = id;
    w[u] = leaf[u]?we:1e17;
    ++id;
    for(auto v:adj[u]) if(v.first != p)
        dfs(v.first,we+v.second,u);
    ou[u] = id - 1;
}

vector<pair<int,pair<int,int>>> qs[maxn];
ll ans[maxn];

void rec(int u,int p = -1) {
    for(auto i:qs[u]){
        ans[i.first] = querySeg(i.second.first,i.second.second);
    }
    for(auto v:adj[u]) if(v.first != p){
        updateSeg(1,n,v.second);
        updateSeg(in[v.first],ou[v.first],-2LL*v.second);
        rec(v.first,u);
        updateSeg(1,n,-v.second);
        updateSeg(in[v.first],ou[v.first],2LL*v.second);
    }
}

void solve(){
    scii(n,q);
    lpi(i,2,n+1){
        int p,w;
        scii(p,w);
        adj[p].emplace_back(i,w);
        adj[i].emplace_back(p,w);
    }
    dfs(1,0);
    build();
    lp(i,q){
        int v,l,r;
        sci(v); scii(l,r);
        qs[v].push_back({i,{l,r}});
    }
    rec(1);
    lp(i,q) prll(ans[i]);
}


int main() {
    freopen("in.txt","r",stdin);
    int tc;
    //sci(tc);
    tc = 1;
    lp(tt,tc){
        //printf("Case #%d: ",tt+1);
        solve();
    }
}
