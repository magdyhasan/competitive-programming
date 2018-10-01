/*
notice that if we reach some configuration where i-th is not coming but he is cnt what igor expected,
then we can always solve this by making him come and this will solve it

so from the beginning if some i-th have 0 cnt, then make him come and decrase all his contacts
now we have problem with n-1 because this one is solved by him coming, and all his contacts are decrased and can start solving again

*/
#include<bits/stdc++.h>
using namespace std;


const int maxn = 300500;

int a[105];
char adj[105][105];


int main(){
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%s", adj + i);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	vector<int> ret;
	while (true){
		int z = -1;
		for (int i = 0; i < n; i++) if (a[i] == 0){
			z = i;
			break;
		}
		if (z == -1) break;
		for (int j = 0; j < n; j++) if (adj[z][j] == '1')
			a[j]--;
		ret.push_back(z + 1);
	}
	sort(ret.begin(), ret.end());
	printf("%d\n", ret.size());
	for (int i : ret) printf("%d ", i);
}