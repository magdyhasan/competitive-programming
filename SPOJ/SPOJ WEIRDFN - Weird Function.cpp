#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int f[300500];

int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	while (T--){
		int a, b, c, n;
		scanf("%d%d%d%d", &a, &b, &c, &n);
		f[1] = 1;
		ll s = 1;
		priority_queue<int, vector<int>, greater<int>> r;
		priority_queue<int, vector<int>, less<int>> l;
		l.push(1);
		for (int i = 2; i <= n; i++){
			f[i] = (ll(a)*ll(l.top()) + ll(b)*ll(i) + ll(c)) % 1000000007ll;
			s += f[i]; 
			if (f[i] > l.top())r.push(f[i]);
			else l.push(f[i]);
			while (l.size() < r.size()) l.push(r.top()), r.pop();
			while (l.size() > r.size() + 1) r.push(l.top()), l.pop();
		}
		printf("%lld\n", s);
	}
}
