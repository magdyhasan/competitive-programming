#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
	ll n;
	int T; scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++){
		scanf("%lld", &n);
		printf("Case #%d:\n", tc);
		ll i = 2;
		int cnt = 0;
		while ((i*i - 1)*(i*i - 1) <= n){
			if (n % (i*i - 1) == 0){
				ll j = ll(sqrt(double(n) / (i*i - 1)) + 1);
				if (j*j == n / (i*i - 1) + 1){
					if (cnt++ == 0)  printf("%lld", n);
					printf("=(%lld^2-1)*(%lld^2-1)", i, j);
				}
			}
			i++;
		}
		if (cnt == 0) printf("For n=%lld there is no almost square factorisation.", n);
		puts("");
	}
}