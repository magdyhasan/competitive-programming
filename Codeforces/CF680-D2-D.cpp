/*
	let's denoate a as largest cube such that a^3 <= m
	now we can see it's always remeber to first use a or a-1 as first cube
	and have subproblem with remider of m-a^3 in first case
	and reminder of a^3-1-(a-1)^3 in second case

	now this can solved using recurison easily

	and because we are subtracting largest power of 3 each time, we will reach base case so fast
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


const int maxn = 1000500;

typedef pair<ll, ll> pll;
vector<ll> p3;

pll rec(ll m){
	if (m == 0) return{ 0, 0 };
	int idx = upper_bound(p3.begin(), p3.end(), m) - p3.begin() - 1;
	pll ret = rec(m - p3[idx]);
	ret.first += 1; ret.second += p3[idx];
	if (idx > 0){
		pll ret2 = rec(p3[idx] - 1 - p3[idx - 1]);
		ret2.first += 1; ret2.second += p3[idx - 1];
		return max(ret, ret2);
	}
	else
		return ret;
}


int main(){
	ios::sync_with_stdio(0);
	for (ll i = 1; i*i*i < 1e17; i++) p3.push_back(i*i*i);	
	ll m; cin >> m;
	pll ret = rec(m);
	cout << ret.first << " " << ret.second;
}