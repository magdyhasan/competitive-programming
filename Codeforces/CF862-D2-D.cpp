/*
	make string of length n with all 1's and get it's hamming distance
	then change first 1 to 0, if hamming distance increases then first position is 1, else first position is 0

	to find the opposite letter from what we found already, we use BS in range 1000, so <= 10 steps
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

int qu(string &st){
	cout << "? " << st << "\n";
	fflush(stdout);
	int ham; cin >> ham;
	return ham;
}

int main(){
	int n; cin >> n;
	int pos0, pos1;
	string s(n, '1');
	int ham = qu(s);
	s[0] = '0';
	int ham2 = qu(s);
	s[0] = '1';
	if (ham2 < ham){
		pos0 = 1;
		int l = 0, r = n-1;
		while (l < r){
			int mid = (l + r + 1) >> 1;
			for (int i = mid; i <= r; i++) s[i] = '0';
			int hamc = qu(s);
			for (int i = mid; i <= r; i++) s[i] = '1';
			if (ham - hamc != (r - mid + 1)) l = mid;
			else r = mid - 1;
		}
		pos1 = l+1;
		printf("! %d %d", pos0, pos1);
		fflush(stdout);
		return 0;
	}
	else{
		pos1 = 1;
		lp(i, n) s[i] = '0';
		ham = qu(s);
		int l = 0, r = n - 1;
		while (l < r){
			int mid = (l + r + 1) >> 1;
			for (int i = mid; i <= r; i++) s[i] = '1';
			int hamc = qu(s);
			for (int i = mid; i <= r; i++) s[i] = '0';
			if (ham-hamc != (r-mid+1)) l = mid;
			else r = mid - 1;
		}
		pos0 = l + 1;
		printf("! %d %d", pos0, pos1);
		fflush(stdout);
		return 0;
	}
}