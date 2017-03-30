#include<bits/stdc++.h>
using namespace std;




int main(){
	freopen("test.txt", "r", stdin);
	int n;	
	while (scanf("%d", &n) && n){
		char st[50];
		int top = 1, north = 2, west = 3, t1, t2, t3;
		for (int i = 0; i < n; i++){
			scanf("%s", st);
			t1 = top, t2 = north, t3 = west;
			if (st[0] == 'n'){
				top = 7 - t2;
				north = t1;
			}
			if (st[0] == 's'){
				top = t2;
				north = 7 - t1;
			}
			if (st[0] == 'w'){
				top = 7 - west;
				west = t1;
			}
			if (st[0] == 'e'){
				top = west;
				west = 7 - t1;
			}
		}
		printf("%d\n", top);
	}
}