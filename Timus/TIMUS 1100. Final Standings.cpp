#include<bits/stdc++.h>
using namespace std;

struct st{
	int fi, se, id;
	bool operator < (const st &a){
		if (a.se != se) return se > a.se;
		return id < a.id;
	}
} a[150550];

int main(){
    freopen("uva.txt","rt",stdin);
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d%d", &a[i].fi, &a[i].se), a[i].id = i;
	sort(a, a + n);
	for (int i = 0; i < n; i++) printf("%d %d\n", a[i].fi, a[i].se);
}


