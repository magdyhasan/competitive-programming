#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;


struct edge{
	int to, wordId, used;
	edge(int a = 0, int b = 0, int c = 0) :to(a), wordId(b), used(c)	{}
};


string words[1005];
int indeg[27], outdeg[27];
vector<edge> adj[27];
int n, m;
vector<int> tour;

void dfs(int u){
	for (int i = 0; i < adj[u].size(); i++) {
		edge &v = adj[u][i];
		if (v.used == 0) {
			v.used = 1;
			dfs(v.to);
			tour.push_back(v.wordId);
		}
	}
	return;
}

int main(){
    freopen("uva.txt","rt",stdin);
	int tc;	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < 27; i++)	adj[i].clear(), indeg[i] = outdeg[i] = 0; // init
		for (int i = 0; i < n; i++)	cin >> words[i];
		sort(words, words + n); // sort all words so when we start tour we get lexigrophically least string
		for (int i = 0; i < n; i++) {
			int x = words[i][0] - 'a';	int y = words[i].back() - 'a'; // for each word(x..y) add indeg and outdeg
			indeg[x]++;	outdeg[y]++;
			adj[x].push_back(edge{ y, i, 0 }); // word i starting with x can go to word starting with y
		}
		/*directed graph can have euler cycle/path
			- Euler cycle: In-Deg == Out-Deg for all nodes
			- Euler path
				- start node : In - Deg = Out - Deg - 1
				- end node : In - Deg = Out - Deg + 1
				- others : In - Deg = Out - Deg
		*/
		int a = 0, b = 0, c = 0;
		for (int i = 0; i < 26; i++)
			if (indeg[i] == outdeg[i] - 1)	a++; // we can have this at most once as end node 
			else if (indeg[i] == outdeg[i] + 1)	b++;// we can have this at most once as start node 
			else if (indeg[i] != outdeg[i])	c++; // nodes other than start,end can never have indeg[i]!=outdeg[i]
		if (c) {
			puts("***");
			continue;
		}
		tour.clear();
		for (int i = 0; i < 26; i++)	if (indeg[i] == outdeg[i] + 1)	dfs(i); // if we have euler cycle
		if (tour.empty())	for (int i = 0; i < 26; i++)	if (outdeg[i]) { dfs(i); break; } // if we might have euler path
		if (tour.size() != n)  // if we didn't have euler path/cycle
			puts("***");
		else {
			for (int i = n - 1; i >= 0; i--)
				printf("%s%s", words[tour[i]].c_str(), (i) ? "." : "");
			puts("");
		}
	}
}

