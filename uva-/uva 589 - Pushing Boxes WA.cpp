#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


int d[512][512];
char gr[20][20];

int di[] = { 1, -1, 0, 0 };
int dj[] = { 0, 0, -1, 1 };
char ds[] = { 's', 'n', 'w', 'e', 'S', 'N', 'W', 'E' };
int prv[512][512][3];

struct node{
	int i, j, a, b, co;
	bool operator < (const node &a) const {
		return co > a.co;
	}
};

int n, m;
inline bool isValid(int i, int j)	{
	return (i >= 0 && j >= 0 && i < n && j < m);
}

int main(){
    freopen("uva.txt","rt",stdin);
	int tc = 0;
	while (scanf("%d%d",&n,&m)){
		if (!n && !m) break;
		if (tc) puts("");
		++tc;
		printf("Maze #%d\n", tc);
		for (int i = 0; i < n; i++) 
			scanf("%s", &gr[i]);
		int si = 1, sj = 1, bi = 1, bj = 1, ti = 1, tj = 1;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++){
			if (gr[i][j] == 'T') ti = i, tj = j;
			else if (gr[i][j] == 'S') si = i, sj = j;
			else if (gr[i][j] == 'B') bi = i, bj = j;
		}	
		for (int i = 0; i < 512; i++) for (int j = 0; j < 512; j++)
			d[i][j] = -1, prv[i][j][0] = -1;
		priority_queue<node> q; 
		node cur;
		q.push({ si, sj, bi, bj, 0 });
		d[si*m + sj][bi*m+bj] = 0;
		while (!q.empty()){
			cur = q.top(); q.pop();
			if (cur.a == ti && cur.b == tj) break;
			//move alone
			for (int k = 0; k < 4; k++){
				int ni = cur.i + di[k];
				int nj = cur.j + dj[k];
				if (!isValid(ni, nj) || gr[ni][nj] == '#' || (ni == cur.a&&nj == cur.b)) continue;
				if (d[ni*m + nj][cur.a*m + cur.b] != -1 
					&& d[ni*m + nj][cur.a*m + cur.b] <= d[cur.i*m + cur.j][cur.a*m + cur.b] + 1) continue;
				d[ni*m + nj][cur.a*m + cur.b] = d[cur.i*m + cur.j][cur.a*m + cur.b] + 1;
				q.push({ ni, nj, cur.a, cur.b, d[ni*m + nj][cur.a*m + cur.b] });
				prv[ni*m + nj][cur.a*m + cur.b][0] = cur.i*m + cur.j;
				prv[ni*m + nj][cur.a*m + cur.b][1] = cur.a*m + cur.b;
				prv[ni*m + nj][cur.a*m + cur.b][2] = k;
			}
			// mvoe box
			for (int ad = 0; ad < 4; ad++) {
				int ni = cur.i + di[ad], ni2 = ni + di[ad];
				int nj = cur.j + dj[ad], nj2 = nj + dj[ad];
				if (!isValid(ni, nj) || !isValid(ni2, nj2) || gr[ni2][nj2] == '#' || !(ni == cur.a&&nj == cur.b)) continue;
				if (d[cur.a*m + cur.b][ni2*m + nj2] != -1 
					&& d[cur.a*m + cur.b][ni2*m + nj2] <= d[cur.i*m + cur.j][cur.a*m + cur.b] + 100000) continue;
				d[cur.a*m + cur.b][ni2*m + nj2] = d[cur.i*m + cur.j][cur.a*m + cur.b] + 100000;
				q.push({ ni, nj, ni2, nj2, d[cur.a*m + cur.b][ni2*m + nj2] });
				prv[cur.a*m + cur.b][ni2*m + nj2][0] = cur.i*m + cur.j;
				prv[cur.a*m + cur.b][ni2*m + nj2][1] = cur.a*m + cur.b;
				prv[cur.a*m + cur.b][ni2*m + nj2][2] = ad + 4;
			}
		}
		bool f = 0;
		int mi = 123456789;
		for (int i = 0; i < n && !f; i++)for (int j = 0; j < m&& !f; j++) if (d[i*m + j][ti*m + tj] != -1)
			mi = min(mi, d[i*m + j][ti*m + tj]);
		for (int i = 0; i < n && !f; i++)for (int j = 0; j < m&& !f; j++) if (d[i*m + j][ti*m + tj] == mi){
			f = 1;
			vector<int> pa;
			int a = i * m + j, b = ti*m + tj;
			while (prv[a][b][0] != -1){
				pa.push_back(prv[a][b][2]);
				int t1 = prv[a][b][0], t2 = prv[a][b][1];
				a = t1, b = t2;
			}
			reverse(pa.begin(), pa.end());
			for (int i : pa) putchar(ds[i]);
			puts("");
		}
		if (!f) puts("Impossible.");
	}

}

