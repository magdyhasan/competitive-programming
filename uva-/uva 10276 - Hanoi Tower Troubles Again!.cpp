#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;

int N,mx_number;
int pegs[55];
int square_numbers[] = { 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225, 256, 289, 324, 361, 400, 441, 484, 529, 576, 625, 676, 
729, 784, 841, 900, 961, 1024, 1089, 1156, 1225, 1296, 1369, 1444, 1521, 1600, 1681, 1764, 1849, 1936, 2025, 2116, 2209, 2304, 2401, 2500, 2601, 
2704, 2809, 2916, 3025, 3136, 3249, 3364, 3481, 3600, 3721, 3844, 3969, 4096, 4225, 4356, 4489, 4624, 4761, 4900, 5041, 5184, 5329, 5476, 5625, 
5776, 5929, 6084, 6241, 6400, 6561, 6724, 6889, 7056, 7225, 7396, 7569, 7744, 7921, 8100, 8281, 8464, 8649, 8836, 9025, 9216, 9409, 9604, 9801,
10000 };

void rec(int number){
	mx_number = max(mx_number, number); // we reached this number maximize on it
	for (int i = 0; i < N; i++ ) // try to place on any pegs 
		if (pegs[i] == -1 || binary_search(square_numbers, square_numbers + 51, number + pegs[i])) {
			pegs[i] = number;
			rec(number + 1);
			break;
		}
	return;
}

int main(){
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &N);
		mx_number = 1;
		for (int i = 0; i <= N; i++)
			pegs[i] = -1; // initalize all pegs to have no numbers
		rec(1);
		printf("%d\n", mx_number-1);
	}
}
