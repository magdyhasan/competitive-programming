#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool r[5005], c[5005], rd[5005], ld[5005];
int n;
bool done;
vector<int> rcs;

void rec(int j){
	if (done) return;
	if (j == n+1){
		for (int t = 0; t < rcs.size(); t++)
			printf("%d%s", rcs[t], t + 1 == rcs.size() ? "\n" : " ");
		done = true;
		return;
	}
	for (int i = 1; i <= n && done == false;i++)
		if (r[i] == 0 && rd[i - j + n] == 0 && ld[i + j] == 0){
			r[i] = rd[i - j + n] = ld[i + j] = true;
			rcs.push_back(i);
			rec(j + 1);
			rcs.pop_back();
			r[i] = rd[i - j + n] = ld[i + j] = false;
		}
	return;
}

void solveEm2(){
	bool f = false;
	for (int i = 1; i <= n / 2; i++){
		if (f) printf(" ");
		f = true;
		printf("%d", i + n / i);
	}
}

int main(){
    freopen("uva.txt","rt",stdin);
	while (scanf("%d", &n) == 1){
		if (n)
	}
}
