/*
	we can sort the querires by left, and if equal by right 
	now for each query put it into a[q[i].l]
	so now we have array a[i], that at each index have all queries that have their left == i
	now we start from 0, and keep a set with current querires we need to set
	when we enter index we put all queries starting at that index in the set
	and after that, if set not empty we place the query with smallest right, as it can be seen 
	it's always better to place the query with the smallest right first
*/
#include <bits/stdc++.h>

using namespace std;


#define lp(i, n)         for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)     for(int i=(j);i>=(int)(n);--i)

struct ev{
	int l, r, idx;
	ev(int l = 0, int r = 0, int idx = 0) :l(l), r(r), idx(idx) {}
	bool operator < (ev &a) const {
		if (l != a.l) return l < a.l;
		return r < a.r;
	}
} q[105];

vector<pair<int, int>> a[10000000 + 100];
int ret[1005];

int main(){
	int n; cin >> n;
	int mx = 0;
	lp(i, n) q[i].idx = i;
	lp(i, n) cin >> q[i].l >> q[i].r;
	lp(i, n) mx = max(mx, max(q[i].l, q[i].r));
	sort(q, q + n);
	lp(i, n) a[q[i].l].push_back({ q[i].r, q[i].idx });
	set<pair<int, int>> cr;
	lp(x, mx + 1){
		for (auto i : a[x]) cr.insert(i);
		if (!cr.empty()){
			auto it = cr.begin();
			ret[it->second] = x;
			cr.erase(it);
		}
	}
	lp(i, n) cout << ret[i] << " ";
}