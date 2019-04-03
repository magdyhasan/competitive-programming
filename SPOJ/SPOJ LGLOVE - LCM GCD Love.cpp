/*
	main idea is that:
	lcm query of range i,j will just be lcm 1..n where n is maximum number in this range
	gcd query of range i,j will just be lcm 1..n where n is minimum number in this range

	so problem is just to find minimum and maximum in range, standard task with lazy segment tree

	also we need to find lcm of 1..n with mod
	to do that we get lcm from prime factors of numbers

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


struct node{
	int mx, mi;
}segT[maxn * 4];

int n;
int lazy[maxn * 4];
int a[maxn];

void push(int idx, int l, int r){
	if (lazy[idx]){
		segT[idx].mx += lazy[idx];
		segT[idx].mi += lazy[idx];
		if (l != r){
			lazy[idx << 1] += lazy[idx];
			lazy[(idx << 1) | 1] += lazy[idx];
		}
		lazy[idx] = 0;
	}
}

void updateSeg(int x, int y, int v, int idx = 1, int l = 0, int r = n - 1){
	push(idx, l, r);
	if (x > r || y < l) return;
	if (x <= l && y >= r){
		lazy[idx] += v;
		push(idx, l, r);
		return;
	}
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	updateSeg(x, y, v, lidx, l, mid);
	updateSeg(x, y, v, ridx, mid + 1, r);
	segT[idx].mi = min(segT[lidx].mi, segT[ridx].mi);
	segT[idx].mx = max(segT[lidx].mx, segT[ridx].mx);
}

node querySeg(int x, int y, int idx = 1, int l = 0, int r = n - 1){
	if (x > r || y < l) return{ -MOD, MOD };
	push(idx, l, r);
	if (x <= l && y >= r) return segT[idx];
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	node ql = querySeg(x, y, lidx, l, mid), qr = querySeg(x, y, ridx, mid + 1, r);
	return{ max(ql.mx, qr.mx), min(ql.mi, qr.mi) };
}

void build(int idx = 1, int l = 0, int r = n - 1){
	if (l == r){
		segT[idx].mx = segT[idx].mi = a[l];
		return;
	}
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	build(lidx, l, mid);
	build(ridx, mid + 1, r);
	segT[idx].mi = min(segT[lidx].mi, segT[ridx].mi);
	segT[idx].mx = max(segT[lidx].mx, segT[ridx].mx);
}

ll lc[maxn];

inline ll gcd(ll a, ll b){
	if (b == 0) return a;
	return gcd(b, a%b);
}

inline ll lcm(ll a, ll b){
	return a*b / gcd(a, b);
}


int pr[maxn], prCnt;
bool notPr[maxn];
int cnPr[maxn];

long long pow_mod(long long base, long long power){
	long long res = 1;
	while (power){
		if (power & 1)res = res * base % MOD;
		base = base * base % MOD;
		power >>= 1;
	}
	return res;
}

void init(){
	for (int i = 2; i < maxn; i++) if (!notPr[i]){
		pr[prCnt++] = i;
		for (ll j = i * 1LL * i; j < maxn; j += i)
			notPr[j] = 1;
	}
	int cn;
	lc[1] = 1;
	ll nu = 1;
	lpi(i, 2, 300005){// lcm of 1..i, using old inf. from previous lcm
		int ni = i;
		for (int j = 0; j < prCnt; j++){
			if (pr[j] * pr[j] > ni) break;
			if (ni % pr[j] == 0){
				cn = 0;
				while (ni%pr[j] == 0){
					++cn;
					ni /= pr[j];
				}
				if (cn > cnPr[pr[j]]){
					nu = (pow_mod(pr[j], cn - cnPr[pr[j]]) * nu) % MOD;
					cnPr[pr[j]] = cn;
				}
			}
		}
		if (ni > 1 && cnPr[ni] == 0){
			nu = (ni * nu) % MOD;
			cnPr[ni] = 1;
		}
		lc[i] = nu;
	}
}

int main(){
	freopen("uva.txt", "r", stdin);
	int m; scii(n, m);
	init();
	lp(i, n){
		sci(a[i]);
		updateSeg(i, i, a[i]);
	}
	int qr, i, j, v;
	while (m--)
	{
		sci(qr); scii(i, j);
		if (qr == 0){
			sci(v);
			updateSeg(i, j, v);
		}
		else if (qr == 1){
			int t = querySeg(i, j).mx;
			prll(lc[querySeg(i, j).mx] % MOD);
		}
		else{
			prll(lc[querySeg(i, j).mi] % MOD);
		}
	}
}