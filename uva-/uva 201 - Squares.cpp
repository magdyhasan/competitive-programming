#include<stdlib.h>
#include<stdio.h>
#include<cstring>
using namespace std;

int n, m, row, column;

int si[10];
bool dots[200][200];
char dir;

int main(){
    freopen("uva.txt","rt",stdin);
	int tc = 0;
	while (scanf("%d%d", &n, &m) != EOF) {
		if (tc)
			puts("\n**********************************\n");
		printf("Problem #%d\n\n", ++tc);
		memset(dots, 0, sizeof(dots));
		memset(si, 0, sizeof(si));
		for (int i = 0; i < m; i++) {
			scanf("%s%d%d", &dir, &row, &column);
			row--;
			column--;
			if (dir == 'H')
				dots[row*n + column][row*n + column + 1] = 1;
			else
				dots[column*n + row][(column + 1)*n + row] = 1;
		}
		for (int k = 0; k < n*n; k++) // make the undrieted edges between the dots with floyd-warshall
			for (int i = 0; i < n*n; i++)
				for (int j = 0; j < n*n; j++)
					dots[i][j] |= (dots[i][k] && dots[k][j]);

		for (int k = 1; k <= n; k++) // go over all squares with all sizes
			for (int i = 0; i < n - k; i++)
				for (int j = 0; j < n - k; j++)
					if (dots[i*n + j][i*n + j + k] && dots[i*n + j][(i + k)*n + j] // if ther's 4 edges for this k square
						&& dots[(i + k)*n + j][(i + k)*n + j + k] && dots[i*n + j + k][(i + k)*n + j + k]) 
						si[k]++; // count as we have one k square
		bool atLeastOne = 0;
		for (int i = 1; i <= n; i++)
			if (si[i]) 
				printf("%d square (s) of size %d\n", si[i], i), atLeastOne = 1;
		if (atLeastOne == false)
			puts("No completed squares can be found.");
	}
}
