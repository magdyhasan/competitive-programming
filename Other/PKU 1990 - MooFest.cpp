#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

const int maxn = 20500;

ll cntT[maxn], diT[maxn];

ll sum(ll T[], int idx){
	ll ret = 0;
	for (; idx; idx -= idx&-idx) ret += T[idx];
	return ret;
}

ll sumR(ll T[], int a, int b){
	return sum(T, b) - sum(T, a - 1);
}

void update(ll T[], int idx, ll val){
	for (; idx<maxn; idx += (idx & -idx)) T[idx] += val;
}

struct cow{
	int v, x;
	bool operator < (cow a) const {
		return v < a.v;
	}
} cows[maxn];

int main(){
    freopen("uva.txt","rt",stdin);
	int n;	
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &cows[i].v, &cows[i].x);
	sort(cows, cows + n);
	ll ret = 0;
	for (int i = 0; i < n; i++){
		ll v = cows[i].v, x = cows[i].x;
		ll nl = sumR(cntT, 1, x), nr = sumR(cntT, x, maxn-100);
		ll spl = sumR(diT, 1, x), spr = sumR(diT, x, maxn-100);
		ret += v * ((x*nl - spl) + (spr - x*nr));
		update(cntT, x, 1);
		update(diT, x, x);
	}
	printf("%lld", ret);
}
