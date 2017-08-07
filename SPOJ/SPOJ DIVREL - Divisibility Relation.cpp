#include<bits/stdc++.h>
using namespace std;

int a[1005];
inline int gcd(int a, int b){ int t; while (b){ a = a%b; t = a; a = b; b = t; }return a; }
int main(){
    freopen("uva.txt","rt",stdin);
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	vector<int> ret;
	ret.push_back(a[0]);
	for (int i = 0; i < n; i++){
		vector<int> cur;
		cur.push_back(a[i]);
		int g = a[i];
		for (int j = 0; j < n; j++) if (i != j && gcd(g, a[j]) == 1)
			cur.push_back(a[j]);

	}
}

