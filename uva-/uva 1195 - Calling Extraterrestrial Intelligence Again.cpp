#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 300500;

typedef long long ll;

bool notPr[maxn];
ll pr[maxn];

int main(){
    freopen("uva.txt","rt",stdin);
	int prCnt = 0;
	for (ll i = 2; i < maxn; i++) if (!notPr[i]) {
		pr[prCnt++] = i;
		for (ll j = i*i; j < maxn; j += i) 
			notPr[j] = 1;
	}
	int m, a, b;
	while (scanf("%d%d%d", &m, &a, &b)){
		if (!m && !a && !b) break;
		int p = 0, q = 0;
		for (int i = 0; pr[i] * pr[i] <= m; i++) {
			int  l = i, r = prCnt - 1;
			while (l <= r){
				int mid = (l + r) / 2;
				if (pr[i] * pr[mid] <= m && pr[i] * ll(b) >= pr[mid] * ll(a)){
					if (pr[i] * pr[mid] > ll(p)*ll(q)) p = pr[i], q = pr[mid];
					l = mid + 1;
				}
				else
					r = mid - 1;
			}
		}
		printf("%d %d\n", p, q);
	}
}
