#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;

int stall[100005];
int N, C;

bool fit(long long dist){ 
	int cur_pos = stall[0];	
	int cows = 1;
	for (int i = 1; i < N; i++) 
		if (stall[i] - cur_pos >= dist) { // if there's a space between cur cow and last one >= dist
			cur_pos = stall[i];
			++cows;
			if (cows == C)	return true;
		}
	return false;
}

int main(){
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &N, &C);
		for (int i = 0; i < N; i++)
			scanf("%d", stall + i);
		sort(stall, stall + N);
		long long l = 0, r = (long long)1e9 + 100;
		while (l < r - 1) {
			long long mid = (l + r) / 2;
			if (fit(mid)) // if i can place them with minimum distance between them == mid
				l = mid;
			else
				r = mid - 1;
		}
		if (fit(l+1))
			l++;
		printf("%lld\n", l);
	}
}
