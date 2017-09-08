#include<bits/stdc++.h>
using namespace std;

const int maxn = 30500;

int a[maxn];


int main(){
    freopen("uva.txt","rt",stdin);
	int n; 
	while (scanf("%d", &n)){
		if (!n) break;
		for (int i = 0; i < n; i++) scanf("%d", a + i);
		set<int> done;
		int ret = 0;
		for (int i = 0; i < n; i++) {
			if (done.find(a[i] + 1) == done.end() && a[i] != n) ret++;
			done.insert(a[i]);
		}
		printf("%d\n", ret);
	}
}

 