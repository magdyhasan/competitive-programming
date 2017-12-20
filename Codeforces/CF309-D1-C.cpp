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

int me[2000500];
int ha[32], tha[32], need[32];

bool can(int mid){
	lp(i, 32)	 ha[i] = tha[i], need[i] = 0;
	lp(i, mid) need[me[i]]++;
	for (int j = 30; j >= 0; j--){
		if (need[j] > ha[j]) return 0;
		if (j) ha[j - 1] += min(2 * (ha[j] - need[j]),1000500);
	}
	return 1;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("uva.txt", "rt", stdin);
#endif
	int n, m; scii(n, m);
	int s;
	lp(i, n){
		sci(s);
		for (int j = 30; j >= 0; j--)
			tha[j] += (s&(1 << j)) ? 1 : 0;
	}
	lp(i, m){
		sci(me[i]);
	}
	sort(me, me + m);
	int l = 0, r = m, ans = 0;
	while (l <= r){
		int mid = (l + r) >> 1;
		if (can(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	pri(ans);
}

