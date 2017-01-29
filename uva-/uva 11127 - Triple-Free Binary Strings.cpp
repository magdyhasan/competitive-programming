#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int n;	 char st[50];
int ln, ans;

int tv[3];

void rec(int idx, int msk){
	if (idx == ln){
		ans++;
		return;
	}
	for (int t = 0; t < 2; t++) if (st[idx] == '*' || st[idx] - '0' == t){
		bool f = true;	
		for (int si = 1; si * 3 <= (idx + 1); si++){
			int nmsk = (msk << 1) | t;
			for (int j = 0; j < 3; j++){
				tv[j] = nmsk & ((1 << si) - 1);
				nmsk >>= si;
			}
			if (tv[0] == tv[1] && tv[1] == tv[2]){
				f = false;	break;
			}
		}
		if (f)
			rec(idx + 1, (msk << 1) | t);
	}
}

int main(){
    freopen("uva.txt","rt",stdin);
	int te = 0;
	while (scanf("%d", &n)){
		if (n == 0) break;
		scanf("%s", st);
		ln = strlen(st);
		ans = 0;
		rec(0, 0);
		printf("Case %d: %d\n", ++te, ans);
	}
}	
