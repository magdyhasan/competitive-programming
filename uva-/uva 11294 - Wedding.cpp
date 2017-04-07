/*
	just mark all pairs as (i*2,i*2+1) for h,w
	now suppose mark[i] mean i set on side of bride, and mark[i]==0 means set opposite to it
	just do 2-sat to find if possible to set all of them with no contraditicon with the given rules
*/

#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 100500;



struct TwoSAT
{
	int n, mark[maxn * 2], S[maxn * 2], c;
	vector<int> g[maxn * 2];
	bool dfs(int x)
	{
		if (mark[x ^ 1]) return false;
		if (mark[x]) return true;
		mark[x] = 1;
		S[c++] = x;
		for (int i = 0; i < g[x].size(); i++)
		{
			if (!dfs(g[x][i])) return false;
		}
		return true;
	}
	void init(int n)
	{
		this->n = n;
		for (int i = 0; i < maxn; i++)
			g[i].clear();
		memset(mark, 0, sizeof(mark));
		mark[1] = 1;
	}
	void add(int x, int xval, int y, int yval)
	{
		x = 2 * x + xval;
		y = 2 * y + yval;
		g[x ^ 1].push_back(y);
		g[y ^ 1].push_back(x);
	}
	bool solve(int n){
		for (int i = 0; i < 2 * n; i += 2){
			if (!mark[i] && !mark[i + 1]){
				c = 0;
				if (!dfs(i)){
					while (c) mark[S[--c]] = false;
					if (!dfs(i + 1)) return false;
				}
			}
		}
		return true;
	}
} sat;




int main(){
    freopen("uva.txt","rt",stdin);
	int n, m;
	while (scanf("%d%d", &n, &m) && n && m){
		sat.init(n);
		char c1, c2;
		int x1, x2;
		for (int i = 0; i < m; i++){
			scanf("%d%c%d%c", &x1, &c1, &x2, &c2);
			sat.add(x1, c1 == 'w', x2, c2 == 'w');
		}
		if (!sat.solve(n)) puts("bad luck");
		else{
			for (int i = 1; i < n; i++)
				printf("%d%c%s", i, sat.mark[2 * i] ? 'h' : 'w', i + 1 == n ? "\n" : " ");
		}
	}
}
