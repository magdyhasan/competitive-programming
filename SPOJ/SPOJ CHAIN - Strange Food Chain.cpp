/*

	hint: use DSU

	For each component in the DSU keep additonal information, 
	who can this component eat, deonted as nxt[u]
	and who can eat this component, denoted as prv[u]

	now when mergeing we can merge nxt and prv easily for each component 
	and the queiries are trivial with this info.
*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 300500;

int pa[maxn], nxt[maxn], prv[maxn];

int par(int x){
	return pa[x] == x ? x : (pa[x] = par(pa[x]));
}

void merge(int x, int y){
	int u = par(x), v = par(y);
	if (u != v)
		pa[v] = u;
}

void merge_all(int x, int y){
	merge(x, y);
	merge(prv[x], prv[y]);
	merge(nxt[x], nxt[y]);
}

bool same(int x, int y){
	return par(x) == par(y);
}

bool eq(int x, int y){
	if (same(nxt[x], y) || same(prv[x], y)) return 0;
	return 1;
}


int a, b, c;

int main(){
    freopen("uva.txt","rt",stdin);
	int tc; scanf("%d", &tc);
	while (tc--){
		int n, k; scanf("%d%d", &n, &k);
		for (int i = 0; i < n * 3; i++){
			pa[i] = i;
			nxt[i] = (i + n) % (n * 3);
			prv[i] = (i + 2 * n) % (n * 3);
		}
		a = n + 1, b = n + 2, c = n + 3;
		int ret = 0;
		while (k--){
			int ty, x, y; 
			scanf("%d%d%d", &ty, &x, &y);
			if (x > n || y > n) ret++;
			else{
				if (ty == 1){
					if (!eq(x, y)) ret++;
					else merge_all(x, y);
				}
				else{
					if (!eq(x, prv[y]))ret++;
					else merge_all(x, prv[y]);
				}
			}
		}
		printf("%d\n", ret);
	}
}
