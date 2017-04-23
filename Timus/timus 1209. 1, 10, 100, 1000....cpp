#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

bool isPerfectSquare(ll n)
{
	ll tst = (ll)(sqrt(double(n)) + 0.5);
	return tst*tst == n;
}

int main(){
    freopen("uva.txt","rt",stdin);
	
	int T; scanf("%d", &T);
	while (T--){
		ll n; scanf("%lld", &n);
		n --;
		if (isPerfectSquare(8LL * n + 1)) printf("%d ", 1);
		else printf("%d ", 0);
	}
}

