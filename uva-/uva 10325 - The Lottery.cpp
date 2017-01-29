#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

ll n, m;
ll exclude[20];

long long gcd(long long x, long long y){
	long long t;
	while (x%y)
		t = x, x = y, y = t%y;
	return y;
}

ll inc_exc(ll idx, ll d, ll sign){
	if (idx == m) {
		return (d == 1) ? 0 : sign*n / d;
	}
	return inc_exc(idx + 1, d, sign) + inc_exc(idx + 1, d*exclude[idx]/gcd(d,exclude[idx]), sign*-1); // we have 2 option to include or exclude
}


int main(){
	while (scanf("%lld%lld",&n,&m) != EOF) {
		for (int i = 0; i < m; i++)
			scanf("%lld", exclude + i);
		printf("%lld\n", n - inc_exc(0, 1, -1));
	}
}
