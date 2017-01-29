#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<queue>
#include<vector>
using namespace std;

vector< vector<int> > adj(100005);
int degree[100005];
int n, to, from;

int main(){
    scanf("%d", &n);
	for (int i = 0; i < n-1; i++) {
		scanf("%d%d", &to, &from);
		adj[from].push_back(to);
		adj[to].push_back(from);
		degree[from]++; 
		degree[to]++;
	}
	queue<int> leafNodes;
	for (int i = 1; i <= n; i++)
		if (adj[i].size() == 1) // if it's a leaf
			leafNodes.push(i);

	int ret = 0;
	while (!leafNodes.empty()) {
		int u = leafNodes.front();
		leafNodes.pop();
		if (degree[u] != 1) // if this node is not a leaf yet
			continue;
		ret++; // we put this node in the set
		for (auto p_u : adj[u]) // find parent of u
			if (degree[p_u] > 0) { // there's only one parent of u and it has adjacent nodes > 0
				degree[p_u] = 0; // we have this node in the set now 
				for (auto c_p_u : adj[p_u]) // remove all it's child that share edge with p_u
					if (--degree[c_p_u] == 1) // if this still has adjacent nodes other than the one we put on set
						leafNodes.push(c_p_u);
			}
	}
	printf("%d\n", ret);
}	
