#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 10500;

typedef long long ll;
int res[maxn];

int main(){
	freopen("uva.txt", "r", stdin);
	int cur = 1, n = 0;
	while (cur+n < maxn){
		for (int t = 0; t < cur; t++) {
			++n;
			res[n] = res[n - 1] + cur;
		}
		cur++;
	}
	while (scanf("%d", &n)){
		if (n == 0)	 break;
		printf("%d %d\n",n, res[n]);
	}
}