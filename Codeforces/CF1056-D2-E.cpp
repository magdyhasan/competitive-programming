/*
	brute-force the length of string r0, and get len of r1 from it

	for fixed length we can iterate through string t,
	we have to take length r0 from string t from it's current index

	then we simply check if this give same r0 for all positions of '0' 
	and same r1 for all '1'

	notice that because we only have 0,1 on string s, number of valid r0 will be very small 
*/
#include<functional>
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


const int maxn = 2000500;

typedef long long ll;

template<ll MOD>
ll norm(ll x) {
	x %= MOD;
	if (x < 0) {
		x += MOD;
	}

	return x;
}

const ll M1 = static_cast<ll>(1000002637);
const ll M2 = static_cast<ll>(1000002649);

struct hs {
	ll l; ll r;

	hs(ll cl, ll cr) : l(norm<M1>(cl)), r(norm<M2>(cr)) {}
	hs(ll x = 0) : l(x), r(x) {}

	hs operator + (const hs& rhs) const {
		return{ l + rhs.l, r + rhs.r };
	}

	hs operator * (const hs& rhs) const {
		return{ l * rhs.l, r * rhs.r };
	}

	hs operator - (const hs& rhs) const {
		return{ l - rhs.l, r - rhs.r };
	}

	bool operator != (const hs& rhs) const {
		return l != rhs.l || r != rhs.r;
	}
};

hs h[maxn], pw[maxn];
hs ba = 56;

hs getSub(int l, int r){
	return pw[l] * (h[r] - h[l]);
}



char s[maxn], t[maxn];

int main() {
	//freopen("in.in", "r", stdin);
	pw[0] = 1;
	scanf("%s%s", s, t);
	int n = strlen(s), m = strlen(t);
	lp(i, m + 1) pw[i + 1] = pw[i] * ba;
	lp(i, m) h[i + 1] = h[i] + pw[m - i] * (t[i] - 'a' + 1);
	int c0 = 0;
	lp(i, n) c0 += s[i] == '0';
	int c1 = n - c0;
	int ret = 0;
	hs s1, s2;
	for (int l0 = 1; l0*c0 < m; l0++){
		int l1 = (m - l0*c0) / c1;
		if (l1*c1 + l0*c0 != m) continue;
		int si = 0;
		bool f = 1;
		bool f1 = 0, f2 = 0;
		lp(i, n){
			if (s[i] == '0'){
				hs hsv = getSub(si, si + l0);
				si += l0;
				if (!f1) f1 = 1, s1 = hsv;
				else{
					if (s1 != hsv) f = 0;
				}
			}
			else{
				hs hsv = getSub(si, si + l1);
				si += l1;
				if (!f2) f2 = 1, s2 = hsv;
				else{
					if (s2 != hsv) f = 0;
				}
			}
		}
		if (l0 == l1 && !(s1 != s2)) f = 0;
		ret += f;
	}
	pri(ret);
}