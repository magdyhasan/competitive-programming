#include<bits/stdc++.h>
using namespace std;

const int maxn = 105;

int n, m;

int X[maxn], Y[maxn], sm[maxn], pm[maxn], sv[maxn], pv[maxn];

bool can(int ns){
	int ret = 0;
	for (int i = 0; i < n; i++){
		int ne = X[i] * ns - Y[i];
		if (ne <= 0) continue;
		int co = 123456789, up = (ne + sm[i] - 1) / sm[i];
		for (int j = 0; j <= up; j++){
			int big = ne - j*sm[i];
			big = (big + sv[i] - 1) / sv[i];
			co = min(co, j*pm[i] + big*pv[i]);
		}
		ret += co;
		if (ret > m) break;
	}
	return ret <= m;
}



int main(){
    freopen("uva.txt","rt",stdin);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++){
		scanf("%d%d%d%d%d%d", X + i, Y + i, sm + i, pm + i, sv + i, pv + i);
	}
	int l = 0, r = m, ret = -1;
	while (l <= r){
		int mid = (l + r) / 2;
		if (can(mid)) l = mid + 1, ret = mid;
		else r = mid - 1;
	}
	printf("%d\n", ret);
}

