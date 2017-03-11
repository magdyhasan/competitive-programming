/*

	straightforward by using grundy 
	for each pile keep a bitmask of all moves already made on this pile, and try ones you that's not tried yet
	Just xor all grundy of all piles
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

const int maxn = 500500;

int mex(unordered_set<int> &hashtable){
	int val = 0;
	while (hashtable.find(val) != hashtable.end())	val++;
	return val;
}

unordered_map<ll, int> dp[64];

int grundy(ll mask, int nu){
	if (dp[nu].find(mask) != dp[nu].end()) return dp[nu][mask];
	unordered_set<int> hashtable;
	for (int i = 1; i <= nu; i++) if (!(mask&(1LL << i)))
		hashtable.insert(grundy(mask | (1LL << i), nu - i));
	return dp[nu][mask] = mex(hashtable);
}


int main(){
#ifndef ONLINE_JUDGE
	freopen("CF.in", "rt", stdin);
#endif	
	int n; scanf("%d", &n);
	int xorSum = 0, s;
	for (int i = 0; i < n; i++) {
		scanf("%d", &s);
		xorSum ^= grundy(0, s);
	}
	puts(xorSum ? "NO" : "YES");
}