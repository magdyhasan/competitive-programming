#include<bits/stdc++.h>
using namespace std;


inline int gcd(int a, int b){
	if (a < b) swap(a, b);
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

const int m = 2005;

int st[3 * m][3 * m];


int qy(int vx, int vy, int tly, int try_, int ly, int ry) {
	if (ly > ry)
		return 0;
	if (ly == tly && try_ == ry)
		return st[vx][vy];
	int tmy = (tly + try_) / 2;
	return gcd(qy(vx, vy * 2, tly, tmy, ly, min(ry, tmy))
		, qy(vx, vy * 2 + 1, tmy + 1, try_, max(ly, tmy + 1), ry));
}

int qx(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
	if (lx > rx)
		return 0;
	if (lx == tlx && trx == rx)
		return qy(vx, 1, 0, m - 1, ly, ry);
	int tmx = (tlx + trx) / 2;
	return gcd(qx(vx * 2, tlx, tmx, lx, min(rx, tmx), ly, ry)
		, qx(vx * 2 + 1, tmx + 1, trx, max(lx, tmx + 1), rx, ly, ry));
}


void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int new_val) {
	if (ly == ry) {
		if (lx == rx)
			st[vx][vy] = new_val;
		else
			st[vx][vy] = gcd(st[vx * 2][vy], st[vx * 2 + 1][vy]);
	}
	else {
		int my = (ly + ry) / 2;
		if (y <= my)
			update_y(vx, lx, rx, vy * 2, ly, my, x, y, new_val);
		else
			update_y(vx, lx, rx, vy * 2 + 1, my + 1, ry, x, y, new_val);
		st[vx][vy] = gcd(st[vx][vy * 2], st[vx][vy * 2 + 1]);
	}
}

void update_x(int vx, int lx, int rx, int x, int y, int new_val) {
	if (lx != rx) {
		int mx = (lx + rx) / 2;
		if (x <= mx)
			update_x(vx * 2, lx, mx, x, y, new_val);
		else
			update_x(vx * 2 + 1, mx + 1, rx, x, y, new_val);
	}
	update_y(vx, lx, rx, 1, 0, m - 1, x, y, new_val);
}

int main(){
	ios::sync_with_stdio(0);
	int q; cin >> q;
	set<pair<int, int>> x, y;
	string tp;
	int tx, ty, td;
	while (q--){
		cin >> tp >> tx >> ty >> td;
		tx += 550;
		ty += 550;
		int xx = tx + ty, yy = tx - ty;
		if (tp[0] == 'S'){
			/*if (xx >= yy) x.insert({ xx, td });
			else y.insert({ yy, td });*/
			update_x(1, 1, m - 1, xx, yy, td);
		}
		else{

			/*for (auto ix : x){
			if (xx - td <= ix.first && xx + td >= ix.first)
			take(gc, ix.second);
			}*/
			/*for (auto iy : y){
			if (yy - td <= iy.first && yy + td >= iy.first)
			take(gc, iy.second);
			}
			if (gc == -1) gc = 0;*/
			cout << qx(1, 1, m - 1, max(0, xx - td), min(xx + td, m - 1), max(0, yy - td), min(yy + td, m - 1)) << "\n";
		}
	}
}