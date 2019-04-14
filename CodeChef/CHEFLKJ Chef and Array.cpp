/*
	a number is dominating if atleast is dominating in one of it's halfs

	so we can build segment tree and store domainting number in each segment and keep
	number of occurance of each number

	now we can answer quereies easily and update is trivial with segment tree
*/
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

#define all(v)           ((v).begin()), ((v).end())
#define sz size()
#define clr(v,d)         memset(v,d,sizeof(v))
#define lp(i, n)         for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define sci(a)	scanf("%d",&a)
#define scii(a, b)	scanf("%d%d",&a, &b)


const int maxn = 300500;


int a[maxn];


struct nd{
	unordered_map<int, int> cc;
	int dom;
} segT[maxn*4];

void build(int idx = 1, int l = 0, int r = maxn - 1){
	if (l == r){
		segT[idx].cc.clear();
		segT[idx].cc[a[l]] = 1;
		segT[idx].dom = a[l];
		return;
	}
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	build(lidx, l, mid);
	build(ridx, mid + 1, r);
	
	segT[idx].cc.clear();
	for (auto i : segT[lidx].cc) segT[idx].cc[i.first] += i.second;
	for (auto i : segT[ridx].cc) segT[idx].cc[i.first] += i.second;

	int ln = (r - l + 1);
	if (segT[idx].cc[segT[lidx].dom] > (ln / 2))
		segT[idx].dom = segT[lidx].dom;
	else if (segT[idx].cc[segT[ridx].dom] > (ln / 2))
		segT[idx].dom = segT[ridx].dom;
	else 
		segT[idx].dom = -1;
	return;
}

vector<int> qrs;
int oy;

void update(int x,int y, int idx = 1, int l = 0, int r = maxn - 1){
	if (x > r || x < l) return;
	if (l == r){
		segT[idx].cc.clear();
		a[l] = y;
		segT[idx].cc[a[l]] = 1;
		segT[idx].dom = a[l];
		return;
	}
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	update(x, y, lidx, l, mid);
	update(x, y, ridx, mid + 1, r);
	int ln = (r - l + 1);

	segT[idx].cc[oy] -= 1;
	segT[idx].cc[y] += 1;

	if (segT[idx].cc[segT[lidx].dom] > (ln / 2))
		segT[idx].dom = segT[lidx].dom;
	else if (segT[idx].cc[segT[ridx].dom] > (ln / 2))
		segT[idx].dom = segT[ridx].dom;
	else
		segT[idx].dom = -1;
	return;
}

void querySeg(int x, int y, int idx = 1, int l = 0, int r = maxn - 1){
	if (x > r || y < l) return;
	if (x <= l && y >= r) {
		qrs.push_back(idx);
		return;
	}
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	querySeg(x, y, lidx, l, mid);
	querySeg(x, y, ridx, mid + 1, r);
}

void solve(){
	int l, r; scii(l, r);
	--l;
	--r;
	int ln = (r - l + 1);
	qrs.clear();
	querySeg(l, r);
	for (int i : qrs) {
		int cn = 0;
		for (int j : qrs){
			cn += segT[j].cc[segT[i].dom];
		}
		if (cn > ln / 2){
			puts("Yes");
			return;
		}
	}
	puts("No");
}


int main(){
	freopen("uva.txt", "r", stdin);
	int n, q; scii(n, q);
	lp(i, n) sci(a[i]);

	build();
	while (q--){
		int ty; sci(ty);
		if (ty == 1){
			int x, y; scii(x, y);
			--x;
			oy = a[x];
			update(x, y);
		}
		else
			solve();
	}
}