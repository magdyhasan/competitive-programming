/*
	we only have people of two types, who perfer pizza a ( call them A )
	and who perfer b ( B )

	so we have pattern like this, AAAAABBB
	we will give (#A's/S) type of pizza a
	so we may have some reminder < S that prefer pizza a, but we may give them instead pizza b

	also we can look at B's in same way

	so now we have just one pizze that we have to decide whtether to make it of type a or b
	we can just try both cases 
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

const int maxn = 300500;

typedef long long ll;


int s[maxn], a[maxn], b[maxn];

int main(){
	int n, S; scii(n, S);
	ll tot = 0;
	lp(i, n){
		sci(s[i]), scii(a[i], b[i]);
		tot += s[i];
	}
	ll pizs = (tot + S - 1) / S;
	s[n] = pizs*S - tot;
	++n;
	vector<pair<ll, ll>> as, bs;
	ll ret = 0, ac = 0, bc = 0;
	lp(i, n){
		if (a[i] > b[i]){
			as.push_back({ a[i] - b[i], s[i] });
			ret += 1LL * a[i] * s[i];
			ac += s[i];
		}
		else{
			bs.push_back({ b[i] - a[i], s[i] });
			ret += 1LL * b[i] * s[i];
			bc += s[i];
		}
	}
	ll mi = 1e18;
	sort(all(as));
	{
		ll rem = ac % S, rv = 0;
		lp(i, (int)as.size()){
			int ta = min(rem, as[i].second);
			rv += 1LL * as[i].first * ta;
			rem -= ta;
		}
		mi = min(mi, rv);
	}
	sort(all(bs));
	{
		ll rem = bc % S, rv = 0;
		lp(i, (int)bs.size()){
			int ta = min(rem, bs[i].second);
			rv += 1LL * bs[i].first * ta;
			rem -= ta;
		}
		mi = min(mi, rv);
	}
	printf("%lld", ret - mi);
}
