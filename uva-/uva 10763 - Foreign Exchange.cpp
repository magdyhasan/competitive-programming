#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;


const int maxn = 700500;


map<int, multiset<int>> adj;

int a[700500], b[700500];

int main(){
    freopen("uva.txt","rt",stdin);
	int n;
	while (scanf("%d", &n)){
		if (!n) break;
		adj = map<int, multiset<int>>();
		for (int i = 0; i < n; i++)  scanf("%d%d", a + i, b + i), adj[a[i]].insert(b[i]);
		bool no = 0;
		for (int i = 0; i < n; i++) if (adj[b[i]].find(a[i]) == adj[b[i]].end()) no = 1;
		else{
			auto it = adj[b[i]].find(a[i]);
			adj[b[i]].erase(it);
		}
		if (no) puts("NO");
		else puts("YES");
	}
}

