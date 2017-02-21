#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int a[105][105], ta[105][105];

int dx[] = { 1, -1, 0, 0 },
	dy[] = { 0, 0, 1, -1 };

int p, n, m, K;

bool isValid(int i, int j){
	return (i >= 0 && j >= 0 && i < n && j < m);
}

int main(){
    freopen("uva.txt","rt",stdin);
	while (scanf("%d%d%d%d", &p, &n, &m, &K)){
		if (!p && !n && !m && !K) break;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
		for (int st = 0; st < K; st++){
			for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) ta[i][j] = a[i][j];
			for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) for (int k = 0; k < 4; k++) {
				int ni = i + dx[k], nj = j + dy[k];
				if (!isValid(ni, nj) || a[ni][nj] != ((a[i][j]+1)%p)) continue;
				ta[ni][nj] = a[i][j];
			}
			for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) a[i][j] = ta[i][j];
		}
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) printf("%d%s", a[i][j], (j + 1 == m) ? "\n" : " ");
	}
}
