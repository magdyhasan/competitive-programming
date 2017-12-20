#include <bits/stdc++.h>
using namespace std;

int f[30500];

int josephus(int n)
{
	// Find value of 2 ^ (1 + floor(Log n))
	// which is a power of 2 whose value
	// is just above n.
	int p = 1;
	while (p <= n)
		p *= 2;

	// Return 2n - 2^(1+floor(Logn)) + 1
	return (2*n) - p + 1;
}


int main(){
	freopen("test.txt", "r", stdin);
	for (int i = 1; i < 30500; i++)
		f[i] = josephus(i);
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int n; cin >> n;
		int cnt = 0;
		while (f[n] != n) cnt++, n = f[n];
		cout << "Case " << tc << ": " <<  cnt << " " << n << "\n";
	}
}