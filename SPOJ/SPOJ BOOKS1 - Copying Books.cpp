#include<stdlib.h>
#include<stdio.h>
#include<string>
using namespace std;

typedef long long ll;

ll p[600];
ll n, k;

bool can(ll mx){ // if it can be done with each scribers take <= pages
	ll pages = 0, i = 0, scribers = 1;
	for (int i = 0; i < n; i++) {
		if (p[i] > mx) // some book are even bigger than mx
			return 0;
		if (pages + p[i] > mx) { // we need a new scribers
			scribers++;
			pages = 0;
		}
		pages += p[i];
	}
	return scribers <= k;
}

void print(int idx, int tk,int mx){
	ll total = 0;
	int i;
	for (i = idx; i >= 0; i--) {
		if (total + p[i] > mx || i == tk - 2) { // we maximize from last one as problem statement asks to 
			print(i, tk - 1, mx);
			break;
		}
		total += p[i];
	}
	if (i >= 0)
		printf("/ ");
	for (int j = i + 1; j <= idx; j++)
		printf("%lld%s", p[j], (j == n - 1) ? "\n":" ");
}



int main(){
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%lld%lld", &n, &k);
		for (int i = 0; i < n; i++) 
			scanf("%lld", p + i);
		ll r = 2147483647, l = 1;
		while (l < r) { // binary search to minimize 
			ll mid = (l + r) / 2;
			if (can(mid)) 
				r = mid;
			else
				l = mid + 1;
		}
		print(n - 1, k, r);
	}
}
