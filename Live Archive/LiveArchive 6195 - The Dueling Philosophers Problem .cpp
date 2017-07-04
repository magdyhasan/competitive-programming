#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

const int maxn = 15000;

vector<int> adj[maxn];
int in[maxn];


int main(){
    freopen("uva.txt","rt",stdin);
	int n, m;
	while (scanf("%d%d", &n, &m)){
		if (n == 0 && m == 0)	 break;
		for (int i = 0; i <= n; i++) adj[i].clear(), in[i] = 0;
		for (int i = 0; i < m; i++){
			int u, v;
			scanf("%d%d", &u, &v);
			adj[u].push_back(v);
			in[v] ++;
		}
		queue<int> q;
		for (int i = 1; i <= n; i++) if (in[i] == 0) q.push(i);
		bool mul = 0;
		while (!q.empty()){
			int u = q.front();	 q.pop();
			mul |= q.size() > 0; // we can choose multiple ordering if we have multiple vertices now to select
			for (int v : adj[u]){
				in[v]--;
				m--;
				if (in[v] == 0) q.push(v);
			}
		}
		if (m > 0) puts("0");// if we didn't use all graph edges then there's a ctcle
		else if (mul) puts("2"); // multiple ordering
		else puts("1");
	}
}

