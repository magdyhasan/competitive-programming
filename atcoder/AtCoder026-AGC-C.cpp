/*	
	constaints given that half of string is 18, give us big clue that we probably need to use mask of 2^18 or something
	but full string 2*18=36 is too big for mask

	so we need to think something like in meet-in-middle
	after tracing some samples we will get that,
	red string of first half should equal reversed part of blue string of second part
	blue string of first half should equal reversed part of red string of second part

	now we can precompute all 2-substrings of second half, which is 2^18 and save them in map
	and now generate all masks of first part and try to match them with second part that's stored in the map
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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

char st[200400];
map<string, int> ma;
int n;

void pre(){
	string se(st + n, st + n + n);
	int m = se.size();
	for (int i = 0; i < (1 << m); i++){
		string r, b;
		for (int j = 0; j < m; j++) if (i&(1 << j)){
			b += se[j];
		}
		for (int j = m - 1; j >= 0; j--) if (!(i&(1 << j))){
			r += se[j];
		}
		ma[(b + "-" + r)]++;
	}
}


int main(){
	sci(n);
	scanf("%s", st);
	pre();
	ll ret = 0;
	for (int i = 0; i < (1 << n); i++){
		string r, b;
		for (int j = 0; j < n; j++) if (i&(1 << j)){
			b += st[j];
		}
		for (int j = n - 1; j >= 0; j--) if (!(i&(1 << j))){
			r += st[j];
		}
		ret += ma[(r + "-" + b)];
	}
	printf("%lld\n", ret);
}