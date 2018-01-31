/*
	notice that we can fix each height since we only taking it's maxium across all

	now check if it's possible using this max height, by checking min(h,w) > h means we can't use this height, 

	now given height, we first check if it's w or h > current_height and use it

	else we sort according to max_difference between w-h and add as much as we can <= n/2
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


int w[maxn], h[maxn];
int n;

bool ch(int mxh){
	int cnt = 0;
	lp(i, n){
		if (min(w[i], h[i]) > mxh) return 0;
		else if (h[i] > mxh) cnt++;
	}
	return cnt <= n / 2;
}
bool v[1005];

int main(){
#ifndef ONLINE_JUDGE
	freopen("uva.txt", "rt", stdin);
#endif	
	sci(n);
	lp(i, n) scii(w[i], h[i]);
	int l = 0, r = 1000, mh = 0;
	while (l <= r){
		int mid = (l + r) >> 1;
		if (ch(mid)) r = mid - 1, mh = mid;
		else l = mid + 1;
	}
	int ret = 2147483647;
	for (mh=0; mh <= 1000; mh++){
		memset(v, 0, sizeof(v));
		int cnt = 0; int wi = 0;
		lp(i, n) if (min(h[i], w[i]) > mh) cnt = n;
		lp(i, n) {
			if (h[i] > mh){
				wi += h[i];
				cnt++;
				v[i] = 1;
			}
			else if (w[i] > mh){
				wi += w[i];
				v[i] = 1;
			}
			else if (w[i] <= h[i]){
				wi += w[i];
				v[i] = 1;
			}
		}
		if (cnt > n / 2)continue;
		vector<pair<int, pii> > vec;
		lp(i, n) if (!v[i]) vec.push_back({ w[i] - h[i], { w[i], h[i] } });
		sort(vec.begin(), vec.end(), greater<pair<int, pii>>());
		for (auto i : vec){
			if (cnt >= n / 2) wi += i.second.first;
			else cnt++, wi += i.second.second;
		}
		ret = min(ret, mh*wi);
	}
	pri(ret);
}
