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

char s[maxn], t[maxn];
int lp[maxn], rp[maxn];
int cnt[27][maxn];

int main(){
#ifndef ONLINE_JUDGE
	freopen("CF.in", "rt", stdin);
#endif
	scanf("%s%s", s, t);
	int n = strlen(s);
	int m = strlen(t);
	// compute lp
	int j = 0;
	for (int i = 0; i < n; i++){
		lp[i] = j;
		if (j < m && s[i] == t[j]) j++;
	}
	// compute rp
	j = m;
	for (int i = n - 1; i >= 0; i--){
		rp[i] = j;
		if (j > 0 && s[i] == t[j - 1]) j--;
	}
	// compute cnt
	for (int c = 0; c < 26; c++) for (int i = 0; i < m; i++)
		cnt[c][i + 1] = cnt[c][i] + (c + 'a' == t[i]);
	//try each position i
	bool f = 1;
	for (int i = 0; i < n; i++){
		if (lp[i] + 1 < rp[i]){
			f = 0;
			break;
		}
		int l = max(0, rp[i] - 1), r = min(m - 1, lp[i]);
		if (cnt[s[i] - 'a'][r + 1] - cnt[s[i] - 'a'][l] <= 0){
			f = 0;
			break;
		}
	}
	puts(f ? "Yes" : "No");
}
