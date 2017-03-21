/*
	NOtice F is just F[n] = F[n-1]+F[n-2]
	-Generate sequence till F[0], F[1] appear again
	-for each number find irst greater element after it with segement tree
	-run dp to get max len of each H

*/

#include<stdlib.h>
#include<stdio.h>
#include<cstring>
using namespace std;

const int maxn = 1000050;

int n, twoN;



int segT[maxn];
int ft[maxn];

int build(int idx = 1, int l = 0, int r = twoN - 1){
	if (l == r)	 return segT[idx] = l;
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	int a = build(lidx, l, mid);
	int b = build(ridx, mid + 1, r);
	return segT[idx] = ft[a] > ft[b] ? a : b;
}

int query(int x, int y, int v, int idx = 1, int l = 0, int r = twoN -1){
	if (x <= l && y >= r && ft[segT[idx]] <= v) return -1;
	if (l == r) return l;
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	if (y <= mid) return query(x, y, v, lidx, l, mid);
	if (x > mid) return query(x, y, v, ridx, mid + 1, r);
	int a = query(x, y, v, lidx, l, mid);
	if (a != -1) return a;
	return query(x, y, v, ridx, mid + 1, r);
}

int nxtSucc[maxn], mxLn[maxn];

int dpLn(int idx){
	if (nxtSucc[idx] == -1) return 1;
	if (mxLn[idx] != -1) return mxLn[idx];
	return mxLn[idx] = 1 + dpLn(nxtSucc[idx]);
}

int main(){
	int T;	 scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++){
		int M;	 scanf("%d", &M);
		ft[0] = 0, ft[1] = 1 % M, ft[2] = ft[1];
		n = 3;
		while (true){
			if (ft[n - 1] == ft[1] && ft[n - 2] == ft[0])	 break;
			ft[n] = (ft[n - 1] + ft[n - 2]) % M;
			n++;
		}
		n -= 2;
		twoN = 2 * n;
		for (int i = 0; i < n; i++) ft[i + n] = ft[i];
		build();
		memset(nxtSucc, -1, (n+1) * sizeof(int));
		for (int i = 0; i < n; i++) nxtSucc[i] = query(i + 1, twoN - 1, ft[i]);
		for (int i = 0; i < n; i++) if (nxtSucc[i] > n) nxtSucc[i] -= n;
		memset(mxLn, -1, (n + 1) * sizeof(int));
		int s = 0;
		for (int i = 0; i < n; i++)
			s += dpLn(i);
		printf("Case %d: %d\n", tc, s);
	}
}
