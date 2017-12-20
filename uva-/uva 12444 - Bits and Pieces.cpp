/*
	hint1: analyze bits of C and D



	hint2: if c&(1<<i) and !(d&(1<<i) then no solution, because c is(a&b) and d is (a|b)
	so it's impossilbe for bit to be set in c and not in d
	

	otherwise to make a<=b and min([a-b])..
	first bit where !(c&(1<<i)) and d&(1<<i) set that in b and not in a
	other bits like this set it in a and not in b
*/
#include<bits/stdc++.h>
using namespace std;

void solve(int c, int d){
	for (int i = 30; i >= 0; i--){
		if ((c&(1 << i)) && !(d&(1 << i))) {
			puts("-1");
			return;
		}
	}
	int a = 0, b = 0;
	bool bigger = 0;
	for (int i = 30; i >= 0; i--){
		if ((c&(1 << i)) && (d&(1 << i))) a |= 1 << i, b |= 1 << i;
		else if (!(c&(1 << i)) && (d&(1 << i))){
			if (bigger) a |= 1 << i;
			else b |= 1 << i, bigger = 1;
		}
	}
	printf("%d %d\n", a, b);
}

int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	while (T--){
		int c, d; scanf("%d %d", &c, &d);
		solve(c, d);
	}
}
