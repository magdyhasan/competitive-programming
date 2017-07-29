#include<bits/stdc++.h>
using namespace std;

char st[1000];

const int maxn = 300500;

int segT[maxn * 4];

int k, n;

int update(int v, int idx = 1, int l = 0, int r = 100500){
	if (l == r){
		segT[idx] -= v;
		return l;
	}
	int mid = (l + r) / 2, lidx = idx << 1, ridx = lidx | 1, ret;
	if (segT[lidx] >= v) ret = update(v, lidx, l, mid);
	else ret = update(v, ridx, mid + 1, r);
	segT[idx] = max(segT[lidx], segT[ridx]);
	return ret;
}

void build(int idx = 1, int l = 0, int r = 100500){
	if (l == r) {
		segT[idx] = k;
		return;
	}
	int mid = (l + r) / 2, lidx = idx << 1, ridx = lidx | 1;
	build(lidx, l, mid);
	build(ridx, mid + 1, r);
	segT[idx] = max(segT[lidx], segT[ridx]);
}


int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	while (T--){
		scanf("%d%d", &k, &n);
		build();
		int r, v, mx = -1, su = 0;
		while (n){
			scanf("%s", st);
			if (st[0] == 'b'){
				scanf("%d%d", &r, &v);
			}
			else{
				sscanf(st, "%d", &v);
				r = 1;
			}
			while (r--){
				n--;
				su += v;
				mx = max(mx, update(v));
			}
		}
		printf("%d %d\n", mx + 1, (mx + 1)*k - su);
	}
}
