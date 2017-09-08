#include<bits/stdc++.h>
using namespace std;

int a[300500];
bool used[300500];

vector<int> adj[300500];

int main(){
    freopen("uva.txt","rt",stdin);
	int m = 0;
	while (scanf("%d", &a[m++]) == 1);
	m-- ;
	int n = a[m - 1];
	map<int, int> cnt;
	set<int> s;
	for (int i = 1; i <= n; i++) s.insert(i);
	for (int i = 0; i < m; i++) cnt[a[i]]++, s.erase(a[i]);
	for (int i = 0; i < m; i++){
		int app = *s.begin();
		s.erase(s.begin());
		cnt[a[i]]--;
		if (cnt[a[i]] == 0) s.insert(a[i]);
		adj[app].push_back(a[i]);
		adj[a[i]].push_back(app);
	}
	for (int i = 1; i <= n; i++){
		printf("%d:", i);
		sort(adj[i].begin(), adj[i].end());
		for (int j : adj[i]) printf(" %d", j);
		puts("");
	}
}

