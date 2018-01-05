#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 300500;
int x[maxn];


int s[1000500];

int main(){
    freopen("uva.txt","rt",stdin);
	int g, w; scanf("%d%d", &g, &w);
	int b, p; scanf("%d%d", &b, &p);
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", x + i);
		s[x[i]]++;
	}
	int cur = 0, cur2 = 0;
	for (int i = 1; i <= g; i++){
		s[i] += s[i - 1];
	}
	int mi = 123456789, si = 0;
	for (int i = 0; i + b <= g; i++){
		int cur = s[i+b-1] - (i - w >= 0 ? s[i - w] : 0);
		if (b - 2 * p >= w) cur -= s[i + b - p - w] - s[i + p - 1];
		if (mi > cur)
			mi = cur, si = i;
	}
	printf("%d\n", si);
}
