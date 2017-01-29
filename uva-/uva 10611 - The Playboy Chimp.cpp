#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
using namespace std;

int line[50050];

int main(){
	int line_nu, Q, height;
	scanf("%d", &line_nu);
	for (int i = 0; i < line_nu; i++)
		scanf("%d", line + i);
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		scanf("%d", &height);
		int up = upper_bound(line, line + line_nu, height) - line; // binary search on the height greater than him
		int low = (up > 0 ) ? up - 1:0; // find height lesser than him
		while (low > 0 && line[low] >= height) low--; // while the height is not lesser than him
		if (low == 0 && line[low] >= height) // if the lesat height is >= his height
			printf("X ");
		else
			printf("%d ", line[low]);
		if (up == line_nu) // if the biggest height is <= his height
			printf("X\n");
		else
			printf("%d\n", line[up]);
	}
}
