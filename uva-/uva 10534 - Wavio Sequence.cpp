#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

const int maxn = 100500;

int d1[maxn], d2[maxn];
int s1[maxn], s2[maxn];
int a[maxn], b[maxn];

int main(){
    freopen("uva.txt","rt",stdin);
	int n;
	while (scanf("%d", &n) == 1){
		for (int i = 0; i < n + 100; i++)
			d1[i] = 123456789, d2[i] = 123456789;
		for (int i = 1; i <= n; i++)
			scanf("%d", a + i), b[n-i+1]= a[i];
		d1[0] = d2[0] = -12345678;
		for (int i = 1; i <= n; i++){
			int j = upper_bound(d1, d1 + n, a[i]) - d1;
			s1[i] = s1[i - 1];
			if (d1[j - 1] < a[i] && d1[j] > a[i])
				d1[j] = a[i], s1[i] = max(s1[i],j);
			s2[i] = s2[i - 1];
			j = upper_bound(d2, d2 + n, b[i]) - d2;
			if (d2[j - 1] < b[i] && d2[j] > b[i])
				d2[j] = b[i], s2[i] = max(s2[i], j);
		}
		int ret = 1;
		for (int i = 2; i < n; i++)
			ret = max(ret, min(s1[i]-1, s2[n - i+1]-1) * 2 + 1);
		printf("%d\n", ret);
	}
}
