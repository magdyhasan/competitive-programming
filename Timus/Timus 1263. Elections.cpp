#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int cnt[100500];

int main(){
    freopen("uva.txt","rt",stdin);
	int n, m, t;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &t);
		cnt[t]++;
	}
	for (int i = 1; i <= n; i++) 
		printf("%.2lf%%\n", double(cnt[i]) / double(m)*100.);
}

