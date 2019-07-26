/*
 * we need n < 13 so we can pass 3^n solution
 * so we can use meet-in-middle
 * divide array into two halfs and solve and combine with map
 */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 600500;
typedef long long ll;

ll a[maxn];
ll f[maxn];
unordered_map<ll,int> dp[32];
ll s;
ll ret;

int e, kk;

void rec1(int i, int k, ll v){
	if(i>=e){
		++dp[kk-k][v];
		return;
	}
	rec1(i+1,k,v);
	if(v+a[i]<=s) rec1(i+1,k,v+a[i]);
	if(k && a[i]<20&&v+f[a[i]]<=s) rec1(i+1,k-1,v+f[a[i]]);
}

void rec2(int i,int k, ll v){
	if(i>=e){
		while(k>=0){
			ret += dp[k][s-v];
			--k;
		}
		return;
	}
	rec2(i+1,k,v);
	if(v+a[i]<=s) rec2(i+1,k,v+a[i]);
	if(k&&a[i]<20&&v+f[a[i]]<=s) rec2(i+1,k-1,v+f[a[i]]);
}


int main() {
	int n,k;
	cin >> n >> k >> s;
	kk = k;
	for(int i=0;i<n;i++) cin >> a[i];
	f[0] = f[1] = 1;
	for(int i=2;i<100;i++) f[i] = f[i-1]*1LL*i;
	for(int j=0;j<32;j++) dp[j].clear();
	e = n/2;
	rec1(0,k,0);
	//for(auto i:dp) cout << i.first << " " << i.second << '\n';
	e = n;
	rec2(n/2,k,0);
	cout << ret;
}
