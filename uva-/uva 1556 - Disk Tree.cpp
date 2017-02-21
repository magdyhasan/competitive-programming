#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<sstream>
#include<algorithm>
using namespace std;

struct Node{
	string st;
	map<string, int> nxt;
	Node(string s = ""){
		st = s;
		nxt.clear();
	}
} trie[1000500];
int nodes;

void add(vector<string> &path){
	int idx = 0;
	for (int i = 0; i < path.size(); i++){
		if (trie[idx].nxt.find(path[i]) == trie[idx].nxt.end()){
			trie[++nodes] = Node(path[i]);
			trie[idx].nxt[path[i]] = nodes;
		}
		idx = trie[idx].nxt[path[i]];
	}
}

void dfs(int u, int pad){
	if (u){
		for (int i = 0; i < pad; i++) putchar(' ');
		puts(trie[u].st.c_str());
	}
	for (auto v : trie[u].nxt)
		dfs(v.second, pad + 1);
}

int main(){
    freopen("uva.txt","rt",stdin);
	char st[1005];
	int n;
	while (scanf("%d", &n) == 1){
		nodes = 0;
		trie[0] = Node("");
		for (int i = 0; i < n; i++){
			scanf("%s", st);
			for (int j = 0; st[j]; j++) if (st[j] == '\\') st[j] = ' ';
			istringstream iss(st);
			vector<string> v; string tv;
			while (iss >> tv) v.push_back(tv);
			add(v);
		}
		dfs(0, -1);
		puts("");
	}
}
