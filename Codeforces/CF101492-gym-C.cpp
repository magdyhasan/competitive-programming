/*
hint: if we knew position of minimum right index to i that's coprime with i, can you solve it ?

hint2: given right[i], we can just build segment tree on it and find minimum one on given range,
can you build right[i]

to build right[i], we can use BS to find nearest coprime number to i
so we need to answer how many numbers on range(a,b) are coprime to a[i]

we can build all sub masks of prime factors of a[i]
and we already store all sub masks of ranges in sorted arrat
now by inclusion exclusion principle
for each subset if size is odd add it,
if size is even subtract it and we have our answer

*/
#include<bits\stdc++.h>
using namespace std;

const int maxn = 300500;

typedef pair<int, int> pii;

vector<int> msk[800500];
vector<pii> prs[maxn];

int pa[800500];
int a[maxn];
int ri[maxn];



int cntNonCoprimes(int s, int e, vector<pii> &sub){
	int cnt = 0;
	for (auto i : sub){
		auto l = upper_bound(msk[i.first].begin(), msk[i.first].end(), s);
		auto r = upper_bound(msk[i.first].begin(), msk[i.first].end(), e);
		if (r - l < 0) continue;
		cnt += (r - l)*((i.second == 0) ? -1 : 1);
	}
	return e - s - cnt;
}


int segT[maxn * 8];
int n;

int query(int x, int y, int idx = 1, int l = 1, int r = n){
	if (r < x || l > y) return (1 << 30);
	if (x <= l && r <= y) return segT[idx];
	int mid = (l + r) / 2, lidx = idx << 1;
	return min(query(x, y, lidx, l, mid), query(x, y, lidx | 1, mid + 1, r));
}

void update(int x, int y, int idx = 1, int l = 1, int r = n){
	if (l == r){
		segT[idx] = y;
		return;
	}
	int mid = (l + r) / 2, lidx = idx << 1;
	if (x <= mid) update(x, y, lidx, l, mid);
	else update(x, y, lidx | 1, mid + 1, r);
	segT[idx] = min(segT[lidx], segT[lidx | 1]);
}

int main(){
	int m, x;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++){
		scanf("%d", a + i);
		x = a[i];
		vector<int> pr;
		for (int j = 2; j*j <= x; j++) if (x%j == 0){
			pr.push_back(j);
			while (x%j == 0) x /= j;
		}
		if (x>1) pr.push_back(x);
		for (int ma = 1; ma < (1 << (pr.size())); ma++){
			int y = 1, c = 0;
			for (int j = 0; j < pr.size(); j++) if (ma&(1 << j))
				y *= pr[j], c++;
			msk[y].push_back(i);
			prs[i].push_back({ y, c % 2 });
		}
	}
	for (int i = 0; i < n; i++){
		int l = i + 1, r = n - 1, ans = n + 1;
		while (l <= r){
			int mid = (l + r) / 2;
			if (cntNonCoprimes(i, mid, prs[i]) > 0) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		ri[i] = ans;
	}
	fill(segT, segT + (maxn * 8), (1 << 30));
	for (int i = 0; i < n; i++)
		update(i + 1, ri[i] + 1);
	while (m--){
		int l, r;
		scanf("%d%d", &l, &r);
		int mr = query(l, r);
		if (mr <= r) puts("S");
		else puts("N");
	}
}