/*
	Let's look at each posslible l in f(l,r)
	if we now on l and we looking for how many r can make f(l,r) give unique number
	we know all numbers <= 1e6, so <= 2^20, so all possible bits in all numbers <= 1e6 is 20 bits
	so if we at l, we can have at most 20 different r where f(l,r) will be different,
	because the only way to make f(l,r) different is by making one bit of current number of f(l,oldr) change

	to do this fast, we keep an array nxt[1e5][21], where nxt[i][j], represent what index after i will have jth bits on
	and use this to iterate to next smallest position where a new bit will be open
*/
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


int a[maxn];
int nxt[maxn][32];
bool ha[8000500];

int main(){
#ifndef ONLINE_JUDGE
	freopen("uva.txt", "rt", stdin);
#endif
	int n; sci(n);
	lp(i, n) sci(a[i+1]);
	for (int i = n; i > 0; i--){
		lp(j, 32) {
			if ((1 << j)&a[i]) nxt[i][j] = i;
			else nxt[i][j] = nxt[i + 1][j];
		}
	}
	for (int i = 1; i <= n; i++){
		if (a[i] == 0) ha[0] = 1;
		int cur = 0, curi = i;
		while (true){
			int nxti = 123456789;
			lp(j, 32) if (!((1 << j)&cur) && nxt[curi][j]){
				nxti = min(nxti, nxt[curi][j]);
			}
			if (nxti == 123456789) break;
			cur |= a[nxti];
			curi = nxti;
			ha[cur] = 1;
		}
	}
	int ret = 0;
	for (int i = 0; i < 8000500; i++) 
		ret += ha[i];
	printf("%d", ret);
}

