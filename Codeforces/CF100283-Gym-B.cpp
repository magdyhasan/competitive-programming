/*
  after sorting edges
  notice that when we merge new 2 components it means we're using that edge in all pairs of the 2 compononents as the max edge
  to do this efficently, using DSU we create new vertex when we merge and cost to it
  and then when we want answer we traverse till the root
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

const ll inf = 1LL<<55;
const int maxn = 800500;

int p[maxn], sz[maxn];
ll co[maxn];


int tn;
vector<pair<int,int>> ed[1005];

pair<int,ll> find(int a){
    if(p[a] == a) return {a,co[a]};
    auto cur = find(p[a]);
    co[a] += cur.second;
    p[a] = cur.first;
    return {p[a],co[a]};
}


void un(int a,int b,int edc){
    a = find(a).first; b = find(b).first;
    if(a == b) return;
    int c = ++tn;
    p[a] = p[b] = p[c] = c;
    sz[c] = sz[a] + sz[b];
    co[a] += edc * 1LL * sz[b];
    co[b] += edc * 1LL * sz[a];
}


void solve() {
    int n,m; scii(n,m);
    tn = n;
    lp(e,1005) ed[e].clear();
    lp(i,m){
        int u,v,c; scii(u,v); sci(c);
        ed[c].push_back({u,v});
    }
    lp(i,n*6+1)
        p[i] = i, co[i] = 0, sz[i] = 1;
    lp(e,1005){
        for(auto i:ed[e])
            un(i.first,i.second,e);
    }
    lpi(i,1,n+1) prll(find(i).second);
}


int main(){
    freopen("in.txt","r",stdin);
    int tc = 1;
    sci(tc);
    lp(tt,tc){
        printf("Case %d:\n",tt+1);
        solve();
    }
}

