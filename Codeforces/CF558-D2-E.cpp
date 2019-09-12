/*
 * using counting sort we can solve problem easily if udpates was on small ranges
 *
 * because updates we need segment tree with lazy updates
 *
 * for each character we keep one segment tree and update accordinly
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


int n;
int segT[maxn * 4][26], lazy[maxn * 4][26];

char s[maxn];

void push(int idx, int j,int l,int r){
	if (lazy[idx][j] != -1){
		segT[idx][j] = lazy[idx][j] * (r-l+1);
		if (l != r){
			lazy[idx << 1][j] = lazy[idx][j];
			lazy[(idx << 1) | 1][j] = lazy[idx][j];
		}
		lazy[idx][j] = -1;
	}
}

void updateSeg(int x, int y, int v, int j, int idx = 1, int l = 0, int r = n - 1){
	push(idx, j, l, r);
	if (x > r || y < l) return;
	if (x <= l && y >= r){
		lazy[idx][j] = v;
		push(idx, j, l, r);
		return;
	}
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	updateSeg(x, y, v, j, lidx, l, mid);
	updateSeg(x, y, v, j, ridx, mid + 1, r);
	segT[idx][j] = segT[lidx][j] + segT[ridx][j];
}

ll querySeg(int x, int y, int j, int idx = 1, int l = 0, int r = n - 1){
	if (x > r || y < l) return 0;
	push(idx, j, l, r);
	if (x <= l && y >= r) return segT[idx][j];
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	return querySeg(x, y, j, lidx, l, mid) + querySeg(x, y, j, ridx, mid + 1, r);
}

void build(int idx = 1, int l = 0, int r = n - 1){
	if (l == r){
		lp(j,26)
			 lazy[idx][j] = -1;
		segT[idx][s[l]-'a']=1;
		return;
	}
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	build(lidx, l, mid);
	build(ridx, mid + 1, r);
	lp(j,26)
		lazy[idx][j] = -1, segT[idx][j] = segT[lidx][j] + segT[ridx][j];
}

void get(int j, int idx = 1, int l = 0, int r = n - 1){
	push(idx, j, l, r);
	if(!segT[idx][j]) return;
	if (l == r){
		//puts("inget");
		s[l] = j+'a';
		return;
	}
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	get(j, lidx, l, mid);
	get(j, ridx, mid + 1, r);
}

void solve(){
	int q; scii(n,q);
	scanf("%s",s);
	build();
	int l,r,f;
	int cnt[26];
	while(q--){
		scii(l,r); sci(f);
		--l; --r;
		lp(j,26)
			cnt[j] = querySeg(l,r,j);
		int p = l;
		if(!f) p = r;
		lp(j,26)if(cnt[j]){
			updateSeg(l,r,0,j);
			if(f){
				updateSeg(p,p+cnt[j]-1,1,j);
				p += cnt[j];
			}else{
				updateSeg(p-cnt[j]+1,p,1,j);
				p -= cnt[j];
			}
		}
	}
	lp(j,26)
		get(j);
	puts(s);
}

int main() {
	freopen("in.txt","r",stdin);
	int tc;
	//sci(tc);
	tc = 1;
	while(tc--){
		solve();
		//puts("");
	}
}
