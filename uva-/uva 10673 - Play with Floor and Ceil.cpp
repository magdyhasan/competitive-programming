#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    freopen("uva.txt","rt",stdin);
	int T;
	scanf("%d", &T);
	while (T--){
		long long x, k;
		scanf("%lld%lld", &x, &k);
		printf("%lld %lld\n", k - x%k, x%k);
	}
}
