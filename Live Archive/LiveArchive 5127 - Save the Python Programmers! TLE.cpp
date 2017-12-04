#include<bits/stdc++.h>
using namespace std;


char li[800500];
vector<int> adj[32];
map<char, int> ma;

int n;

int getnu(char ch){
	if (ma.find(ch) != ma.end()) return ma[ch];
	return (ma[ch] = n++);
}


vector<int> fa, fb;

int dp[20][20][20][20][20][20][2];



int main(){
    freopen("uva.txt","rt",stdin);
	while (gets(li)){
		n = 0;
		for (int i = 0; i < 32; i++) adj[i].clear();
		memset(dp, -1, sizeof(dp));
		ma.clear();
		istringstream iss(li);
		string cur;
		while (iss >> cur){
			int a = getnu(cur[0]);
			for (int i = 1; i < cur.size(); i++){
				int b = getnu(cur[i]);
				adj[a].push_back(b);
				adj[b].push_back(a);
			}
		}
		fa.clear(); fb.clear();
		fa.push_back(getnu('a'));	fa.push_back(getnu('b'));	fa.push_back(getnu('c'));
		fb.push_back(getnu('d'));	fb.push_back(getnu('e'));	fb.push_back(getnu('f'));
		sort(fa.begin(), fa.end());
		sort(fb.begin(), fb.end());
		queue<pair<pair<vector<int>, vector<int>>,int>> q;
		q.push({ { fa, fb }, 0 });
		q.push({ { fa, fb }, 1 });
		dp[fa[0]][fa[1]][fa[2]][fb[0]][fb[1]][fb[2]][0] = 0;
		dp[fa[0]][fa[1]][fa[2]][fb[0]][fb[1]][fb[2]][1] = 0;
		int ret = -1;
		while (!q.empty()){
			vector<int> a = q.front().first.first, b = q.front().first.second;
			int tu = q.front().second;
			q.pop();
			if (a == fb&&b == fa){
				ret = dp[a[0]][a[1]][a[2]][b[0]][b[1]][b[2]][tu];
				break;
			}
			if (tu != 0)
			for (int i = 0; i < 3; i++){
				for (int j : adj[a[i]]) {
					bool f = 1;
					for (int k = 0; k < 3 && f; k++) if (a[k] == j || b[k] == j) f = 0;
					if (f){
						vector<int> na;
						for (int k = 0; k < 3; k++) if (k != i)  na.push_back(a[k]);
						na.push_back(j);
						sort(na.begin(), na.end());
						if (dp[na[0]][na[1]][na[2]][b[0]][b[1]][b[2]][0] == -1){
							dp[na[0]][na[1]][na[2]][b[0]][b[1]][b[2]][0] = dp[a[0]][a[1]][a[2]][b[0]][b[1]][b[2]][1] + 1;
							q.push({ { na, b }, 0 });
						}
					}
				}
			}
			if (tu != 1)
			for (int i = 0; i < 3; i++){
				for (int j : adj[b[i]]) {
					bool f = 1;
					for (int k = 0; k < 3 && f; k++) if (a[k] == j || b[k] == j) f = 0;
					if (f){
						vector<int> nb;
						for (int k = 0; k < 3; k++) if (k != i)  nb.push_back(b[k]);
						nb.push_back(j);
						sort(nb.begin(), nb.end());
						if (dp[a[0]][a[1]][a[2]][nb[0]][nb[1]][nb[2]][1] == -1){
							dp[a[0]][a[1]][a[2]][nb[0]][nb[1]][nb[2]][1] = dp[a[0]][a[1]][a[2]][b[0]][b[1]][b[2]][0] + 1;
							q.push({ { a, nb }, 1 });
						}
					}
				}
			}
		}
		if (ret == -1) puts("No solution.");
		else printf("%d\n", ret);
	}
}
