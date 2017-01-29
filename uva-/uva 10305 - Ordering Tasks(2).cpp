#include<stdlib.h>
#include<stdio.h>
#include<cstring>
using namespace std;

int n, m, from, to;
int adj[105][105];
int inDeg[105], outDeg[105];


int main(){
	freopen("uva.txt", "r", stdin);
	while (scanf("%d%d", &n, &m)) {
		if (n == 0 && m == 0)
			break;
		memset(adj, 0, sizeof(adj));
		memset(inDeg, 0, sizeof(inDeg));
		memset(outDeg, 0, sizeof(outDeg));
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &from, &to);
			inDeg[to]++;
			adj[from][outDeg[from]++] = to;
 		}
		int j;
		for (int i = 0; i < n; i++) {
			for (j = 1; j <= n; j++)
				if (!inDeg[j])
					break;
			printf("%s%d", i ? " " : "", j);
			inDeg[j] = -1;
			for (int k = 0; k < outDeg[j]; k++)
				inDeg[adj[j][k]]--;
		}
		puts("");
	}
}
