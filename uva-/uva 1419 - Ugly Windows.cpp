#include<stdlib.h>	
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

char a[150][150];
bool vis[105][105];
int n, m;

int mxx, mix, mxy, miy;

int dx[] = { 1, -1, 0, 0 },
	dy[] = { 0, 0, 1, -1 };
int dfs(int i, int j, char ch){
	if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || a[i][j] != ch) return 0;
	vis[i][j] = 1;
	int ret = 1;
	mxx = max(mxx, i), mxy = max(mxy, j);
	mix = min(mix, i), miy = min(miy, j);
	for (int k = 0; k < 4; k++)
		ret += dfs(i + dx[k], j + dy[k], ch);
	return ret;
}


int main(){
    freopen("uva.txt","rt",stdin);
	while (scanf("%d%d", &n, &m)){
		if (!n&&!m) break;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; i++) scanf("%s", a[i]);
		set<char> ret;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) 
			if (a[i][j] >= 'A' && a[i][j] <= 'Z' && !vis[i][j]){
				mxx = -1, mxy = -1;
				mix = 100, miy = 100;
				int cnt = dfs(i, j, a[i][j]);
				int width = (mxx - mix + 1), height = (mxy - miy - 1);
				if (width*2 + height*2 == cnt && dfs(i + 1, j + 1, '.') == (width - 2)* height)
					ret.insert(a[i][j]);
			}
		for (char ch : ret) putchar(ch);
		puts("");
	}
}
