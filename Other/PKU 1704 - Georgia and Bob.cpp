/*
	consider each 2 consective chess's as a pile of size = distance between 2 chess's
	e.g 
	..1.2..
	here we have one pile(di(1-2))
	...1.2..3..4
	here we have 2 piles (di(1-2)),(di(3-4))

	-handle odd n bty adding a 0
	e.g
	0..1..2..3
	here we have 2 piles (di(0-1)),(di(2-3))
*/
#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 10500;

typedef long long ll;


int main(){
	int T; scanf("%d", &T);
	while (T--){
		int n;	 scanf("%d", &n);
		vector<int> v;	 int t;
		for (int i = 0; i < n; i++){
			scanf("%d", &t);
			v.push_back(t);
		}
		v.push_back(0);
		sort(v.begin(), v.end());
		ll xorSum = 0;
		for (int i = n - 1; i >= 0; i -= 2)
			xorSum ^= (v[i + 1] - v[i] - 1);
		puts(xorSum ? "Georgia will win" : "Bob will win");
	}
}