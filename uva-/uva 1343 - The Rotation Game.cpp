/*
	solution with BFS will TLE/MLE because number of states

	we can use some heuristic search algorithms like IDA
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int depth, solved, pa[128];

int cen[8] = { 6, 7, 8, 11, 12, 15, 16, 17 };
int shift[8][8] = {
		{ 0, 2, 6, 11, 15, 20, 22 },
		{ 1, 3, 8, 12, 17, 21, 23 },
		{ 10, 9, 8, 7, 6, 5, 4 },
		{ 19, 18, 17, 16, 15, 14, 13 },
		{ 23, 21, 17, 12, 8, 3, 1 },
		{ 22, 20, 15, 11, 6, 2, 0 },
		{ 13, 14, 15, 16, 17, 18, 19 },
		{ 4, 5, 6, 7, 8, 9, 10 }
};
int invShift[8] = { 5, 4, 7, 6, 1, 0, 3, 2 };

void shiftStrip(int a[], int dir){
	int aux = a[shift[dir][0]];
	for (int i = 0; i < 6;i++){
		a[shift[dir][i]] = a[shift[dir][i + 1]];
	}
	a[shift[dir][6]] = aux;
}

int heu(int a[]){
	int k[4] = { 0 };
	for (int i = 0; i < 8; i++){
		k[a[cen[i]]]++;
	}
	return 8 - max(k[1], max(k[2], k[3]));
}


int IDA(int a[], int curd, int hvalue){
	if (hvalue == 0){ // if values in the centers are the same
		solved = 1; // mark as already solved
		if (curd == 0) puts("No moves needed");
		else{
			for (int i = 0; i < curd; i++) putchar(pa[i] + 'A');
			puts("");
		}
		printf("%d\n", a[cen[0]]);
		return curd;
	}
	if (curd + hvalue > depth) return curd + hvalue;
	int ret = 123456789, nhvalue, aux;
	for (int i = 0; i < 8; i++){
		shiftStrip(a, i);
		nhvalue = heu(a);
		pa[curd] = i;
		aux = IDA(a, curd + 1, nhvalue);
		ret = min(ret, aux);
		shiftStrip(a, invShift[i]);
		if (solved)
			break;
	}
	return ret;
}


int main(){
    freopen("uva.txt","rt",stdin);
	int t;
	while (scanf("%d", &t) && t){
		int a[32];
		a[0] = t;
		for (int i = 1; i < 24; i++) scanf("%d", a + i);
		depth = solved = 0;
		while (!solved){
			depth = IDA(a, 0, heu(a));
		}
	}
}
