#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

int dx[] = { -1, 2, 3, 1, -2, -3 };

int main(){
    freopen("uva.txt","rt",stdin);
	int ibt, bt, fbt;
	while (scanf("%d%d%d", &ibt, &bt, &fbt)){
		if (!ibt && !bt && !fbt) break;
		int ret = 0;
		if (fbt >= ibt){
			while (ibt + bt * 3 <= fbt) ret++, ibt += bt * 3;
			while (ibt + bt * 2 <= fbt) ret++, ibt += bt * 2;
			while (ibt + bt * 1 <= fbt) ret++, ibt += bt * 1;
		}
		else{
			while (ibt - bt * 3 >= fbt) ret++, ibt -= bt * 3;
			while (ibt - bt * 2 >= fbt) ret++, ibt -= bt * 2;
			while (ibt - bt * 1 >= fbt) ret++, ibt -= bt * 1;
		}
		if (ibt == fbt) printf("%d\n", ret);
		else puts("No accounting tablet");
		
	}
}

