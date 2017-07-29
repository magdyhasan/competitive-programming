#include<bits/stdc++.h>
using namespace std;

int a[105][105];

typedef pair<int, int> pii;

int main(){
    freopen("uva.txt","rt",stdin);
	int n; scanf("%d", &n);
	int cur = 1;
	vector<pii> pos;
	for (int i = 0; i < n; i++) pos.push_back({ 0, i });
	for (int i = 1; i < n; i++) pos.push_back({ i, n - 1 });
	for (int it = 0; it+1 < 2 * n; it++){
		int i = pos[it].first, j = pos[it].second;
		while (i >= 0 && j >= 0 && i < n && j < n){
			a[i][j] = cur++;
			i++;
			j--;
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = n - 1; j >= 0; j--) printf("%d ", a[i][j]);
		puts("");
	}
}

