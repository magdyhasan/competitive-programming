/*
 * when going from top to down, save sum of current path
 * now for given node, we need to know how many nodes on path
 * from root to node have path sum <= a[u]
 * we can do that using binary search
 */
#include <bits/stdc++.h>
using namespace std;


#define all(v)          ((v).begin()), ((v).end())
#define sz size()
#define clr(v,d)         memset(v,d,sizeof(v))
#define lp(i, n)         for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define sci(a)	scanf("%d",&a)
#define scii(a, b)	scanf("%d%d",&a, &b)
#define pri(a)	printf("%d\n",a)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)


const int maxn = 2e5+50;
typedef long long ll;

int a[maxn];
int n;

vector<pair<int,int>> adj[maxn];

int ret[maxn];
ll su[maxn], st[maxn];

void rec(int u,int de, ll s){
	st[de] = u;
	su[de] = s;
	int l = lower_bound(su,su+de+1,s-a[u])-su-1;
	--ret[st[l]]; ++ret[u];
	for(auto v:adj[u]){
		rec(v.first,de+1,s+v.second);
		ret[u] += ret[v.first];
	}
}


void solve(){
	sci(n);
	lp(i,n) sci(a[i+1]);
	lp(i,n-1){
		int pi, wi; scii(pi,wi);
		adj[pi].emplace_back(i+2,wi);
	}
	su[0] = -(1LL<<60);
	rec(1,1,0);
	lp(i,n) printf("%d ",ret[i+1]-1);
}

int main() {
	freopen("in.txt","r",stdin);
	int tc;
	//sci(tc);
	tc = 1;
	while(tc--){
		solve();
		puts("");
	}
}
