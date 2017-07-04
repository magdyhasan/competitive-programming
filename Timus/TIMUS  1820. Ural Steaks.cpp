#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
	freopen("uva.txt", "rt", stdin);
	int n, k;
	scanf("%d%d", &n, &k);
	queue<int> q0, q1, qf; 
	int out = 0, ti = 0;
	for (int i = 1; i <= n; i++) q0.push(-1);
	while (out < n){
		while (qf.size() < k && q0.size() > 0) qf.push(q0.front()), q0.pop();
		while (qf.size() < k && q1.size() > 0) qf.push(q1.front()), q1.pop();
		ti++;
		while (!qf.empty()){
			int u = qf.front(); qf.pop();
			if (u == -1) q1.push(1);
			else out++;
		}
	}
	printf("%d\n", ti);
}

