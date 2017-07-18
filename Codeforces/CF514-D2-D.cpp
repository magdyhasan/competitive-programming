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


struct deque_with_max{
	deque<pair<int, int>> dq;
	void append(int x, int idx){
		while (!dq.empty() && dq.back().first <= x) dq.pop_back();
		dq.push_back({ x, idx });
	}
	void pop_front(int idx){
		while (!dq.empty() && dq.front().second <= idx) dq.pop_front();
	}
	int get_max(){
		if (dq.empty()) return -1234567;
		return dq.front().first;
	}
};


deque_with_max ty[5];

int n, m, k;
int a[maxn][5];
int ret[5];


bool can(int ln){
	lp(i, m)	 ty[i].dq.clear();
	lp(i, n){
		if (i >= ln){
			lp(j, m) ty[j].pop_front(i - ln);
		}
		int  s = 0;
		lp(j, m) ty[j].append(a[i][j], i), s += ty[j].get_max();
		if (i + 1 >= ln && s <= k){
			lp(j, m) ret[j] = ty[j].get_max();
			return 1;
		}
	}
	return 0;
}



int main(){
#ifndef ONLINE_JUDGE
	freopen("CF.in", "rt", stdin);
#endif
	scii(n, m), sci(k);
	lp(i, n) lp(j, m)	 sci(a[i][j]);
	int l = 0, r = n;
	while (l < r){
		int mid = (l + r + 1) / 2;
		if (can(mid)) l = mid;
		else r = mid - 1;
	}
	lp(j, m)
		printf("%d ", ret[j]);
}

