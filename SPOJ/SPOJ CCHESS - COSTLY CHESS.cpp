#include<bits/stdc++.h>
using namespace std;


bool isValid(int i, int j){
	return (i >= 0 && i < 8 && j >= 0 && j < 8);
}

int vis[8][8];

struct node{
	int i, j, co;
	node(int a, int b, int c) : i(a), j(b), co(c)	{}
	bool operator < (const node &a) const  {
		return co > a.co;
	}
};

int di[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int dj[] = { 1, -1, 1, -1, 2, -2, 2, -2 };


int dijkstra(int si, int sj, int ti, int tj){
	memset(vis, 0, sizeof(vis));
	priority_queue<node > pq;
	pq.push(node(si, sj, 0));
	while (pq.empty() == false) {
		node u = pq.top();
		pq.pop();
		if (u.i == ti && u.j == tj)	return u.co;
		if (vis[u.i][u.j])	continue;
		vis[u.i][u.j] = 1;
		for (int k = 0; k < 8; k++){
			int ni = u.i + di[k], nj = u.j + dj[k];
			if (!isValid(ni, nj) || vis[ni][nj]) continue;
			pq.push({ ni, nj, u.co + u.i*ni + u.j*nj });
		}
	}
	return -1;
}

int main(){
    freopen("uva.txt","rt",stdin);
	int si, sj, ti, tj;
	while (scanf("%d%d%d%d", &si, &sj, &ti, &tj) == 4){
		printf("%d\n", dijkstra(si, sj, ti, tj));
	}
}
