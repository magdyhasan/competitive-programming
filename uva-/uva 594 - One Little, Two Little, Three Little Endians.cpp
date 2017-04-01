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
	while (scanf("%d", &n) != EOF){
		int ret = 0, tn = n;
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 8; j++) ret |= ((n >> j) & 1) << j;
			n >>= 8;
			if(i < 3) ret <<= 8;
		}
		printf("%d converts to %d\n", tn, ret);
	}
}
