/*
we can easily simulate the process using segment tree standard operation

for answering qeries, it's also sandard stack given we already now the list
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
#define scll(a)	scanf("%lld",&a)
#define pri(a)	printf("%d\n",a)
#define prll(a)	printf("%lld\n",a)

const int maxn = 2000005;

const int MOD = 1e9 + 7;
typedef pair<int, int> pii;


int seg[maxn * 4];


void ad(int v, int idx = 1, int l = 0, int r = maxn - 1){
	if (l == r) {
		seg[idx] = 1;
		return;
	}
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	if (v <= mid) ad(v, lidx, l, mid);
	else ad(v, ridx, mid + 1, r);
	seg[idx] = seg[lidx] + seg[ridx];
}


int getKth(int kth, int idx = 1, int l = 0, int r = maxn - 1){
	if (l == r) return l;
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	if (seg[lidx] >= kth) return getKth(kth, lidx, l, mid);
	return getKth(kth - seg[lidx], ridx, mid + 1, r);
}

void delKth(int kth, int idx = 1, int l = 0, int r = maxn - 1){
	if (l == r) {
		seg[idx] = 0;
		return;
	}
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	if (seg[lidx] >= kth) delKth(kth, lidx, l, mid);
	else delKth(kth - seg[lidx], ridx, mid + 1, r);
	seg[idx] = seg[lidx] + seg[ridx];
}

bool lu[maxn];

int main(){
	//freopen("uva.txt", "r", stdin);
	clr(lu, 0);
	int ha = 1000000;
	for (int i = 1; i <= ha * 2; i += 2) ad(i);
	lu[1] = 1;
	for (int s = 2; s <= ha; s++){
		int nxt = 1, rem = 0, term = getKth(s);
		lu[term] = 1;
		while (term*nxt - rem <= ha){
			delKth(term*nxt - rem);
			++rem, ++nxt, --ha;
		}
	}
	int n;
	while (sci(n) == 1){
		bool f = 0;
		if (n % 2 == 0){
			for (int k = n / 2; k > 0; k--){
				if (lu[k] && lu[n - k]){
					printf("%d is the sum of %d and %d.\n", n, k, n - k);
					f = 1;
					break;
				}
			}
		}
		if (!f) printf("%d is not the sum of two luckies!\n", n);
	}
}