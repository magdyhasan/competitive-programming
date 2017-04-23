#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

typedef long long ll;
const ll mxll = ~0ULL >> 1;


ll nCr[64][64];

ll pr[20] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 51 };
int cnt[64];
map<ll, ll> ans;

void gen(int idx, ll n, ll mx, int pes){
	ll ways = 1, pe = pes;
	for (int i = 0; i < idx; i++){ 
		if (ways>mxll / nCr[pe][cnt[i]]) {
			ways = -1;
			break;
		}
		ways *= nCr[pe][cnt[i]];
		pe -= cnt[i];
	}
	if (ways != -1)
		if (ans[ways] == 0)
			ans[ways] = n;
		else
			ans[ways] = min(ans[ways], n);
	for (int i = 1; i <= (idx ? cnt[idx-1]:64); i++){
		mx /= pr[idx];
		if (mx == 0)break;
		n *= pr[idx];
		cnt[idx] = i;
		gen(idx + 1, n, mx, pes + i);
	}
}

int main(){
    freopen("uva.txt","rt",stdin);
	for (int i = 0; i < 64; ++i) { // build n choose r
		nCr[i][0] = nCr[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];
		}
	}
	gen(0, 1, mxll, 0); // generate all answers
	ans[1] = 2;// handle special case
	ll n;
	while (scanf("%lld", &n) != EOF) {
		printf("%lld %lld\n", n, ans[n]);
	}
}
