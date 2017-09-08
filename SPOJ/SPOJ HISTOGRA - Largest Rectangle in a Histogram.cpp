#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

const int maxn = 800500;

int h[maxn];

int l[maxn], r[maxn];



int main(){
    freopen("uva.txt","rt",stdin);
	int n; 
	while (scanf("%d", &n)){
		if (!n)break;
		for (int i = 1; i <= n; i++) scanf("%d", h + i);
		h[0] = -1;
		stack<int> st; st.push(0);
		for (int i = 1; i <= n; i++){
			while (h[i] <= h[st.top()]) st.pop();
			l[i] = st.top() + 1;
			st.push(i);
		}
		while (!st.empty()) st.pop();
		h[n + 1] = -1;
		st.push(n + 1);
		for (int i = n; i > 0; i--){
			while (h[i] <= h[st.top()]) st.pop();
			r[i] = st.top() - 1;
			st.push(i);
		}
		ll ret = 0;
		for (int i = 1; i <= n; i++) ret = max(ret, 1LL * h[i] * (r[i] - l[i] + 1));
		printf("%lld\n", ret);
	}
}


