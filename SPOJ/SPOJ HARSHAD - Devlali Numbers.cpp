#include<bits/stdc++.h>
using namespace std;

const int maxn = 2000500;

typedef long long ll;

int df(int x){
	int ret = x;
	while (x > 0){
		ret += x % 10;
		x /= 10;
	}
	return ret;
}



bool notPrime[maxn], notDev[maxn];
int s[maxn];


int main(){
	freopen("uva.txt", "rt", stdin);
	for (int i = 1; i < 1050000; i++) notDev[df(i)] = 1;
	for (ll i = 2; i < maxn; i++) if (!notPrime[i]){
		if (!notDev[i]) s[i]++;
		for (ll j = i*i; j < maxn; j += i) notPrime[j] = 1;
	}
	for (int i = 1; i < maxn; i++) 
		s[i] = s[i - 1] + s[i];
	int q; scanf("%d", &q);
	while (q--){
		int a, b; scanf("%d%d", &a, &b);
		if (a == 0) a++;
		int t1 = s[b], t2 = s[a - 1];
		printf("%d\n", s[b] - s[a - 1]);
	}
}
