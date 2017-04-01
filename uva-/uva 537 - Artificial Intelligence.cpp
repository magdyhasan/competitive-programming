#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;

char li[1000500];
int ty[2];
double va[2];


int main(){
    freopen("uva.txt","rt",stdin);
	int T;
	scanf("%d", &T); gets(li);
	for (int tc = 1; tc <= T; tc++) {
		gets(li);
		string st, pre;
		int n = 0;
		istringstream iss(li);
		while (iss >> st){
			if (st[1] == '='){
				istringstream(st.substr(2)) >> va[n] >> pre;
				if (st[0] == 'P') ty[n++] = 0;
				else if (st[0] == 'U') ty[n++] = 1;
				else ty[n++] = 2;
				if (pre[0] == 'm') va[n - 1] *= 0.001;
				else if (pre[0] == 'k') va[n - 1] *= 1000;
				else if (pre[0] == 'M') va[n - 1] *= 1000000;
			}
		}
		printf("Problem #%d\n", tc);
		if (ty[0] > ty[1]) swap(ty[0], ty[1]), swap(va[1], va[0]);
		if (ty[0] == 0 && ty[1] == 2) printf("U=%.2lfV\n", va[0] / va[1]);
		else if (ty[0] == 0 && ty[1] == 1) printf("I=%.2lfA\n", va[0] / va[1]);
		else printf("P=%.2lfW\n", va[0] * va[1]);
		puts("");
	}
}
