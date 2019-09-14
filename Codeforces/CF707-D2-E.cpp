/*
 * notice we only have 2000 query and only 2000 gerland
 * so for each garland we add it's position on 2D DS, with add and query rectangle
 * now for each question, if current garland is on during this query we add it
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

const int mN = 2010;
ll BIT[mN][mN];
ll get(int i, int j){
	++i, ++j;
	ll ret = 0;
	while (i){
		int jj = j;
		while (jj){
			ret += BIT[i][jj];
			jj -= jj&-jj;
		}
		i -= i&-i;
	}
	return ret;
}
void add(int i, int j, ll v){
	++i, ++j;
	while (i<mN){
		int jj = j;
		while (jj<mN){
			BIT[i][jj] += v;
			jj += jj&-jj;
		}
		i += i&-i;
	}
}
ll getRect(int x,int y,int x2,int y2){
	return get(x2,y2)-(!y ? 0:get(x2,y-1))-(!x ? 0:get(x-1,y2))+(!x||!y ? 0 : get(x-1,y-1));
}

vector<pair<int,int>> gr[2005];
vector<int> w[2005];

pair<int,int> to[2005], bo[2005];

char st[512];
bool on[2005];
bool iso[2005][2005];
ll ans[2005];

void solve(){
	int n,m,k,ln;
	scii(n,m); sci(k);
	lp(i,k){
		on[i] = 1;
		sci(ln);
		lp(j,ln){
			int x,y,ww; scii(x,y); sci(ww);
			--x; --y;
			gr[i].emplace_back(x,y);
			w[i].emplace_back(ww);
		}
	}
	int q; sci(q);
	int ask = 0;
	lp(i,q){
		scanf("%s",st);
		if(st[0] == 'A'){
			int x,y;
			scii(x,y);
			--x; --y;
			to[ask] = {x,y};
			scii(x,y);
			--x; --y;
			bo[ask] = {x,y};
			lp(j,k) iso[ask][j] = on[j];
			++ask;
		}else{
			int ik; sci(ik);
			--ik;
			on[ik] = !on[ik];
		}
	}
	lp(i,k){
		lp(j,gr[i].size()){
			add(gr[i][j].first,gr[i][j].second,w[i][j]);
		}
		lp(j,ask)if(iso[j][i]){
			ans[j] += getRect(to[j].first,to[j].second,bo[j].first,bo[j].second);
		}
		lp(j,gr[i].size()){
			add(gr[i][j].first,gr[i][j].second,-w[i][j]);
		}
	}
	lp(i,ask) printf("%lld\n",ans[i]);
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
