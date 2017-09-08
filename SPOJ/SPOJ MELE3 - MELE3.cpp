#include <bits/stdc++.h>
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
#define DB1(a)          std::cout<<#a<<"="<<(a)<<endl
#define DB2(a,b)        std::cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<endl
#define DB3(a,b,c)      std::cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<endl
#define DB4(a,b,c,d)    std::cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<endl
#define DB5(a,b,c,d,e)  std::cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<endl
typedef pair<int, int> pii;
typedef long long ll;
const int  MAX = (int)500 + 5;
const ll  inf = (ll)1e18;
const double EPS = 1e-9;
const int mod = 1000000005;

ll d[1005];
ll cost[1005][1005];

int wait_time(int from, int to, int ct){
	int dis = abs(from - to) * 10, rem;
	if (from<to){
		rem = ct%dis;
		return (dis - rem) % dis;
	}
	else{
		return ct%dis;
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("ci.in", "rt", stdin);
#endif
	cin.sync_with_stdio(false); cin.tie(NULL);

	int k, n;
	cin >> k >> n;
	vector< vector<int> > adj(k + 1);

	lp(i, n){
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
		cost[a][b] = cost[b][a] = abs(b - a) * 5;
	}
	lp(i, 1005)
		d[i] = inf;

	set< pii > s;
	d[1] = 0;
	s.insert({ 0, 1 });
	while (!s.empty()){
		int u = s.begin()->se;
		s.erase(s.begin());
		for (auto x : adj[u]){
			if (d[x] > d[u] + cost[u][x] + wait_time(u, x, d[u])){
				s.erase({ d[x], x });
				d[x] = d[u] + cost[u][x] + wait_time(u, x, d[u]);
				s.insert({ d[x], x });
			}
		}
	}
	cout << d[k];
}