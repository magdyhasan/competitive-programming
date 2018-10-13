/*
	we can binary search for the answer
	if we're given that minimum between two points at consective intervals is mi
	we first fix the first point at r[0] because it's better than < r[0], 
	as this can give us more space between last point of last interval and this point of the first interval
	as the points are circular

	now after fixing point at la=r[0] and keep in mind we have ha=r[0]-l[0] that we can move in later time,
	now we go to next interval, there are 3 cases:
	1-la + mi - ha > r[i], this means we can never place this point with at least mi distance from last point
	2-la+mi < l[i], just place current point at l[i], as this give us more distance for next points.
	3-la+mi>l[i], just place at la+mi, and now we remember we have min(ha,la+mi-l[i]) avaiable space to move in later times
*/
#include<bits/stdc++.h>
using namespace std;


#define all(v)           ((v).begin()), ((v).end())
#define sz size()
#define clr(v,d)         memset(v,d,sizeof(v))
#define lp(i, n)         for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define sci(a)	scanf("%d",&a)
#define scii(a, b)	scanf("%d%d",&a, &b)
#define pri(a)	printf("%d\n",a)



typedef long long ll;

const int maxn = 500500;


ll m; int n;
ll l[maxn], r[maxn];

bool check(ll mi){
	ll la = r[0];// place first one at most right position
	ll ha = r[0] - l[0];
	ll fp = r[0];
	lpi(i, 1, n){
		if (la + mi - ha > r[i]) return 0; // we can't place place this
		ll cur = la + mi;
		if (cur > r[i]){
			ha -= cur - r[i];
			fp -= cur - r[i];
			la = r[i];
		}
		else
			la = cur;
		ha = min(ha, la - l[i]);
	}
	ll di = m - la + fp;// distance from last point to first one
	return di >= mi;
}


int main(){
	ios::sync_with_stdio(0);
	cin >> m >> n;
	lp(i, n)
		cin >> l[i] >> r[i];
	l[n] = l[0];
	ll bl = 0, br = m, ans = 0;
	while (bl <= br){
		ll mid = bl + (br - bl) / 2;
		if (check(mid)) {
			bl = mid + 1;
			ans = mid;
		}
		else
			br = mid - 1;
	}
	cout << ans;
}