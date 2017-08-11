#include<bits/stdc++.h>
using namespace std;

char st[2000500], pat[1000500];

int longestP[2000500];

int main(){
	freopen("uva.txt", "r", stdin);
	int n; scanf("%d%s%s", &n, pat, st);
	for (int i = 1, k = 0; pat[i]; i++){
		while (k > 0 && pat[i] != pat[k]) k = longestP[k - 1];
		if (pat[i] == pat[k]) longestP[i] = ++k;
		else longestP[i] = k;
	}
	for (int i = 0; i<n; i++) st[i + n] = st[i];
	n *= 2;
	st[n] = '\0';
	int longest = -1, mini = 123456789;
	for (int i = 0, k = 0; i < n; i++){
		while (k>0 && pat[k] != st[i]) k = longestP[k - 1];
		if (pat[k] == st[i]) k++;
		if (k>longest || (k == longest&& i - k + 1 < mini)) longest = k, mini = i - k + 1;
		if (k * 2 == n) k = longestP[k - 1];
	}
	printf("%d\n", mini);
}