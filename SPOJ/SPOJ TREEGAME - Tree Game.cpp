#include<stdlib.h>
#include<stdio.h>
#include<cstring>
using namespace std;

int tree[4 * (1 << 16)];
int h;



int main(){
    freopen("uva.txt","rt",stdin);
	scanf("%d", &h);
	memset(tree, -1, sizeof(tree));
	for (int i = 0; i < (1 << h); i++){
		int idx;
		scanf("%d", &idx);
		if (i + 1 == (1 << h)) continue;
		idx += (1<<h)-1;
		while (tree[idx] != -1 || tree[idx ^ 1] != -1) idx /= 2;
		tree[idx] = 1;
		while (idx < (1 << h)){
			idx *= 2;
			if (tree[idx] != -1) idx++;
			if (tree[idx / 2] == 1) tree[idx] = 0;
			else tree[idx] = 1;
		}
		printf("%d ", tree[idx]);
	}
}
