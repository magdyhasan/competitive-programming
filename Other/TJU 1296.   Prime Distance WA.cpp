#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

const int maxn = 9500000;

typedef long long ll;

bool notPrime[maxn];
int pr[maxn];
int prCnt;

int main(){
	freopen("uva.txt", "r", stdin);
	for (ll i = 2; i < maxn; i++) if (!notPrime[i]){
		pr[prCnt++] = i;
		for (ll j = i*i; j < maxn; j += i) notPrime[j] = 1;
	}
	int l, r;
	while (scanf("%d%d", &l, &r) == 2){
		int it = lower_bound(pr, pr + prCnt, l) - pr;
		if (it == prCnt || pr[it + 1] > r) puts("There are no adjacent primes.");
		else{
			int mi = 123456789, mx = -1, mia, mib, mxa, mxb;
			for (int i = it+1; pr[i] <= r; i++){
				if (pr[i] - pr[i - 1] < mi)  mia = pr[i - 1], mib = pr[i], mi = mib - mia;
				if (pr[i] - pr[i - 1] > mx)  mxa = pr[i - 1], mxb = pr[i], mx = mxb - mxa;
			}
			printf("%d,%d are closest, %d,%d are most distant.\n", mia, mib, mxa, mxb);
		}
	}
}