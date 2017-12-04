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


int h[maxn], s[maxn], e[maxn];
int qh[maxn], qt[maxn];
bool done[maxn];

struct no{
	int ti, id;
	bool s, q;
	no(int a, int b, bool c, bool d) : ti(a), id(b), s(c), q(d) {}
	bool operator < (const no &a) const {
		if(ti != a.ti) return ti < a.ti;
		if(q != a.q) return q < a.q;
		return s < a.s;
	}
};
bool ret[maxn];

int main(){
	freopen("uva.txt", "r", stdin);
	int H, C, Q; 
	scanf("%d%d%d", &H, &C, &Q);
	int hi, si, ei, ti;
	vector<no> vec;
	for (int i = 0; i < C; i++){
		scanf("%d%d%d", &h[i], &s[i], &e[i]);
		vec.push_back({ s[i], i, 1, 0 });
		vec.push_back({ e[i]+1, i, 0, 0 });
	}
	lp(i, Q){
		scanf("%d%d", qh + i, qt + i);
		vec.push_back({ qt[i], i, 0, 1 });
	}
	sort(vec.begin(), vec.end());
	priority_queue<pii> pq;
	for (auto i : vec){
		if (i.q){
			int mx = -1;
			while (!pq.empty()){
				if (!done[pq.top().second]){
					mx = pq.top().first;
					break;
				}
				else
					pq.pop();
			}
			ret[i.id] = (qh[i.id] > mx);
		}
		else{
			if (i.s) pq.push({ h[i.id], i.id });
			else done[i.id] = 1;
		}
	}
	lp(i, Q) puts(ret[i] ? "YES" : "NO");
}

