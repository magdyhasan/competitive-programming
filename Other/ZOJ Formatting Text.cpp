#include<bits/stdc++.h>
using namespace std;

const int maxn = 3000500;


int dp[maxn], dpline[maxn], prv[maxn];

char st[8000500];
vector<string > words;

int sqr(int x){
	return x*x;
}
int width;

void rec(int r){
	int l = prv[r];
	if (l > 0) rec(l);
	if (l + 1 == r){
		puts(words[l].c_str());
		return;
	}
	int tot = 0;
	for (int i = l; i < r; i++) tot += words[i].size();
	int spaces = r - l - 1;
	int sm = (width - tot) / spaces, la = sm, smn = spaces, lan = 0;
	if ((width - tot) % spaces) la++, lan = (width - tot) % spaces, smn -= lan;
	for (int i = l; i < r; i++){
		printf("%s", words[i].c_str());
		if (i-l < smn){
			for (int j = 0; j < sm; j++) putchar(' ');
		}
		else if(i-l<smn+lan) {
			for (int j = 0; j < la; j++) putchar(' ');
		}
	}
	puts("");
}

int main(){
    freopen("uva.txt","rt",stdin);
	while (scanf("%d", &width)){
		if (width == 0) break;
		gets(st);
		string ss;
		words.clear();
		while (gets(st)){
			if (st[0] == '\0') break;
			istringstream iss(st);
			while (iss >> ss){
				words.push_back(ss);
			}
		}
		int n = words.size();
		memset(dp, 63, sizeof(dp));
		memset(dpline, 63, sizeof(dpline));
		dp[0] = dpline[0] = 0, prv[0] = -1;
		for (int i = 0; i < n; i++){
			if (dp[i] + 500 < dp[i + 1] || (dp[i] + 500 == dp[i + 1] && dpline[i] + 1 <= dpline[i + 1])){
				dp[i + 1] = dp[i] + 500;
				dpline[i + 1] = dpline[i] + 1;
				prv[i + 1] = i;
			}
			int tot = words[i].size();
			for (int j = i + 1; j < n; j++){
				tot += words[j].size();
				if (tot + j - i > width) break;
				int spaces = j - i;
				int sm = (width - tot) / spaces, la = sm, smn = spaces, lan = 0;
				if ((width - tot) % spaces) la++, lan = (width - tot) % spaces, smn -= lan;
				int badnes = sqr(sm - 1)*smn + sqr(la - 1)*lan;
				if (dp[i] + badnes < dp[j + 1] || (dp[i] + badnes == dp[j + 1] && dpline[i] + 1 <= dpline[j + 1]))
					dp[j + 1] = dp[i] + badnes, dpline[j + 1] = dpline[i] + 1, prv[j + 1] = i;
			}
		}
		rec(n);
		puts("");
	}
}

