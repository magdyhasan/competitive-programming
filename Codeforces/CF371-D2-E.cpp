/*
first it's see that answer will be consective range of k points after sorting the points

but how to test all such k groups after sorting points in O(n)

it might seem straightfoward to minimize range of first point and last point, but consider this

|*...*...*....*|
|*.*........*.*|

in this case if we calculate the distance between pairs the second one is less, although range of first and last point is same in both

but we can do this with sliding windows

first let's calculate k points ditances after sorting points

for each new point we add x*i distance and subtract previous points distance
where x is current point and i is number of previous points

after constructing this windows, it's easy to iterate through other windows with same logic
*/
#include <bits/stdc++.h>	
using namespace std;


#define all(v)           ((v).begin()), ((v).end())
#define sz size()
#define clr(v,d)         memset(v,d,sizeof(v))
#define lp(i, n)         for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define sci(a)	scanf("%d",&a)
#define scll(a)	scanf("%lld",&a)
#define scii(a, b)	scanf("%d%d",&a, &b)
#define pri(a)	printf("%d\n",a)
#define prll(a)	printf("%lld\n",a)


const int maxn = 300500;

typedef long long ll;

struct node{
	ll x;
	int id;
	node() {}
	bool operator < (const node ot) const{
		if (x != ot.x) return x < ot.x;
		return id < ot.id;
	}
} a[maxn];

ll x[maxn];
ll su[maxn];

int main() {
	int n; sci(n);
	lp(i, n)	 {
		scll(x[i]);
		a[i].x = x[i] + 1e9;
		a[i].id = i + 1;
	}
	int k; sci(k);
	sort(a, a + n);

	ll dif = 1e18, ans = 0;
	ll cur = 0;
	lp(i, n) su[i + 1] = su[i] + a[i].x;// calculate prefix sum
	lp(i, k) cur += a[i].x*i - (su[i]);// calculate first window
	dif = cur;
	for (int i = k; i < n; i++){
		int j = i - k;// point to remove
		cur -= (su[i] - su[j + 1]) - a[j].x*(k - 1);// remove point from the left
		cur += a[i].x * (k - 1) - (su[i] - su[j + 1]);// add new point
		if (cur < dif){
			ans = i - k + 1;
			dif = cur;
		}
	}
	lp(i, k) printf("%d ", a[ans + i].id);
}