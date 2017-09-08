#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
    freopen("uva.txt","rt",stdin);
	int S, W, C, K, M;
	while (scanf("%d%d%d%d%d", &S, &W, &C, &K, &M) == 5){
		set<ll>  ava;
		for (int i = 0; i < K; i++) ava.insert(M*(i + 1) + S);
		ll cur = 0, ti = 0;
		while (cur < 10000){
			set<ll>::iterator it = ava.begin();
			ava.insert(max(*it,ti) + W + S*2LL);
			ti = max(max(*it, ti) + W, ti);
			cur += C;
			ava.erase(it);
		}
		printf("%lld\n", ti + S);
	}
}

