#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 1000500;

int a[maxn], b[maxn], c[maxn];
int aa[maxn], bb[maxn], cc[maxn];

int sq(int x) { return x*x; }

int main(){
    freopen("uva.txt","rt",stdin);
	for (int i = 0; i < 16; i++) scanf("%d%d%d", aa + i, bb + i, cc + i);
	int n = 0;
	while (scanf("%d%d%d", a + n, b + n, c + n)){
		if (a[n] == -1 && b[n] == -1 && c[n] == -1) break;
		n++;
	}
	for (int i = 0; i < n; i++){
		int di = 2147483647, ans = -1;
		for (int j = 0; j < 16; j++) {
			int t = sq(a[i] - aa[j]) + sq(b[i] - bb[j]) + sq(c[i] - cc[j]);
			if (t < di) di = t, ans = j;
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n", a[i], b[i], c[i], aa[ans], bb[ans], cc[ans]);
	}
}
