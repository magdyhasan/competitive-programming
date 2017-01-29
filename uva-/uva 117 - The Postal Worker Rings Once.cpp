#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<queue>
#include<utility>
#include<vector>
#include<functional>
using namespace std;

typedef pair<int, int> node;
#define node(a,b) make_pair(a,b)
#define cost first
#define id second

int edges[30];
int adj[30][30];
char str[100005];
bool vis[30];
int S, T;

void add_street(){
	int len = strlen(str);
	adj[str[0] - 'a'][str[len - 1] - 'a'] = len;
	adj[str[len - 1] - 'a'][str[0] - 'a'] = len;
	edges[str[0] - 'a']++;
	edges[str[len - 1] - 'a']++;
	return;
}

int dijskstra(){
	memset(vis, 0, sizeof(vis));
	priority_queue<node, vector<node>, greater<node> > pq;
	pq.push(node(0, S));

	while (pq.empty() == false) {
		node u = pq.top();
		pq.pop();
		if (u.id == T)	return u.cost;
		if (vis[u.id])	continue;
		vis[u.id] = 1;
		for (int v = 0; v < 30; v++)
			if (vis[v] == false && adj[u.id][v])
				pq.push(node{ adj[u.id][v] + u.cost, v });
	}
}
	
int main(){
	while (scanf("%s",str) != EOF){
		memset(adj, 0, sizeof(adj));
		memset(edges, 0, sizeof(edges));
		add_street();
		while (scanf("%s", str) && strcmp(str, "deadend"))	add_street();
		bool oddvertix = 0;
		int sumOfDegrees = 0;
		for (int i = 0; i < 30; i++)
			for (int j = i + 1; j < 30; j++)
				sumOfDegrees += adj[i][j]; // cost of euler circuit 
		S = -1;
		for (int i = 0; i < 30;i++)
			if (edges[i] % 2 && S == -1)  // if we have 2 nodes with odd degree
				S = i;
			else if(edges[i] %2){
				T = i;
				sumOfDegrees += dijskstra(); // we add the cost of going from one of them to other ( because after we do euler path we have to return from one of them to the other )
			}
		printf("%d\n", sumOfDegrees);
	}
}
