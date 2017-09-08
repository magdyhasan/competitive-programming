#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++){
		int n; scanf("%d", &n);
		vector<int> p2;
		for (int i = 30; i >= 0; i--) if (n&(1 << i)) p2.push_back(i);
		printf("%d %d", tc, p2.size());
		for (int i : p2) printf(" [%d,0]", i);
		puts("");
	}
}

