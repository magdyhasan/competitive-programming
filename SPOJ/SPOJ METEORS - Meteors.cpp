/*
	easy idea is to run BS for each member but this will TLE because in each BS iteration
	we need to update all k range upadtes

	we can notice we will do same BS iteration for same mid value multiple times
	so we can use idea of parallel BS to speed it up
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define all(v)           ((v).begin()), ((v).end())
#define sz size()
#define clr(v,d)         memset(v,d,sizeof(v))
#define lp(i, n)         for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define sci(a)	scanf("%d",&a)
#define scii(a, b)	scanf("%d%d",&a, &b)
#define pri(a)	printf("%d\n",a)

const int maxn = 300500;

vector<int> own[maxn];
ll a[maxn];

struct quer{
	int l, r;
	ll a;
} qs[maxn];

int l[maxn], r[maxn];

ll bit[maxn * 2];

void update(int idx, ll val){
	for (int x = idx; x < maxn; x = (x | (x + 1)))
		bit[x] += val;
}

ll query(int idx){
	ll ret = 0;
	for (int x = idx; x >= 0; x = ((x&(x + 1)) - 1))
		ret += bit[x];
	return ret;
}

void updateR(int i){
	if (qs[i].l <= qs[i].r){
		update(qs[i].l, qs[i].a);
		update(qs[i].r + 1, -qs[i].a);
	}
	else{
		update(1, qs[i].a);
		update(qs[i].r + 1, -qs[i].a);
		update(qs[i].l, qs[i].a);
	}
}

vector<int> ch[maxn];



int main(){
	int n, m, x;
	scii(n, m);
	lp(i, m) {
		sci(x);
		own[x].push_back(i + 1);
	}
	lpi(i, 1, n + 1)
		scanf("%lld", a + i);
	int k; sci(k);
	lpi(i, 1, k + 1){
		scii(qs[i].l, qs[i].r);
		scanf("%lld", &qs[i].a);
	}
	lpi(i, 1, n + 1){
		l[i] = 1;
		r[i] = k + 1;
	}
	bool f = 1;
	while (f){
		f = 0;
		memset(bit, 0, sizeof bit);
		lp(i, k + 10) ch[i].clear();
		lpi(i, 1, n + 1) {
			if (l[i] != r[i]){
				f = 1;
				ch[(l[i] + r[i]) / 2].push_back(i);
			}
		}
		lpi(i, 1, k + 1){
			updateR(i);
			for (int j : ch[i]){
				ll su = 0;
				for (auto kk : own[j]){
					su += query(kk);
					if (su >= a[j]) break;
				}
				if (su >= a[j]) r[j] = i;
				else l[j] = i + 1;
			}
		}
	}
	lpi(i, 1, n + 1) {
		if (l[i] > k) puts("NIE");
		else printf("%d\n", l[i]);
	}
}
