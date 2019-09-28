/*
  just go through the tree, keep current cost, now we have remaining rem = T-2*cost because we have to get back to root
  now standing at root u, with rem we need to know how much cookies we can eat, and we need to take smaller t[i] first
  this subproblem can be solved with range DS
  let's store all avaiable cookies with time t[i] at t[i] index in the tree
  now we can BS for max range we can take, or just using BIT in logn 
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


const int maxn = 1<<20;

typedef long long ll;
const ll mod = 1e9+7;


ll bit[maxn], cnt[maxn];

void update(int idx, ll v, ll cn){
    for (int x = idx; x < maxn; x += (x & -x))
        bit[x] += v, cnt[x] += cn;
}

ll query(ll x){
    int i = 0;
    ll ret = 0;
    for (int len = (1<<19); len; len >>= 1) {
        if (i+len < maxn && x >= bit[i + len]) {
            x -= bit[i += len];
            ret += cnt[i];
        }
    }
    if(i+1<maxn)
        ret += x/(i+1);
    return ret;
}

vector<pair<int,ll>> adj[maxn];
ll x[maxn];
ll t[maxn];
ll T;

ll dp[maxn];

void dfs(int u,ll su){
    update(t[u],t[u]*1LL*x[u],x[u]);
    dp[u] = query(T-su);
    priority_queue<ll> pq;
    for(auto v:adj[u]){
        dfs(v.first,su+2LL*v.second);
        pq.push(dp[v.first]);
    }
    if(!pq.empty()){
        if(u == 1) dp[u] = max(dp[u],pq.top());
        else{
            pq.pop();
            if(!pq.empty())
                dp[u] = max(dp[u],pq.top());
        }
    }
    update(t[u],-t[u]*1LL*x[u],-x[u]);
}

int main() {
    //  freopen("in.txt","r",stdin);
    int n;  sci(n);
    scll(T);
    lpi(i,1,n+1) scll(x[i]);
    lpi(i,1,n+1) scll(t[i]);
    lpi(i,2,n+1){
        int p; sci(p);
        ll co; scll(co);
        adj[p].emplace_back(i,co);
    }
    dfs(1,0);
    prll(dp[1]);
    return 0;
}
