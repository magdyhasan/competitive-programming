/*
	if it's square:
		we only need to check for traingle and others traingles are symmetric
	else
		we check one quadrants and others are symmetric	
*/
#include<bits/stdc++.h>
using namespace std;


int main(){
	int tc; cin >> tc;
	while (tc--){
		int n, m;
		cin >> n >> m;
		if (n == m){
			int x = ceil(n / 2.);
			cout << (x*(x + 1)) / 2 << "\n";
		}
		else
			cout << (int)(ceil(n / 2.)*ceil(m / 2.)) << "\n";
	}
}
