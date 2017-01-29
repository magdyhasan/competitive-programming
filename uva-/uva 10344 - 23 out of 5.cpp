#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <algorithm>
using namespace std;

int x[5];


bool rec(int i, int cur_sum){
	if (i == 5) 
		return (cur_sum == 23); // return true if we found 23 else false
	return (rec(i + 1, cur_sum + x[i]) || rec(i + 1, cur_sum - x[i]) || rec(i + 1, cur_sum * x[i]) ); // ry all three operations
}

int main(){
	while (scanf("%d%d%d%d%d",x,x+1,x+2,x+3,x+4)) {
		if (x[0] == 0)
			break;
		sort(x, x + 5);
		bool found = 0;
		do {
			if (rec(1, x[0])) {
				found = 1;
				puts("Possible");
				break;
			}
		} while (next_permutation(x,x+5)); // try all permutation of number
		if (found == false)
			puts("Impossible");
	}
}
