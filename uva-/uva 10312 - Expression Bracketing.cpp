#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


typedef long long ll;


ll C[100];
ll all[] = { 1, 1, 3, 11, 45, 197, 903, 4279, 20793, 103049, 518859, 2646723, 13648869, 71039373, 372693519, 1968801519, 10463578353, 55909013009, 300159426963, 1618362158587, 8759309660445, 47574827600981, 259215937709463, 1416461675464871, 7760733824437545, 42624971294485657, 234643073935918683, 1294379445480318899, 7154203054548921813 };



int main(){
    freopen("uva.txt","rt",stdin);
	C[0] = 1;
	for (int i = 1; i <= 30; i++) {
		C[i] = 0;
		for (int k = 1; k <= i; k++)
			C[i] += (C[k - 1] * C[i - k]); // for each root k we have left subtree with (k-1)nodes and right substree with (i-k)nodes
	}
	int n; 
	while (scanf("%d", &n) == 1){
		printf("%lld\n", all[n - 1] - C[n - 1]);
	}
}
