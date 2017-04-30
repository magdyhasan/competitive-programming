#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;


int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	while (T--){
		int x; scanf("%d", &x);
		string best;
		for (int i = 0; i <= 250; i++) best += '8';
		int ans = -1;
		for (int e = 0; e  <= 200; e++) for (int s = 0; s + e <= 200; s++) {
			if (s + e == 0) continue;
			int cur = 0;
			string st;
			for (int i = 0; i < s + e; i++){
				if (i < e) cur = (cur * 10 + 8), st += '8';
				else cur = (cur * 10 + 6) , st += '6';
				if (cur > 1000500) cur %= x;
			}
			cur %= x;
			if (cur == 0){
				ans = 1;
				if (best.size() > st.size() ) best = st;
			}
		}
		if (ans == -1) puts("-1");
		else printf("%s\n", best.c_str());
	}
}

