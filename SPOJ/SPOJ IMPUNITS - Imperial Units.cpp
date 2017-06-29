#include<stdlib.h>
#include<stdio.h>
#include<cstring>
using namespace std;

typedef long long ll;


inline ll GCD(ll a, ll b){
	if (b == 0)
		return a;
	return GCD(b, a%b);
}

int main(){
    freopen("uva.txt","rt",stdin);
	int n; 
	while (scanf("%d", &n)){
		if (n == -1) break;
		ll a = 1, b = 1;
		while (--n){
			int t1, t2;
			scanf("%d%d", &t1, &t2);
			a *= t1, b *= t2;
		}
		ll g = GCD(a, b);
		printf("%lld %lld\n", a / g, b / g);
	}
}
