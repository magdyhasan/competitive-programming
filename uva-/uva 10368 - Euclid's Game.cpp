#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

bool rec(ll a, ll b){
	if (!a) return 0;
	if (!rec(b%a, a) || (b / a != 1 && !rec(b, b + b%a)))	return 1;
	return 0;
}

int main(){
    freopen("uva.txt","rt",stdin);
	ll a, b;
	while (scanf("%lld%lld", &a, &b)){
		if (!a && !b)break;
		if (a > b) swap(a, b);
		puts(rec(a, b) ? "Stan wins" : "Ollie wins");
	}
}
