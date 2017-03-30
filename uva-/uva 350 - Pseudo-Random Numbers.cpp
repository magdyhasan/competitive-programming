#include<bits/stdc++.h>
using namespace std;

bool used[100500];


int main(){
	freopen("uva.txt", "r", stdin);
	int Z, I, M, L, tc = 0;
	while (scanf("%d%d%d%d", &Z, &I, &M, &L)){
		if (!Z && !I && !M && !L)	 break;
		memset(used, 0, sizeof(used));
		int cnt = 0;
		while (!used[L]){
			used[L] =  cnt;
			cnt++;
			L = (Z*L + I) % M;
		}
		printf("Case %d: %d\n", ++tc, cnt - used[L]);
	}
}