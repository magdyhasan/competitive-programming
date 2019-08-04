/*
 *	We need to connect each 2 consective 'g' with a chain
 *	now we solve for b and r independently
 *	we connect all b's and then remove biggest gap to make it like tree connected to g chain
 *
 *	a corner case if we might don't make chain between g's and instead connect all r's and b's
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


const int maxn = 600500;
typedef long long ll;

vector<ll> p[2];


void solve(){
	ll gmx=-1e14, gmi = 1e14;
	ll rmx=-1e14, rmi = 1e14;
	ll bmx=-1e14, bmi = 1e14;
	ll lg = -1e14;
	int n; cin >> n;
	ll ret = 0, po;
	char ty;
	for(int i=0;i<=n;i++){
		if(i < n) cin >> po >> ty;
		else po = 1e14, ty = 'G';
		if(ty == 'G'){
			if(i<n){
				gmx = max(gmx,po);
				gmi = min(gmi,po);
			}
			ll c1 = po - lg, c2 = (po-lg) * 2;
			if(c1 >= 1e12) c1 = 0;
			lp(j,2) if(!p[j].empty()){
				c1 += po - lg;
				ll mxgap = max(p[j].front()-lg,po-p[j].back());
				for(int it=0;it+1<p[j].size();it++)
					mxgap = max(mxgap,p[j][it+1]-p[j][it]);
				c1 -= mxgap;
				p[j].clear();
			}
			ret += min(c1,c2);//handle corner case
			lg = po;
		}else if(ty == 'R'){
			p[0].push_back(po);
			rmx = max(rmx,po);
			rmi = min(rmi,po);
		}else{
			p[1].push_back(po);
			bmx = max(bmx,po);
			bmi = min(bmi,po);
		}
	}
	if(gmi > gmx){// if no g's
		ret = 0;
		if(rmi < rmx) ret += rmx-rmi;
		if(bmi < bmx) ret += bmx-bmi;
	}
	cout << ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	int tc;
	//sci(tc);
	tc = 1;
	while(tc--){
		solve();
		puts("");
	}
}
