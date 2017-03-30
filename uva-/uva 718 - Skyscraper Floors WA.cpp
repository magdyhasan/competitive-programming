#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int f, e, a, b;
int di[50000500];
bool vis[50000500];
int gcd(int a, int b){
	return (!b ? a : gcd(b, a%b));
}

int lcm(int a, int b){
	return a*b / gcd(a, b);
}


int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	while (T--){
		scanf("%d%d%d%d", &f, &e, &a, &b);
		int u, v;
		vector<int> ele;
		for (int i = 0; i < e; i++){
			scanf("%d%d", &u, &v);
			di[v] = u;
			ele.push_back(v);
		}
		queue<int> q;	q.push(a);
		bool can = false;
		memset(vis, 0, sizeof(vis)); 
		vis[a] = 1;
		while (!q.empty())	{
			u = q.front();	 q.pop();
			if (u == b) {
				can = true;
				break;
			}
			for (int el : ele) if (!vis[el] && di[u] && lcm(el, u) % di[u] == 0)
				q.push(el), vis[el] = 1;
		}
		puts(can ? "It is possible to move the furniture." : "The furniture cannot be moved.");
	}
}
