#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;

int need[20050], cnt[20050], temp_seq[10050], seq[10050];
int n, len;

void dfs(int idx, int mx){
	if (idx + need[temp_seq[idx - 1]] >= len) // if we need sequence length more than the already existed sequence we already found
		return;
	if (temp_seq[idx - 1] == n) { // if we reached n
		len = idx; // we made a sequence of len == idx
		for (int i = 0; i < idx; i++) 
			seq[i] = temp_seq[i];
		return;
	}
	for (int i = min(mx, n); i > temp_seq[idx - 1]; i--) { // we can only begin from number <= n
		if (cnt[i] == 0) // if we can make this number from 2 previous number of the sequence
			continue;
		// backtrack
		temp_seq[idx] = i; // consider we take this number
		for (int j = 0; j <= idx; j++) // we now can make a new number with any of the previous number with i
			cnt[temp_seq[j] + i]++;
		dfs(idx + 1, i * 2);
		for (int j = 0; j <= idx; j++) 
			cnt[temp_seq[j] + i]--;
	}
}

int main(){
	while (scanf("%d",&n) && n != 0) {
		memset(cnt, 0, sizeof(cnt)); // initialize
		memset(need, 0, sizeof(need));
		for (int i = n - 1; i > 0; i--) // set minimum of number needed to reach n from number i
			need[i] = need[i * 2] + 1; // to get to n from i we at most will have the next number as 2*i
		len = n + 1; // we can't make sequence of length > n because we can only use n numbers
		temp_seq[0] = 1;  // set the first number as 1
		cnt[1] = cnt[2] = 1; // now we can make number 1 and number 2 from 2*1
		dfs(1, 2); 
		for (int i = 0; i < len - 1; i++)
			printf("%d ", seq[i]);
		printf("%d\n", seq[len - 1]);
	}
}
