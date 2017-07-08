#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

bool vis[64];
int n;

vector<char> ava[30];
vector<string> full[30];

int ret[30];

void rec(int idx){
	if (idx >= n) return; 
	for (char c = 'a'; c <= ('a' + n - 1); c++){
		int cnt = 0;
		for (int i = 0; i < n; i++) if (!vis[i] && find(ava[i].begin(), ava[i].end(), c) != ava[i].end())
			cnt++;
		if (cnt == 1){
			for (int i = 0; i < n; i++) if (!vis[i] && find(ava[i].begin(), ava[i].end(), c) != ava[i].end()){
				ret[c - 'a'] = i;
				vis[i] = 1;
				break;
			}
			rec(idx + 1);
			return;
		}
	}
}

char st[100500];

int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	for (int tc = 1; tc <= T;tc++){
		for (int i = 0; i < 30; i++) vis[i] = 0, ava[i].clear(), full[i].clear();
		scanf("%d", &n);
		for (int i = 0; i < n; i++){
			int k; scanf("%d", &k);
			for (int j = 0; j < k; j++){
				scanf("%s", st);
				for (int it = 0; st[it]; it++) st[it] |= 32;
				ava[i].push_back(st[0]);
				st[0] &= ~(32);
				full[i].push_back(st);
			}
		}
		rec(0);
		printf("Case #%d:\n", tc);
		for (int i = 0; i < n; i++){
			for (string ss : full[ret[i]]) if (ss[0] == (i + 'A'))
				puts(ss.c_str());
		}
	}
}
