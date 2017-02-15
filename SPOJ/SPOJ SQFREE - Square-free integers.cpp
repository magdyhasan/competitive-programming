#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


const int maxn = 10004000;


//en.mostafa function
int moebius[maxn];
bool pr[maxn];

void gen_moebius(){
	for (int i = 2; i < maxn; i++)
		moebius[i] = -1, pr[i] = true;
	for (int i = 2; i <= maxn; i++) if (pr[i]){
		moebius[i] = 1;
		for (ll j = i * 2; j < maxn; j += i)
			pr[j] = 0, moebius[j] = j % (i*i) == 0 ? 0 : -moebius[j];
	}
	return;
}

int main(){
	freopen("test.txt", "r", stdin);
	gen_moebius();
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		ll n, ret;
		scanf("%lld", &n);
		ret = n;
		for (ll i = 1; i*i <= n; i++)
			ret -= moebius[i] * (n / (i*i));
		printf("%lld\n", ret);
	}
}