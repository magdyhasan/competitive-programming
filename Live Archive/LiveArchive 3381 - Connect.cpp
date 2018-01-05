#include<bits/stdc++.h>
using namespace std;
struct p{
	int x, y;
	p(int a=0, int b=0){
		x = a;
		y = b;
	}
};

struct seg{
	p p1, p2;
	seg(p a, p b){
		p1.x = a.x;
		p1.y = a.y;
		p2.x = b.x;
		p2.y = b.y;
	}
};
int area(p A, p B, p C){
	return A.x*B.y + B.x*C.y + C.x*A.y - A.y*B.x - B.y*C.x - C.y*A.x;
}

bool intersection(seg A, seg B){
	if (A.p1.x == B.p1.x && A.p1.y == B.p1.y) return false;
	if (A.p1.x == B.p2.x && A.p1.y == B.p2.y) return false;
	if (A.p2.x == B.p1.x && A.p2.y == B.p1.y) return false;
	if (A.p2.x == B.p2.x && A.p2.y == B.p2.y) return false;

	if (area(A.p1, B.p2, A.p2)*area(A.p1, B.p1, A.p2)<0 && area(B.p1, A.p2, B.p2)*area(B.p1, A.p1, B.p2)<0) return true;
	return false;
}


int dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 }; int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };//Knight Direction
int g[2][24][24];
int n, m;

vector<pair<int,int>> adj[21][21];
bool vis[21][21];

bool rec(int x, int y){
	vis[x][y] = 1;
	if (x == n) return 1;
	for (auto v : adj[x][y]) if (!vis[v.first][v.second]) {
		if (rec(v.first, v.second)) return 1;
	}
	return 0;
}

int main(){
    freopen("uva.txt","rt",stdin);
	while (scanf("%d%d", &n, &m)){
		if (!n && !m) break;
		int x, y;
		memset(g, 0, sizeof(g));
		vector<p> seg;
		vector<pair<int, int>> pseg;
		for (int i = 0; i < 21; i++) for (int j = 0; j < 21; j++) adj[i][j].clear(), vis[i][j] = 0;
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &x, &y);
			g[i % 2][x][y] = 1;
			p cur1 = p(x, y);
			for (int k = 0; k < 8; k++){
				int nx = x + dx[k], ny = y + dy[k];
				if (nx < 0 || ny < 0 || nx >= n+1 || ny >= n+1 || !g[i%2][nx][ny]) continue;
				p cur2 = p(nx, ny);
				bool f = 1;
				for (int j = 0; j < seg.size(); j += 2){
					if (intersection({ cur1, cur2 }, { seg[j], seg[j + 1] })){
						f = 0;
						break;
					}
				}
				if (f){
					seg.push_back(cur1);
					seg.push_back(cur2);
					pseg.push_back({ x, y });
					pseg.push_back({ nx, ny });
					adj[x][y].push_back({ nx, ny });
					adj[nx][ny].push_back({ x, y });
				}
			}
		}
		bool f = 0;
		for (int i = 0; i < n; i++){
			if (rec(0, i)) {
				f = 1; break;
			}
		}
		puts(f ? "yes" : "no");
	}

}
