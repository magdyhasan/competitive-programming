/*
 * because size of query string is < 11 but it repeats
 * we can have one BIT for each query size [1,10]
 * but we also need to know which index in the query size
 * and which character, this all 10*10*4
 * so we can have this number of BIT's and solve for each one independtly
 * and now problem is basic usage of BIT
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


const int maxn = 1e5+50;
typedef long long ll;

int bit[10][10][4][maxn];

int get(char c){
  if(c == 'A')return 0;
  if(c == 'T')return 1;
  if(c == 'G')return 2;
  if(c == 'C')return 3;
  return 4;
}


void update(int si,int rem, int ch, int idx, int delta){
	for (; idx<maxn; idx |= (idx + 1))
		bit[si][rem][ch][idx] += delta;
}

int query(int si,int rem, int ch, int idx){
	ll sum = 0;
	for (; idx >= 0; idx = (idx & (idx + 1)) - 1)
		sum += bit[si][rem][ch][idx];
	return sum;
}

char st[maxn], wo[64];


void solve(){
	scanf("%s",st);
	int ln = strlen(st);
	//puts("done");
	for(int i=0;i<ln;i++){
		lp(j,10){
			update(j,i%(j+1),get(st[i]),i,1);
		}
	}
	int q; sci(q);
	while(q--){
		int ty, idx, l, r; sci(ty);
		if(ty == 1){
			scanf("%d%s",&idx,wo);
			--idx;
			lp(j,10){
				update(j,idx%(j+1),get(st[idx]),idx,-1);
			}
			st[idx] = wo[0];
			lp(j,10){
				update(j,idx%(j+1),get(st[idx]),idx,1);
			}
		}else{
			scii(l,r);
			scanf("%s",wo);
			int qsz = strlen(wo);
			int ret = 0;
			--l; --r;
			lp(i,qsz){
				ret += query(qsz-1,(l+i)%qsz,get(wo[i]),r);
				ret -= query(qsz-1,(l+i)%qsz,get(wo[i]),l-1);
			}
			pri(ret);
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
