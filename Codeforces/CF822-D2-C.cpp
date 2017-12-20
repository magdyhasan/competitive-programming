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


struct in{
	int ti, ln, c;
	bool op;
	in(int a, int b, int c, bool d) : ti(a), ln(b), c(c), op(d) {}
	bool operator < (const in& ot){
		if (ti != ot.ti) return ti < ot.ti;
		if (op != ot.op) return op < ot.op;
		return c < ot.c;
	}
};

int mi[maxn];

int main(){
#ifndef ONLINE_JUDGE
	freopen("uva.txt", "rt", stdin);
#endif
	int n, x; scii(n, x);
	int l, r, c;
	vector<in> e;
	lp(i, n){
		scii(l,r); sci(c);	
		e.push_back({ l, r - l + 1, c, 1 });
		e.push_back({ r + 1, r - l + 1, c, 0 });
	}
	sort(e.begin(),e.end());
	int be = 2147483647;
	lp(i, maxn) mi[i] = 2147483647;
	for (auto i : e){
		if (i.op && i.ln < x){
			if (mi[x - i.ln] != 2147483647)
				be = min(be, mi[x - i.ln] + i.c);
		}
		else{
			mi[i.ln] = min(mi[i.ln], i.c);
		}
	}
	printf("%d", be == 2147483647 ? -1 : be);
}

