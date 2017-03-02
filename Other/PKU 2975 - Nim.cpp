#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 10500;

typedef long long ll;

ll a[maxn];

int main(){
	int n;
	while (scanf("%d", &n) && n){
		ll xorSum = 0;
		for (int i = 0; i < n; i++) scanf("%lld", a + i), xorSum ^= a[i];
		int ret = 0;
		for (int i = 0; i < n; i++) ret += a[i] >(a[i] ^ xorSum);
		printf("%d\n", ret);
	}
}