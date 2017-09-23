#include<bits/stdc++.h>
using namespace std;

typedef long long ll;



int main(){
    freopen("uva.txt","rt",stdin);
	ll a, b, n;
	while (scanf("%lld%lld%lld", &a, &b, &n)){
		if (!a && !b && !n) break;
		n %= 5;
		if (n == 0) printf("%lld\n", a);
		else if (n == 1) printf("%lld\n", b);
		else if (n == 2) printf("%lld\n", (1 + b) / a);
		else if (n == 3) printf("%lld\n", (a + b + 1) / a / b);
		else printf("%lld\n", (1 + a) / b);
	}
}
