#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int n, nmsk; 

char st[32][105];
int sz[32];
string dp[1 << 15];
bool vis[1 << 15];

string rec(int msk, string cur){
	if (msk == nmsk) return "";
	string &ret = dp[msk];
	if (vis[msk]) return ret;
	string s = cur;
	for (int i = 0; i < msk; i++) if(!(msk&(1<<i))) {
		int nmsk = msk | (1 << i);
	}
}


int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++){
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%s", st[i]);

	}
}

