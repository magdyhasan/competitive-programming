/*
	Let's fix the gcd we will use for all numbers, call it g

	now all numbers has to be some multiples of g

	let's iterate over all those multiples

	suppose we are now at tg+g:
	since we only have increase opertions, it's optimal to choose numbers in range [tg,tg+g]

	it's better to use increase operations on some range from tg+g to some f
	we can this f is easly x/y-1, because this first numbers that increasing it with some k*y cost
	will be higher than just deleting it with x cost
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


const int maxn = 2000500;


ll a[maxn], cn[maxn], s[maxn];

int main(){
	int n;
	ll x, y;
	sci(n);
	scanf("%lld%lld", &x, &y);
	int c = x / y;
	ll v;
	lp(i, n){
		scanf("%lld", &v);
		cn[v]++;
		s[v] += v;
	}
	lpi(i, 1, maxn){
		cn[i] += cn[i - 1];
		s[i] += s[i - 1];
	}
	ll ret = 1LL * n*x;
	for (int g = 2; g < maxn; g++){
		ll tret = 0;
		for (int tg = 0; tg + g < maxn; tg += g){
			if (tg + g - c - 1>tg)
				tret += (cn[tg + g - c - 1] - cn[tg])*x;
			int st = max(tg + g - c, tg + 1);
			tret += ((cn[tg + g - 1] - cn[st - 1])*(tg + g) - (s[tg + g - 1] - s[st - 1]))*y;
		}
		ret = min(ret, tret);
	}
	printf("%lld", ret);
}