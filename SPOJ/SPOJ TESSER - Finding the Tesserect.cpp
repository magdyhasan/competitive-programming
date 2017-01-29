#include<stdlib.h>
#include<stdio.h>
#include<cstring>
using namespace std;

int a[100500];
char p[100500];

int pat[100500], lprefix[100500];

bool check(int a, int b, char t){
	if (t == 'G') return a < b;
	if (t == 'L') return a > b;
	return a == b;
}

int main(){
    freopen("uva.txt","rt",stdin);
	int T;
	scanf("%d", &T);
	while (T--){
		int n;	scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", a + i);
		scanf("%s", p);
		int m = strlen(p);
		for (int i = 1, k = 0; i < m; i++){
			while (k > 0 && p[i] != p[k]) k = lprefix[k - 1];
			if (p[k] == p[i]) lprefix[i] = ++k;
			else lprefix[i] = k;
		}
		bool f = false;
		for (int i = 0, k = 0; i+1 < n; i++){
			while (k > 0 && !check(a[i], a[i + 1], p[k])) k = lprefix[k - 1];
			if (check(a[i], a[i + 1], p[k])) k++;
			if (k == m){
				f = true;
				break;
			}
		}
		puts(f ? "YES" : "NO");
	}
}
