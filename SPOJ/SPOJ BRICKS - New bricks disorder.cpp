/*
 * it's always better to get character from nearest position (if we have any)
 * so get nearest one, and update range from 0 to this position with 1, because we moved all of them
 * we use BIT for range update and point query
 */
#include <bits/stdc++.h>
using namespace std;


#define all(v)           ((v).begin()), ((v).end())
#define sz size()
#define clr(v,d)         memset(v,d,sizeof(v))
#define lp(i, n)         for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define sci(a)	scanf("%d",&a)
#define scii(a, b)	scanf("%d%d",&a, &b)
#define pri(a)	printf("%d\n",a)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)


const int maxn = 300500;
typedef long long ll;

char a[maxn], b[maxn];
char sw[4];

ll mod = 1LL<<32;

bool g[32][32];
vector<int> po[32];

int bit[maxn];

void update(int idx, int val = 1){
	for (int x = idx; x < maxn; x = (x | (x + 1)))
		bit[x] += val;
}

int query(int idx){
	int ret = 0;
	for (int x = idx; x >= 0; x = ((x&(x + 1)) - 1))
		ret += bit[x];
	return ret;
}


int main() {
	int tc; sci(tc);
	while(tc--){
		scanf("%s%s",a,b);
		clr(g,0);
		clr(bit,0);
		int q; sci(q);
		lp(i,q){
			scanf("%s",sw);

			g[sw[0]-'a'][sw[1]-'a'] = g[sw[1]-'a'][sw[0]-'a'] = 1;
		}
		lp(i,32) po[i].clear();
		int n = strlen(a), m  = strlen(b);
		if(n != m){
			pri(-1); continue;
		}
		lp(i,n) po[a[i]-'a'].push_back(i);
		lp(i,32) reverse(all(po[i]));
		ll ret = 0 ;
		lp(i,n){
			int k = (b[i]-'a');
			if(po[k].empty()){
				ret = -1;
				break;
			}
			int ps = po[k].back(); po[k].pop_back();
			lp(j,32) if((!po[j].empty()) && po[j].back()<=ps&&(!g[j][k])){
				ret = -1;
				break;
			}
			if(ret == -1) break;
			ret = (ret+ps-i+query(ps))%mod;
			//printf("%d %lld\n", ps, ret);
			update(0);
			update(ps+1,-1);
		}
		printf("%lld\n",ret);
	}
}
