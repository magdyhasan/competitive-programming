#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int a[12][12];

bool vis[12];

int ret;

void rec(int idx,int s){
	if (idx == 11){
		ret = max(ret, s);
		return;
	}
	for (int i = 0; i < 11; i++) if (!vis[i] && a[idx][i]){
		vis[i] = 1;
		rec(idx + 1, s + a[idx][i]);
		vis[i] = 0;
	}
}

int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	while (T--){
		vector<int> per;
		int n = 11;
		for (int i = 0; i < n; i++) per.push_back(i), vis[i] = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++)
				scanf("%d", a[i] + j);
		}
		ret = -1;
		rec(0, 0);
		printf("%d\n", ret);
	}
}

