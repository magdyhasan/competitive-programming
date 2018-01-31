/*
	note that we only have n-1 ones

	since we want all ones below the main diagonal (i > j )
	it will always be better to sort number in non-increasing number of ones in this columns

	since n <= 1000
	we can now iterate over all rows and try to find row satsaify our condition, which always will be found
	because of sorted columns
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

int a[1005][1005];
int tr[1005];


int main(){
#ifndef ONLINE_JUDGE
	freopen("uva.txt", "rt", stdin);
#endif
	int n; sci(n);
	int s = 0;
	lp(i, n - 1){
		int x, y; scii(x, y);
		a[x - 1][y - 1] = 1;
	}
	vector < pair<int, pair<int, int>>> ret;
	vector<int> colcnt;
	lp(j, n){
		int cnt = 0;
		lp(i, n)	 cnt += a[i][j];
		colcnt.push_back(cnt);
	}
	lp(j, n){
		int mx = colcnt[j], mxi = j;
		for (int k = j + 1; k < n; k++){
			if (colcnt[k] > mx){
				mx = colcnt[k];
				mxi = k;
			}
		}
		if (mxi != j){
			ret.push_back({ 2, { j + 1, mxi + 1 } });
			swap(colcnt[mxi], colcnt[j]);
			lp(k, n) tr[k] = a[k][mxi];
			lp(k, n) a[k][mxi] = a[k][j];
			lp(k, n) a[k][j] = tr[k];
		}
	}
	lp(i, n-1){
		s = 0;
		lp(j, n) if (j >= i && a[i][j]){
			s = 1; break;
		}
		if (s == 0) continue;
		int k = i + 1;
		for (;; k++){
			s = 0;
			lp(j, n) if (j >= i && a[k][j]) {
				s = 1; break;
			}
			if (s) continue;
			ret.push_back({ 1, { i + 1, k + 1 } });
			lp(j, n) tr[j] = a[i][j];
			lp(j, n) a[i][j] = a[k][j];
			lp(j, n) a[k][j] = tr[j];
			break;
		}
	}
	pri(ret.size());
	for (int i = 0; i < ret.size(); i++)
		printf("%d %d %d\n", ret[i].first, ret[i].second.first, ret[i].second.second);
}

