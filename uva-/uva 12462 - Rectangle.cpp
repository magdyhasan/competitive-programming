#include<bits/stdc++.h>
using namespace std;

const int maxn = 300500;


typedef long long ll;

int h[maxn], c[maxn];
int cs[maxn][100];
int l[maxn], r[maxn];

int main(){
    freopen("uva.txt","rt",stdin);
	int n, C; 
	while (scanf("%d%d", &n, &C)){
		if (!n && !C) break;
		for (int i = 1; i <= n; i++) scanf("%d", h + i);
		for (int i = 1; i <= n; i++) scanf("%d", c + i);
		h[n + 1] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < C; j++) cs[i][j] = cs[i - 1][j];
			cs[i][c[i]]++;
		}
		stack<int> st;
		st.push(0);
		for (int i = 1; i <= n; i++){
			while (h[i] <= h[st.top()]) st.pop();
			l[i] = st.top() + 1;
			st.push(i);
		}
		while (!st.empty()) st.pop();
		st.push(n + 1);
		for (int i = n; i > 0; i--) {
			while (h[i] <= h[st.top()]) st.pop();
			r[i] = st.top() - 1;
			st.push(i);
		}
		ll ret = 0;
		for (int i = 1; i <= n; i++){
			bool f = 1;
			for (int j = 0; j < C; j++) f &= (cs[r[i]][j] - cs[l[i] - 1][j] > 0);
			if (f) ret = max(ret, 1LL * h[i] * (r[i] - l[i] + 1LL));
		}
		printf("%lld\n", ret);
	}
}

