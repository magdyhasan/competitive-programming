#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;


string words[105];
int adj[105][105], inDeg[105], outDeg[105];

int main(){
    freopen("uva.txt","rt",stdin);
	int n, m, i, tc = 0;
	while (scanf("%d%d", &n) == 1) {
		for (int i = 0; i < n; i++)
			cin >> words[i];
		memset(inDeg, 0, sizeof(inDeg));
		memset(outDeg, 0, sizeof(outDeg));
		scanf("%d", &m);
		char a[55], b[55];
		for (i = 0; i < m; i++) {
			scanf("%s%s", a, b);
			int aa = find(words, words + n, a) - words;
			int bb = find(words, words + n, b) - words;
			adj[aa][outDeg[aa]++] = bb;
			inDeg[bb]++;
		}
		printf("Case #%d: Dilbert should drink beverages in this order:", ++tc);
		int j;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++)
				if (!inDeg[j]) break;
			inDeg[j] = -1;
			printf(" %s", words[j].c_str());
			for (int k = 0; k < outDeg[j]; k++)
				inDeg[adj[j][k]]--;
		}
		puts(".\n");
	}
}
