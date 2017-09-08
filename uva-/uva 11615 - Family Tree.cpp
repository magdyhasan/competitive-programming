#include<bits/stdc++.h>
using namespace std;

int n;
int cntCh(int idx){
	int ret = 0;
	if (idx * 2 < (1 << (n))) ret += cntCh(idx * 2) + 1;
	if (idx * 2 + 1 < (1 << (n))) ret += cntCh(idx * 2 + 1) + 1;
	return ret;
}

int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	while (T--){
		int a, b;
		scanf("%d%d%d", &n, &a, &b);
		printf("%d\n", (1 << n) - 1 - min(cntCh(a), cntCh(b)));
	}
}

