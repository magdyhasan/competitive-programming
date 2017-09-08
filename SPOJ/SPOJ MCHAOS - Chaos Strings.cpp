#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 300500;

int bit[maxn * 4];
pair<ll, ll> v[maxn];
ll tv[maxn];

char st[1000];

ll con(string s){
	ll ret = 0;
	for (int i = 0; i < s.size(); i++) ret = ret * 29LL + (s[i] - 'a' + 1);
	for (int i = s.size(); i <= 10; i++) ret = ret * 29LL;
	return ret;
}

void update(int idx, int val){
	for (int x = idx; x < maxn; x = (x|(x+1)))
		bit[x] += val;
}

int query(int idx){ // need to handle idx == 0
	int ret = 0;
	for (int x = idx; x >= 0; x = ((x&(x + 1)) - 1))
		ret += bit[x];
	return ret;
}

int main(){
    freopen("uva.txt","rt",stdin);
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i ++ ){
		scanf("%s", st);
		string s(st);
		v[i].first = con(s);
		reverse(s.begin(), s.end());
		v[i].second = tv[i] = con(s);
	}
	sort(v, v + n);
	sort(tv, tv + n);
	ll ret = 0;
	for (int i = n - 1; i >= 0; i--){
		int pos = lower_bound(tv, tv + n, v[i].second) - tv;
		ret += query(pos);
		update(pos, 1);
	}
	printf("%lld", ret);
}
