#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define all(v)           ((v).begin()), ((v).end())
#define sz size()
#define clr(v,d)         memset(v,d,sizeof(v))
#define rep(i, v)        for(int i=0;i<(v).sz;++i)
#define lp(i, n)         for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define sci(a)	scanf("%d",&a)
#define scii(a, b)	scanf("%d%d",&a, &b)
#define pri(a)	printf("%d\n",a)
#define prii(a, b)	printf("%d %d\n",a, b)
#define DB1(a)          std::cout<<#a<<"="<<(a)<<endl
#define DB2(a,b)        std::cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<endl
#define DB3(a,b,c)      std::cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<endl
#define DB4(a,b,c,d)    std::cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<endl
#define DB5(a,b,c,d,e)  std::cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<endl
typedef pair<int, int> pii;
typedef long long ll;
const ll  inf = 1000000000000000000LL;
const double EPS = 1e-9;
const ll mod = 1000000007ll;
#define PI acos(-1)



const int  maxn = (int)100500 + 10;

set<ll> st;

void BFS(map<pair<int, int>, int> &d, map<ll, pair<int, int>> &f, int a, int b){
	queue < pair<int, int> > q;
	q.push({ a, b });
	d[{a, b}] = 0;
	while (!q.empty()){
		int ta = q.front().first, tb = q.front().second;
		st.insert(ll(ta)*ll(tb));
		f[ll(ta)*ll(tb)] = { ta, tb };
		int tc = d[{ta, tb}];
		q.pop();
		if (ta % 2 == 0 && d.find({ ta / 2, tb }) == d.end())
			d[{ta / 2, tb}] = tc + 1, q.push({ ta / 2, tb });
		if (tb % 2 == 0 && d.find({ ta, tb / 2 }) == d.end())
			d[{ta, tb / 2}] = tc + 1, q.push({ ta, tb / 2 });
		if (ta % 3 == 0 && d.find({ ta / 3 * 2, tb }) == d.end())
			d[{ta / 3 * 2, tb}] = tc + 1, q.push({ ta / 3 * 2, tb });
		if (tb % 3 == 0 && d.find({ ta, tb / 3 * 2 }) == d.end())
			d[{ta, tb / 3 * 2}] = tc + 1, q.push({ ta, tb / 3 * 2 });
	}
	return;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("CF.in", "rt", stdin);
#endif	
	int a1, b1, a2, b2;
	scii(a1, b1), scii(a2, b2);
	map<pair<int, int>, int> d1, d2;
	map<ll, pair<int, int>> f1, f2;
	BFS(d1, f1, a1, b1);
	BFS(d2, f2, a2, b2);
	vector<ll> tr(st.begin(), st.end());
	int ret = 123456789, ra1, rb1, ra2, rb2;
	for (ll i : tr)
		if (f1.find(i) != f1.end() && f2.find(i) != f2.end()){
		int tra1 = f1[i].first, trb1 = f1[i].second, tra2 = f2[i].first, trb2 = f2[i].second;
		if (ret > d1[{tra1, trb1}] + d2[{tra2, trb2}])
			ret = d1[{tra1, trb1}] + d2[{tra2, trb2}], ra1 = tra1, rb1 = trb1, ra2 = tra2, rb2 = trb2;
		}
	if (ret == 123456789) pri(-1);
	else printf("%d\n%d %d\n%d %d", ret, ra1, rb1, ra2, rb2);
}