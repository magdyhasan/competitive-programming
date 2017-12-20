#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
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

const int maxn = 600500;
int n, m, k;
vector<int> adj[maxn];
int in[maxn], tin[maxn], ret[maxn];
bool fs[maxn];
int co[maxn];


bool cycle(int u){
	co[u] = 0;
	for (int v : adj[u]) if (co[v] != 1){
		if (co[v] == 0 || cycle(v)) return 1;
	}
	co[u] = 1;
	return 0;
}



int main(){
#ifndef ONLINE_JUDGE
	freopen("uva.txt", "rt", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k >> m;
	vector<vector<int>>  a(n,vector<int>(m));
	lp(i, n){
		lp(j, m) cin >> a[i][j];
		fs[a[i][0]] = 1;
	}
	lp(i, n - 1){
		int j = 0;
		while (j < m && a[i][j] == a[i + 1][j]) j++;
		if (j == m){
			cout << -1; return 0;
		}
		adj[a[i][j]].push_back(a[i + 1][j]);
		in[a[i + 1][j]]++; 
	}
	memset(co, -1, sizeof(co));
	for (int i = 0; i < k; i++) if (co[i] == -1){
		if (cycle(i)){
			cout << -1; return 0;
		}
	}
	queue<int> q;
	lp(i, k) {
		if (in[i] == 0)
			q.push(i);
		tin[i] = in[i];
	}
	int cur = 1;
	bool zeroNotFirst = 0;
	while (!q.empty()){
		int u = q.front(); q.pop();
		if (!zeroNotFirst && tin[u] > 0){
			cout << -1; return 0;
		}
		if (!fs[u] && !zeroNotFirst){
			zeroNotFirst = 1;
			ret[u] = 0;
		}
		else
			ret[u] = cur++;
		for (int v : adj[u]) if (--in[v] == 0)
			q.push(v);
	}
	lp(i, k) cout << ret[i] << " ";
}

