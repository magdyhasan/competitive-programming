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



typedef pair<bool, pii> state;

char st[1000];
bool avachar[27];
vector<char> chs;
map<string, int> num;
map<string, state> dp;
string sst[30];
int n;



state rec(string s){
	if (dp.find(s) != dp.end()) return dp[s];
	state &ret = dp[s];
	ret = { 0, { 0, 0 } };
	for (char ch : chs) for (int di = 0; di < 2; di++){
		string ns;
		if (di == 1) ns = s + ch;
		else ns = ch + s;
		if (num.find(ns) != num.end()){
			int mx = -1, sum = 0;
			for (char ch2 : ns) mx = max(mx, (ch2 - 'a' + 1)), sum += (ch2 - 'a' + 1);
			state nret = rec(ns);
			nret.second.first += sum*mx + num[ns];
			//ret = max(ret, state{ 1 ^ nret.fi, pii{ -nret.se.se + sum*mx + num[ns], -nret.se.fi } });
			if ((!ret.fi && !nret.fi) || (ret.fi != nret.fi && nret.se.fi > ret.se.fi)
				|| (ret.fi != nret.fi && nret.se.fi == ret.se.fi && nret.se.se < ret.se.se))
				ret = nret, ret.first = !nret.first;
		}
	}
	int tt = ret.second.first;
	ret.second.first = ret.second.second, ret.second.second = tt;
	return ret;
}


int main(){
#ifndef ONLINE_JUDGE
	freopen("CF.in", "rt", stdin);
#endif
	sci(n);
	lp(i, n){
		scanf("%s", st);
		sst[i] = st;
		int ln = strlen(st);
		lp(j, ln) avachar[st[j] - 'a'] = 1;
		string s(st);
		set<string> sub;
		lp(j, ln){
			string cur = "";
			for (int k = j; k < ln; k++){
				cur += st[k];
				sub.insert(cur);
			}
		}
		for (string ss : sub)
			if (num.find(ss) != num.end()) num[ss]++;
			else num[ss] = 1;
	}
	lp(i, 27) if (avachar[i]) chs.push_back(i + 'a');
	state ret = rec("");
	puts(ret.first ? "First" : "Second");
	printf("%d %d", ret.second.second, ret.second.first);
}

