#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	while (T--){
		int n; scanf("%d", &n);
		int one = 0, other = 0;
		while (n--){
			int cur; scanf("%d", &cur);
			if (cur == 1) one++;
			else other++;
		}
		puts((one % 2 || other > 0) ? "poopi" : "piloop");
	}
}
