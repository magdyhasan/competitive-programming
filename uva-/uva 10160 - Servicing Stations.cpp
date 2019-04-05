/*
	backtracking using bitmasks
	
	do some pruning by only considering nodes in order

	and checking if remaining nodes will make constraints applied will reduce time to get AC
	
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define all(v)           ((v).begin()), ((v).end())
#define sz size()
#define clr(v,d)         memset(v,d,sizeof(v))
#define lp(i, n)         for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define sci(a)	scanf("%d",&a)
#define scii(a, b)	scanf("%d%d",&a, &b)
#define scll(a)	scanf("%lld",&a)
#define pri(a)	printf("%d\n",a)
#define prll(a)	printf("%lld\n",a)

const int maxn = 100005;

const int MOD = 1e9 + 7;
typedef pair<int, int> pii;


int n;

ll adj[40];
ll cover[40];

ll mskl;

int ret;

void dfs(int u, int c, ll msk){
	if (c >= ret) return;
	if (msk == mskl) {
		ret = c;
		return;
	}
	if ((cover[u] | msk) != mskl) return;
	lpi(i, u, n + 1) if ((cover[i] | msk) != msk)
		dfs(i + 1, c + 1, msk | adj[i]);
	return;
}


int main(){
	freopen("uva.txt", "r", stdin);
	int m;
	while (scii(n, m)){
		if (!n && !m) break;
		mskl = (2LL << n) - 2;
		int u, v;
		lpi(i, 1, n + 1) adj[i] = 1LL << i;
		lp(i, m){
			scii(u, v);
			adj[u] |= 1LL << v;
			adj[v] |= 1LL << u;
		}
		cover[n] = adj[n];
		lpd(i, n - 1, 1)
			cover[i] = (cover[i + 1] | adj[i]);
		ret = n;
		dfs(1, 0, 0);
		pri(ret);
	}
}