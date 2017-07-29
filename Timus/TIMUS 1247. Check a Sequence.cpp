#include<bits/stdc++.h>
using namespace std;

int a[300500], ss[300500];

int main(){
    freopen("uva.txt","rt",stdin);
	int n, s;
	scanf("%d%d", &n, &s);
	for (int i = 0; i < n; i++){
		scanf("%d", a + i);
		a[i]--;
	}
	int mx = 0, cur = 0;
	for (int i = 0; i < n; i++){
		cur += a[i];
		if (cur < 0) cur = 0;
		mx = max(mx, cur);
	}
	puts(mx > s ? "NO" : "YES");
}

