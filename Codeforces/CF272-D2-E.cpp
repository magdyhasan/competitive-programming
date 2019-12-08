/*
  At first consider all vertices belongs to one group
  then find some vertex in this group that have more than 1 friend on this group, and move it to the group
  be repeating this operating we are decrasing number of bad assigments so it will converge
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

int c[maxn], nu[maxn];
vector<int> adj[maxn];


void solve() {
    int n,m; scii(n,m);
    lp(i,m){
        int u,v; scii(u,v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    lpi(i,1,n+1){
        nu[i] = adj[i].size();
        if(nu[i] > 1)
            q.push(i);
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(nu[u] < 2) continue;
        c[u] ^= 1;
        nu[u] = adj[u].size() - nu[u];
        for(auto v:adj[u]){
            if(c[v] == c[u]){
                ++nu[v];
                if(nu[v] == 2) q.push(v);
            } else
                --nu[v];
        }
    }
    lpi(i,1,n+1) putchar('0'+c[i]);
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

