#include<stdlib.h>
#include<stdio.h>
#include<string>
using namespace std;

int A, B, C, M, N, ans, sum;
int seq[10500], have[10500];

int main(){
	int tc;
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		scanf("%d%d%d%d%d", &A, &B, &C, &M, &N);
		ans = sum = 0; // initialize
		for (int i = 1; i <= M + 1; i++)
			have[i] = 0;
		seq[0] = A; // build the sequance
		for (int i = 1; i < N; i++)
			seq[i] = (seq[i - 1] * B + C) % M + 1;
		have[0] = 1; // if the reminder is 0 then we have a number 
		for (int i = 0; i < N; i++) {
			sum = (sum + seq[i]) % M;
			ans += have[sum]; // if we have sum as the current sum before then we have reminder 0 here because we can substrat the current sum from the previous sum
			have[sum]++; // we now have this sum
		}
		printf("Case %d: %d\n", t, ans);
	}
}
