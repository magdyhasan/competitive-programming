/*
A[i] must be multiple of all elements of row i, so A[i] is lcm(row(i))
B[j] must be multiple of all elements of column j, so B[j] is lcm(col(j))
After making these arrays, check conditions of the problem

*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a[305][305];

ll A[305], B[305];

inline ll gcd(ll a, ll b){
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

inline ll lcm(ll a, ll b){
	return a*b / gcd(a, b);
}

int main(){
	freopen("test.txt", "rt", stdin);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> a[i][j];
		ll l = a[i][0];
		for (int j = 1; j < m; j++)l = lcm(l, a[i][j]);
		A[i] = l;
	}
	for (int j = 0; j < m; j++){
		ll l = a[0][j];
		for (int i = 1; i < n; i++)
			l = lcm(l, a[i][j]);
		B[j] = l;
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++){
		if (A[i] > 1e9 or B[j] > 1e9 || gcd(A[i], B[j]) != a[i][j]){
			cout << -1; return 0;
		}
	}
	cout << A[0];
	for (int i = 1; i < n; i++) printf(" %d", A[i]);
	cout << "\n" << B[0];
	for (int i = 1; i < m; i++) printf(" %d", B[i]);
}
