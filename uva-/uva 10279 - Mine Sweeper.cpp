#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

char gr[12][12];
char to[12][12];
int a[12][12];

int n;

int dx[] = { -1, -1, -1, 1, 1, 1, 0, 0 };
int dy[] = { 0, -1, 1, 0, -1, 1, 1, -1 };

bool isValid(int i, int j){
	return (i >= 0 && j >= 0 && i < n && j < n);
}

int main(){
    freopen("uva.txt","rt",stdin);
	int T;	scanf("%d", &T);
	while (T--){
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%s", gr[i]);
		for (int i = 0; i < n; i++)  scanf("%s", to[i]);
		bool ast = false;
		memset(a, 0, sizeof(a));
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				ast |= (gr[i][j] == '*' && to[i][j] == 'x');
				for (int k = 0; k < 8; k++){
					int ni = i + dx[k];
					int nj = j + dy[k];
					if (!isValid(ni, nj)) continue;
					a[i][j] += gr[ni][nj] == '*';
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (gr[i][j] == '*'){
					if (ast) putchar('*');
					else putchar('.');
				}
				else if (to[i][j] == 'x')
					putchar((a[i][j] + '0'));
				else
					putchar('.');
			}
			puts("");
		}
		if (T) puts("");
	}
}
