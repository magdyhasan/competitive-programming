#include<bits/stdc++.h>
using namespace std;

vector<string> words;

int width;

char st[1000500];
int dp[15000], dpl[15000], prv[15000];

int sqr(int x){
	return x*x;
}

void print(int r){
	if (prv[r] > 0) print(prv[r]);
	int l = prv[r];
	if (l + 1 == r){
		puts(words[l].c_str());
		return;
	}
	int s = 0;
	for (int i = l; i < r; i++)
		s += words[i].size();
	int spaces = r - l - 1;
	int ssp = (width - s) / spaces, lsp = ssp, lspn = 0;
	if ((width - s) % spaces) lsp++, lspn = (width - s) % spaces;
	for (int i = l, j = 0; i < r; i++, j++){
		printf("%s", words[i].c_str());
		if (j < (spaces - lspn)){
			for (int k = 0; k < ssp; k++)	printf(" ");
		}
		else if (j < spaces){
			for (int k = 0; k < lsp; k++)	printf(" ");
		}
	}
	puts("");
}

int main(){
    freopen("uva.txt","rt",stdin);
	while (scanf("%d", &width)){
		if (!width) break;
		while (getchar() != '\n');
		words.clear();
		string ss;
		while (gets(st) && st[0] != '\0'){
			istringstream iss(st);
			while (iss >> ss) words.push_back(ss);
		}
		int n = words.size();
		memset(dp, 63, sizeof(dp));
		memset(dpl, 63, sizeof(dpl));
		dp[0] = dpl[0] = 0, prv[0] = -1;
		for (int i = 0; i < n; i++){
			if (dp[i] + 500 < dp[i + 1] || (dp[i] + 500 == dp[i + 1] && dpl[i] + 1 <= dpl[i + 1]))
				dp[i + 1] = dp[i] + 500, dpl[i + 1] = dpl[i] + 1, prv[i + 1] = i;
			int s = words[i].size();
			for (int j = i + 1; j < n; j++){
				s += words[j].size();
				if (s + j - i>width) break;
				int spaces = j - i;
				int ssp = (width - s) / spaces, lsp = ssp, lspn = 0;
				if ((width - s) % spaces) lsp++, lspn = (width - s) % spaces;
				int bad = sqr(ssp - 1)*(spaces - lspn) + sqr(lsp - 1)*lspn;
				if (dp[i] + bad < dp[j + 1] || (dp[i] + bad == dp[j + 1] && dpl[i] + 1 <= dpl[j + 1]))
					dp[j + 1] = dp[i] + bad, prv[j + 1] = i, dpl[j + 1] = dpl[i] + 1;
			}
		}
		print(n);
		puts("");
	}
}
