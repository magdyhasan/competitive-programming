#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    freopen("uva.txt","rt",stdin);
	int n;
	while (scanf("%d", &n) && n){
		int ln = 1, l = 1, r = 1, cnt = 1;
		bool lr = 0;
		while (true){
			if (n <= r) break;
			ln += 2;
			l = r + 1, r = r + ln;
			lr = !lr;
			cnt++;
		}
		if (lr){
			if (n * 2<(l + r)) printf("%d %d\n", n - l + 1, cnt);
			else printf("%d %d\n", cnt, r - n + 1);
		}
		else{
			if (n * 2<(l + r)) printf("%d %d\n", cnt, n - l + 1);
			else printf("%d %d\n", r - n + 1, cnt);
		}
	}
}
