#include<bits/stdc++.h>
using namespace std;

/*
	count number of inversions.
	if this number is odd "Marcelo" win, otherwise "Carlos" win
*/

typedef long long ll;

ll cnt(int *a, int l, int r, int nleft){
	int *c = new int[r - l + 2];
	ll i = l, j = nleft, k = 0, ret = 0;
	while (i < nleft && j < r){
		if (a[i] < a[j])
			c[k++] = a[i++];
		else{
			ret += nleft - i;
			c[k++] = a[j++];
		}
	}
	while (i < nleft)
		c[k++] = a[i++];
	while (j < r)
		c[k++] = a[j++];
	for (int p = l; p<r; p++)
		a[p] = c[p - l];
	return ret;
}


ll merge_sort(int *a, int l, int r){
	if (r - l < 2)
		return 0;
	ll ret = 0;
	ret += merge_sort(a, l, (r + l) / 2);
	ret += merge_sort(a, (r + l) / 2, r);
	ret += cnt(a, l, r, (r + l) / 2);
	return ret;
}


const int maxn = 300500;

int a[maxn];

int main(){
    freopen("uva.txt","rt",stdin);
	int n; 
	while (scanf("%d", &n)){
		if (!n) break;
		for (int i = 0; i < n; i++) scanf("%d", a + i);
		ll ret = merge_sort(a, 0, n);
		puts((ret & 1) ? "Marcelo" : "Carlos");
	}
}
