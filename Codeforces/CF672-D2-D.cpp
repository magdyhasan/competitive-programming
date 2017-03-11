/*
	Notice increment and decrement operations cen be done seperatly, can't really prove that.

	so by using binary search we find the minimum value all nodes will have after k increment operations
	after finding minimum value update all numbers, we can have < n-1 more operations ( because if we have more, the binary search would've ncrement minimum vlaue)
	
	Do same for decrement operation and find max value after k operations
*/

#include <bits/stdc++.h>
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
const int  inf = (int)1e9;
const double EPS = 1e-9;
const ll mod = 1000000007ll;


const int  maxn = (int)500000 + 10;

int n, k;
int arr[maxn];

int main(){
#ifndef ONLINE_JUDGE
	freopen("CF.in", "rt", stdin);
#endif
	scii(n, k);
	lp(i, n)
		sci(arr[i]);
	int l = 0, r = INT_MAX, mid;
	ll s = 0;
	while (l < r) {
		mid = l + (r - l) / 2;
		if (mid == l)	mid++;
		s = 0;
		lp(i, n) s += max(0, mid - arr[i]);
		if (s <= k) l = mid;
		else r = mid - 1;
	}
	s = k;
	lp(i, n) s -= max(0, l - arr[i]), arr[i] = max(arr[i], l);
	lp(i, n) if (arr[i] == l && s) s--, arr[i]++;
	l = 0, r = INT_MAX;
	while (l < r) {
		mid = l + (r - l) / 2;
		s = 0;
		lp(i, n) s += max(0, arr[i] - mid);
		if (s <= k) r = mid;
		else l = mid + 1;
	}
	s = k;
	lp(i, n) s -= max(0, arr[i] - l), arr[i] = min(arr[i], l);
	lp(i, n) if (arr[i] == l && s) s--, arr[i]--;
	pri(*max_element(arr, arr + n) - *min_element(arr, arr + n));
}