#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


vector<string> g;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

bool vis[55][55];

ll rec(int i, int j){
	int ret = 0;
	vis[i][j] = 1;
	for (int k = 0; k < 4; k++){
		int ni = i + dx[k];
		int nj = j + dy[k];
		if (vis[ni][nj]) continue;
		if (g[ni][nj] == '#') ret++;
		else if (g[ni][nj] != '@') ret += rec(ni, nj);
	}
	return ret;
}

char st[111];

int main(){
    freopen("uva.txt","rt",stdin);
	int n;
	scanf("%d", &n);
	g.push_back(string(n + 2, '#'));
	for (int i = 0; i < n; i++){
		scanf("%s", st);
		string cur = "#";
		cur += st;
		cur += "#";
		g.push_back(cur);
	}
	g.push_back(string(n + 2, '#'));
	g[0][0] = g[0][1] = g[1][0] = '@';
	g[n + 1][n + 1] = g[n][n + 1] = g[n + 1][n] = '@';
	ll ret = rec(1, 1);
	if (!vis[n][n]) ret += rec(n, n);
	printf("%lld", ret*9LL);
}

