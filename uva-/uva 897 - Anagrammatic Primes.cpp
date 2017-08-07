#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool notPrime[10500000];
int pr[10500000], anapr[10500000];
int prCnt, anaprCnt;


bool isanapr(int x){
	vector<int> per;
	while (x > 0) { per.push_back(x % 10); x /= 10; }
	sort(per.begin(), per.end());
	int cur;
	do{
		cur = 0;
		for (int i : per) cur = cur * 10 + i;
		if (notPrime[cur]) return 0;
	} while (next_permutation(per.begin(), per.end()));
	return 1;
}

int main(){
	freopen("uva.txt", "rt", stdin);
	for (ll i = 2; i < 10000500; i++) if (!notPrime[i]){
		pr[prCnt++] = i;
		for (ll j = i*i; j < 10000500; j += i) notPrime[j] = 1;
	}
	for (int i = 0; i < prCnt; i++) if (isanapr(pr[i]))
		anapr[anaprCnt++] = pr[i];
	int n; 
	while (scanf("%d", &n)){
		if (!n) break;
		int p10 = 1;
		while (p10 <= n) p10 *= 10;
		int ans = 0;
		for (int i = 0; i < anaprCnt; i++) if (anapr[i] > n){
			if (anapr[i] < p10) ans = anapr[i];
			break;
		}
		printf("%d\n", ans);
	}
}
