#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;

int cubes[205];

int main(){
	for (int i = 2; i <= 200; i++) // generate cube of all numbers <= 200
		cubes[i] = i*i*i;
	for (int a = 2; a < 201; a++)
		for (int b = 2; b < 201; b++) {
			if (cubes[b] > cubes[a])
				break;
			for (int c = b+1; c < 201; c++) { // brute-force on a,b and c
				if (cubes[b] + cubes[c] > cubes[a])
					break;
				int idx = lower_bound(cubes+c+1, cubes + 201, cubes[a] - cubes[b] - cubes[c]) - cubes; // binary search on d
				if (idx == 201 || cubes[a] != cubes[b] + cubes[c] + cubes[idx]) 
					continue;
				printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, idx);
			}
		}

}
