#include<stdlib.h>
#include<stdio.h>
#include<cstring>
using namespace std;

bool vc[10], vr[10], d1[16], d2[16];
int pos[100][10], tpos[10], pos_cnt;

void gen(int c){ // c is the column because we want it to be sorted accoriding to smallest row
	if (c == 9) { // we have a possible way for placing 8 queens
		for (int i = 1; i < 9; i++) 
			pos[pos_cnt][i] = tpos[i];
		pos_cnt++;
		return;
	}
	for (int r = 1; r < 9;r++) // we start from minimum for rows
		if (vc[c] == 0 && vr[r] == 0 && d1[r + c] == 0 && d2[8 + r - c] == 0) {
			tpos[c] = r;
			vc[c] = vr[r] = d1[r + c] = d2[8 + r - c] = 1; // mark this cell,row,diagnlos as used
			gen(c + 1); // try placing in next column
			vc[c] = vr[r] = d1[r + c] = d2[8 + r - c] = 0;
		}
	return;
}

int main(){
    freopen("uva.txt","rt",stdin);
	gen(1);
	int tc, r, c, seq;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &r, &c);
		puts("SOLN       COLUMN");
		puts(" #      1 2 3 4 5 6 7 8\n");
		seq = 0;
		for (int i = 0; i < pos_cnt; i++)
			if (pos[i][c] == r) { // if there's a queen in the place specified by the input
				printf("%2d      ", ++seq);
				for (int j = 1; j < 9; j++)
					printf("%d%s", pos[i][j], (j == 8) ? "\n" : " ");
			}	
		if (tc)
			puts("");
	}
}
