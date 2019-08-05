/*
 * since our queries are on subtree we can build euler tour of tree
 * now our queries is just range update and query, we can do this easily with segment tree with lazy update
 * each node will save mask of current colors in this node and count of this mask is our answer
 *
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


const int maxn = 400500;
typedef long long ll;



ll segT[maxn * 4], lazy[maxn * 4];
int a[maxn];
int tn;

void push(int idx,int l,int r){
	if (lazy[idx] != -1){
		segT[idx] = lazy[idx];
		if (l != r){
			lazy[idx << 1] = lazy[idx];
			lazy[(idx << 1) | 1] = lazy[idx];
		}
		lazy[idx] = -1;
	}
}

void updateSeg(int x, int y, ll v, int idx = 1, int l = 0, int r = tn - 1){
	push(idx, l, r);
	if (x > r || y < l) return;
	if (x <= l && y >= r){
		lazy[idx] = v;
		push(idx, l, r);
		return;
	}
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	updateSeg(x, y, v, lidx, l, mid);
	updateSeg(x, y, v, ridx, mid + 1, r);
	segT[idx] = segT[lidx] | segT[ridx];
}

ll querySeg(int x, int y, int idx = 1, int l = 0, int r = tn - 1){
	if (x > r || y < l) return 0;
	push(idx, l, r);
	if (x <= l && y >= r) return segT[idx];
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	return querySeg(x, y, lidx, l, mid) | querySeg(x, y, ridx, mid + 1, r);
}
int c[maxn];



vector<int> adj[maxn];

int timer;
int tin[maxn*2], tout[maxn*2];


void dfs(int u=1,int p=-1){
	++timer;
	tin[u] = timer;
	for(auto v:adj[u]) if(v!=p)
		dfs(v,u);
	tout[u] = timer;
}



struct qs{
	int ty,v,c;
} q[maxn];

void solve(){
	int n,m;
	scii(n,m);
	lpi(i,1,n+1) sci(c[i]);
	lp(i,n-1){
		int u,v; scii(u,v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	tn = timer+1;
	//lpi(i,1,n+1) printf("%d %d %d\n",i,tin[i],tout[i]);
	memset(lazy,-1,sizeof(lazy));
	lpi(i,1,n+1)
		updateSeg(tin[i],tin[i],1LL<<c[i]);
	lp(i,m){
		sci(q[i].ty);
		if(q[i].ty == 1){
			scii(q[i].v,q[i].c);
			updateSeg(tin[q[i].v],tout[q[i].v],1LL<<q[i].c);
		}else{
			sci(q[i].v);
			int ret = 0;
			ll ans = querySeg(tin[q[i].v],tout[q[i].v]);
			lpi(j,1,61) ret += ((ans>>(j))&1);
			printf("%d\n",ret);
		}
	}
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
