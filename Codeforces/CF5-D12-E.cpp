/*
	Let's think about adding pair of numbers as follow:
	let the minimum number of the pair add this pair
	so if there's (3,6) pair, 3 will add this pair

	now because of this point of view about problem, we can now get rid of circular array
	by keeping maximum number in first position of array and last position

	now for each element, we need to find two pairs this element will add
	- first greater element to it's right, and first greater elment to it's left
	this a standard trick by keeping L,R arrays
	now we just have to take care of equal elements
	while building R array, we can count how many equal element will make pairs
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

const int maxn = 1000500;

int ta[maxn], a[maxn];
int L[maxn], R[maxn];
int cnt[maxn];

int main(){
	freopen("uva.txt", "r", stdin);
	int n; sci(n);
	int mxi = 0;
	lp(i, n){
		sci(ta[i]);
		if (ta[i] > ta[mxi]) mxi = i;
	}
	lp(i, n+1) a[i] = ta[(i + mxi) % n];
	for (int i = 1; i <= n; i++) {
		L[i] = i - 1;
		while (L[i] && a[L[i]] <= a[i]) 
			L[i] = L[L[i]];
	}
	R[n] = n;
	for (int i = n - 1; i >= 0; i--){
		R[i] = i + 1;
		while (R[i] < n && a[i] > a[R[i]]) R[i] = R[R[i]];
		if (R[i] < n && a[R[i]] == a[i]) {
			cnt[i] = cnt[R[i]] + 1;
			R[i] = R[R[i]];
		}
	}
	ll ret = 0;
	lp(i, n){
		ret += cnt[i];
		if (a[i] < a[0]){
			ret += 2;
			if (L[i] == 0 && R[i] == n) ret--;
		}
	}
	printf("%lld", ret);
}