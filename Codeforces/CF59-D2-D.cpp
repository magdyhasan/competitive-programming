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

const int maxn = 500500;

int ra[maxn];
map<int, int> rra;

int ord[3][maxn];
int pr[maxn];

int main(){
#ifndef ONLINE_JUDGE
	freopen("CF.in", "rt", stdin);
#endif	
	int n;	 sci(n);
	lpi(i, 1, n * 3 + 1) sci(ra[i]), rra[ra[i]] = i;
	lp(i, n) scii(ord[0][i], ord[1][i]), sci(ord[2][i]);
	int K; sci(K);
	for (int i = 0; i < n; i++) for (int j = 0; j < 3; j++) if (ord[j][i] == K){
		bool g = true;
		vector<int> curT;
		for (int k = 0; k < 3; k++) if (k != j){
			curT.push_back(ord[k][i]);
			if (rra[ord[j][i]] > rra[ord[k][i]]) g = 0;
		}
		if (g){
			set<int> fis, sec;
			if (curT[0] < curT[1]) swap(curT[0], curT[1]);
			for (int it = 0; it <= i; it++) for (int k = 0; k < 3; k++) if (ord[k][it] != K){
				if (ord[k][it] <= curT[0])	fis.insert(ord[k][it]);
				else sec.insert(ord[k][it]);
			}
			for (int it : fis) printf("%d ", it);
			for (int it = i + 1; it < n; it++) for (int k = 0; k < 3; k++) sec.insert(ord[k][it]);
			for (int it : sec) printf("%d ", it);
		}
		else
			for (int it = 1; it <= 3 * n; it++) if (it != K)
				printf("%d ", it);
		return 0;
	}
}