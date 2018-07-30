/*
	key observatoin is that each shape has different number of holes on it

	so just doing flood-fill and counting number of adjacent shapes or empty cells can tell us
*/
#include<bits/stdc++.h>
using namespace std;


string gr[1024];

string htd(char x){
	switch (x){
		case '0': return "0000";
		case '1': return "0001";
		case '2': return "0010";
		case '3': return "0011";
		case '4': return "0100";
		case '5': return "0101";
		case '6': return "0110";
		case '7': return "0111";
		case '8': return "1000";
		case '9': return "1001";
		case 'a': return "1010";
		case 'b': return "1011";
		case 'c': return "1100";
		case 'd': return "1101";
		case 'e': return "1110";
		case 'f': return "1111";
	}
}

int di[] = { 1, -1, 0, 0 };
int dj[] = { 0, 0, 1, -1 };

int n, m, cnt;
int co[1024][1024], in[1024][1024];

void bfs(int i, int j, int c){
	queue<int> q;
	q.push(i); q.push(j);
	while (!q.empty()){
		i = q.front(); q.pop();
		j = q.front(); q.pop();
		co[i][j] = c;
		in[i][j] = 0;
		for (int k = 0; k < 4; k++){
			int ni = i + di[k];
			int nj = j + dj[k];
			if (ni < 0 || nj < 0 || ni >= n || nj >= m || gr[i][j] != gr[ni][nj] || co[ni][nj] || in[ni][nj]) continue;
			q.push(ni);
			q.push(nj);
			in[ni][nj] = 1;
		}
	}
}

set<int> ne[300500];

int main(){
    freopen("uva.txt","rt",stdin);
	int tc = 0;
	while (cin >> n >> m){
		if (n == 0) break;
		memset(co, 0, sizeof co);
		for (int i = 0; i < n; i++){
			string st; cin >> st;
			if (i == 0) gr[i] = string(m * 4 + 2, '0');
			gr[i+1] = "0";
			for (char c : st)
				gr[i+1] += htd(c);
			gr[i + 1] += "0";
		}
		gr[n + 1] = string(m * 4 + 2, '0');
		n += 2;
		m = m * 4 + 2;
		cnt = 0;
		vector<int> shcnt;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (!co[i][j]){
			bfs(i, j, ++cnt);
			if (gr[i][j] == '1')
				shcnt.push_back(cnt);
		}
		for (int i = 0; i <= cnt; i++) ne[i].clear();
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (gr[i][j] == '1'){
			for (int k = 0; k < 4; k++){
				int ni = i + di[k];
				int nj = j + dj[k];
				if (i < 0 || j < 0 || i >= n || j >= m || co[ni][nj] == co[i][j])
					continue;
				ne[co[i][j]].insert(co[ni][nj]);
			}
		}
		string name = "#WAKJSD";
		vector<char> ans;
		for (auto i : shcnt) ans.push_back(name[ne[i].size()]);
		sort(ans.begin(), ans.end());
		cout << "Case " << ++tc << ": " << string(ans.begin(),ans.end()) << "\n";
	}
}
