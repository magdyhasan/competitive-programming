#include<bits/stdc++.h>
using namespace std;


int a[1048][7000];
char gr[512][7000][100];

int n, m;

int rec(int i, int j){
	if (a[i][j] != -1) return a[i][j];
	int s = 0;
	istringstream iss(gr[i][j]);
	string st;
	while (iss >> st){
		int ni = 0, nj = 0;
		for (char ch : st)
			if (isdigit(ch)) ni = ni * 10 + (ch - '0');
			else nj = nj * 26 + (ch - 'A' + 1);
		s += rec(ni, nj);
	}
	return (a[i][j] = s);
}

int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	while (T--){
		scanf("%d%d", &m, &n);
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++){
			scanf("%s", gr[i][j]);
			for (int k = 0; gr[i][j][k]; k++) if (gr[i][j][k] == '+' || gr[i][j][k] == '=')
				gr[i][j][k] = ' ';
			if (isdigit(gr[i][j][0])) a[i][j] = atoi(gr[i][j]);
			else a[i][j] = -1;
		}
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
			printf("%d%s", rec(i, j), (j == m) ? "\n" : " ");
	}
}
