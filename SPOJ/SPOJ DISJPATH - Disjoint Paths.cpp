#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<sstream>
#include<bits/stdc++.h>
using namespace std;

int n,k;
int cap[6000][6000], flow[6000][6000], f; 
int d[6000],prv[6000];
bool vis[6000];

bool augment(){
	memset(prv, -1, sizeof(prv));
	queue<int> q;	q.push(1);	
	while (!q.empty()){
		int u = q.front();	 q.pop();
		if (u == 2) break;
		for (int i = 0; i < 2 * n; i++)
			if (flow[u][i] < cap[u][i] && prv[i] == -1)
				q.push(i), prv[i] = u;
	}
	if (prv[2] == -1)	return false;
	int t = 2;
	while (t != 1){
		int pr = prv[t];
		flow[pr][t] ++;
		flow[t][pr] --;
		t = pr;
	}
	return true;
}



int main(){
    freopen("2.in","rt",stdin);
    int tc = 0, t;
    while(true){
		scanf("%d%d", &k, &n);
        if(n == 0 && k == 0)	break;
		memset(cap, 0, sizeof(cap));
		memset(flow, 0, sizeof(flow));
        printf("Case %d:\n",++tc);
		for (int i = 0; i < n; i++){
			char ch; 
			for (;;) {
				scanf("%d%c", &t, &ch);
				t--;
				cap[i * 2 + 1][2 * t] = 1;
				if (ch == '\n') break;
			}
			cap[i * 2][i * 2 + 1] = 1;
        }
		f = 0;
		for (int i = 0; i < k; i++) f += augment();
		if (f != k) puts("Impossible");
		else{
			for (int i = 0; i < 2 * n; i++) if (flow[1][i]){
				flow[1][i] = 0;
				printf("1 %d", 1 + i / 2);
				t = i;
				while (t != 2){
					for (int j = 0; j < n * 2; j++) if (flow[t][j] == 1){
						flow[t][j] = 0;
						t = j;
						if (t % 2 == 0) printf(" %d", 1 + t / 2);
						break;
					}
				}
				puts("");
			}
		}
		puts("");
    }
}
