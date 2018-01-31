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

const int maxn = 300500;


int a[1000500];
ll ans[1000500];


int main(){
#ifndef ONLINE_JUDGE
	freopen("uva.txt", "rt", stdin);
#endif
	int n; sci(n);
	lp(i, n) sci(a[i]);
	ll ret = 0;
	set<int> s; map<int, int> idx;
	lp(i, n){
		auto it = s.lower_bound(a[i]);
		if (it == s.end()){
			ans[i] = a[i] * ll(i+1);
		}
		else{
			int j = idx[*it];
			ans[i] = ans[j] + a[i] * ll(i - j);
		}
		while (!s.empty()){
			it = s.begin();
			if (*it <= a[i]) s.erase(it);
			else break;
		}
		ret += ans[i];
		s.insert(a[i]);
		idx[a[i]] = i;
	}
	s.clear(); idx.clear();
	lp(i, n){
		auto it = s.lower_bound(-a[i]); 
		if (it == s.end()){
			ans[i] = a[i] * ll(i + 1);
		}
		else{
			int j = idx[*it];
			ans[i] = ans[j] + a[i] * ll(i - j);
		}
		while (!s.empty()){
			it = s.begin();
			if (*it <= -a[i]) s.erase(it);
			else break;
		}
		ret -= ans[i];
		s.insert(-a[i]);
		idx[-a[i]] = i;
	}
	printf("%lld", ret);
}

