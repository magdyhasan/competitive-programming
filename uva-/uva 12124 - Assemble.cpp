#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

typedef long long ll;

map<string, vector<pair<ll, ll>>> ma;

ll b;

bool can(ll qu){
	ll mi = 0;
	for (auto ty : ma){
		ll least = 10000000000LL;
		for (auto p : ty.second) if (p.first >= qu)
			least = min(least, p.second);
		mi += least;
	}
	return mi <= b;
}

char st1[100500], st2[100500];

int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	while (T--){
		ma = map<string, vector<pair<ll, ll>>>();
		int n; scanf("%d%lld", &n, &b);
		for (int i = 0; i < n; i++){
			int pri, qual;
			scanf("%s%s%d%d", st1, st2, &pri, &qual);
			ma[st1].push_back({ qual, pri });
		}
		ll l = 0, r = 10000000000LL;
		while (l + 1 < r){
			ll mi = l + (r - l) / 2LL;
			if (can(mi)) l = mi;
			else r = mi - 1;
		}
		if (can(l + 1)) l++;
		printf("%lld\n", l);
	}
}

