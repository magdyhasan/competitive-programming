/*
	first notice that we can order the bits whatever we want
	some observations after some tracing:
	-number of bits in all numbers must be even
	-maximum number of bits in element must be <= sum of bits in all other numbers in this range

	counting ranges for first condition is easy, what about second one ?
	notice that a[i] > 0 for all elements in array, i.e, all elements have at least one bit
	so we can see if we're in range with length > around 62 ellemtns we will have sum of bits > 61
	and no element will have more than 61 bits

	so let's first count all ranges satisfy first condition
	now we counted ranges that violates second condition
	but we now that this elements have  length of ranges < 62, so for each i, we loop for 62 and subtract
	element that satisfy first condition and violate second
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define all(v)           ((v).begin()), ((v).end())
#define sz size()
#define clr(v,d)         memset(v,d,sizeof(v))
#define lp(i, n)         for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define sci(a)	scanf("%d",&a)
#define scl(a)	scanf("%lld",&a)
#define scii(a, b)	scanf("%d%d",&a, &b)
#define pri(a)	printf("%d\n",a)
#define prl(a)	printf("%lld\n",a)


const int maxn = 1000500;

ll b[maxn], a[maxn];

int cnt(ll x){
	int ret = 0;
	for (int i = 62; i >= 0; i--){
		ret += ((x >> i) & 1LL);
	}
	return ret;
}

ll cn[maxn][2];

int main(){
	int n; sci(n);
	lp(i, n)	 scl(b[i]);
	lp(i, n) a[i] = cnt(b[i]);
	cn[n][0] = 1;
	ll ret = 0, curs = 0;
	for (int i = n - 1; i >= 0; i--){
		curs += a[i];
		ret += cn[i + 1][curs % 2];
		cn[i][0] = cn[i + 1][0];
		cn[i][1] = cn[i + 1][1];
		++cn[i][curs % 2];
		int s = 0, mx = 0;
		for (int j = i; j < n && j - i < 66; j++){
			s += a[j];
			mx = max(1ll*mx, a[j]);
			if (mx>s - mx && !(s & 1)) ret--;
		}
	}
	prl(ret);
}