#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

char st[10005], li[10500][105];


int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	while (T--){
		scanf("%s", st);
		int ln = strlen(st);
		int n; scanf("%d", &n);
		map<string, pair<int, int>> wo;
		map<string, pair<int, int>>::iterator it;
		for (int i = 0; i < n; i++){
			scanf("%s", li[i]);
			string t(li[i]);
			// we care about first and last letters and sorted of other letters, so just sort all and add first and last
			sort(t.begin(), t.end());
			t = t + li[i][0] + li[i][strlen(li[i]) - 1];
			if (wo.find(t) == wo.end()) wo[t] = { 1, i };// if this patter first to occur
			else wo[t].first++;// this occured before, increase number of it
		}
		int dp[1005] = {}, prv[1005][2] = {};// prv to track my steps if there's only one solution
		dp[0] = 1;
		for (int i = 0; i < ln; i++) if (dp[i])for (int j = 1; j < 105 && j + i <= ln; j++){
			char tempc = st[i + j];// start at st[i] and end at st[j-1]
			st[i + j] = '\0';// mark end of string i want
			string t(st + i);
			sort(t.begin(), t.end());// make it listed to match it with some pattern
			t = t + st[i] + st[i + j - 1];
			it = wo.find(t);
			if (it != wo.end()){// if i can find a pattern like this
				dp[i + j] += it->second.first*dp[i];
				if (dp[i + j] > 2) dp[i + j] = 2;// i only care whether i can go only 1 or > 1
				prv[i + j][0] = i;// track
				prv[i + j][1] = it->second.second;
			}
			st[i + j] = tempc;
		}
		if (dp[ln] == 0) puts("impossible");// couldn't find whole sentence
		else if (dp[ln] > 1) puts("ambiguous");// more than one way
		else{
			vector<int> ret;
			while (ln){
				ret.push_back(prv[ln][1]);
				ln = prv[ln][0];
			}
			reverse(ret.begin(), ret.end());
			for (int i = 0; i < ret.size();i++) printf("%s%s",(i==0)?"":" ", li[ret[i]]);
			puts("");
		}
	}
}
