#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

typedef long long ll;
const int maxn = 100500;

ll a[maxn], q[maxn];


int main(){
    freopen("uva.txt","rt",stdin);
	int T;	 scanf("%d", &T);
	bool en = false;
	while (T--){
		if (en) puts("");
		en = true;
		int n, m;
		scanf("%d%d", &n, &m);
		multiset<ll> nu;
		for (int i = 0; i < n; i++) scanf("%lld", a + i);
		for (int i = 0; i < m; i++) scanf("%lld", q + i);
		int qi = 0;
		multiset<ll>::iterator mi;
		int inc = 0;
		for (int i = 1; i <= n; i++){
			nu.insert(a[i - 1]);
			if (i == 1) mi = nu.begin();
			else if (a[i - 1] < *mi) --mi;
			if (inc > 0) ++mi, --inc;
			while (qi < m && q[qi] <= i){
				if (inc > 0) ++mi, inc--;
				printf("%lld\n", *mi);
				qi++;
				inc++;
			}
		}
	}
}
