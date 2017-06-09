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


char st[maxn];
int cnt[10], cnt2[10];
int tcnt[10], tcnt2[10];

int main(){
#ifndef ONLINE_JUDGE
	freopen("CF.in", "rt", stdin);
#endif
	scanf("%s", st);
	int n = strlen(st);
	int be = -1;
	vector<int> br1, br2;
	for (int i = 0; i < n; i++) cnt[st[i] - '0']++, cnt2[st[i] - '0']++;
	bool c = 0;
	for (int a = 0; a < 10; a++) for (int b = 0; b < 10; b++) if (a + b == 10 && cnt[a] > 0 && cnt2[b] > 0){
		c = 1;
		deque<int> r1, r2;
		for (int i = 0; i < 10; i++) tcnt[i] = cnt[i], tcnt2[i] = cnt2[i];
		r1.push_back(a), r2.push_back(b), tcnt[a]--, tcnt2[b]--;
		int cur = 0;
		for (int i = 9; i >= 0; i--) for (int j = 9; j >= 0; j--) if (i + j == 9){
			while (tcnt[i] > 0 && tcnt2[j] > 0)
				r1.push_back(i), r2.push_back(j), tcnt[i]--, tcnt2[j]--, cur++;
		}
		while (tcnt[0] && tcnt2[0]) r1.push_front(0), r2.push_front(0), tcnt[0]--, tcnt2[0]--;
		if (cur > be){
			be = cur;
			br1.assign(r1.begin(), r1.end());
			br2.assign(r2.begin(), r2.end());
			for (int i = 0; i < 10; i++) {
				while (tcnt[i] > 0)	{
					br1.push_back(i);
					tcnt[i]--;
				}
				while (tcnt2[i] > 0)	{
					br2.push_back(i);
					tcnt2[i]--;
				}
			}
		}
	}
	if (!c){
		for (int i = 0; i < 10; i++) while (cnt[i] > 0) br1.push_back(i), cnt[i]--;
		for (int i = 0; i < 10; i++) while (cnt2[i] > 0) br2.push_back(i), cnt2[i]--;
	}
	reverse(br1.begin(), br1.end());
	reverse(br2.begin(), br2.end());
	for (int i : br1) printf("%d", i);
	puts("");
	for (int i : br2) printf("%d", i);
}
