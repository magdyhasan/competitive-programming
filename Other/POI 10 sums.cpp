/*
	repesnt sum as:
	s = y + k*xi // for some k >= 0 and for any xi
	now take both side % xi
	s % xi = y % xi

	so now task is to find how we can obtain y%xi from the given sums
	notice that we only care about the minimum way to obtain y%xi
	since we can always increase it be keeping adding xi

	to find smallest sum that give y%xi we can use dijkstra on the numbers 0,1,..xi-1

	now for a given query x
	if x >= d[x%xi] then we can always obtain x by keeping assing up xi
	else we can't get x because smallest sum we can get is alreay bigger than x
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 300500;

int a[maxn];
ll d[maxn];

typedef pair<ll, int> pll;
int n;

void dijkstra(){
	for (int i = 0; i <= a[0]; i++)
		d[i] = 1e18;
	d[0] = 0;
	priority_queue<pll, vector<pll>, greater<pll>> pq;
	pq.push({ 0, 0 });
	while (!pq.empty()){
		pll u = pq.top(); pq.pop();
		if (d[u.second] < u.first) continue;
		for (int i = 0; i < n; i++){
			int v = (u.second + a[i]) % a[0];
			ll nc = u.first + a[i];
			if (d[v] > nc){
				d[v] = nc;
				pq.push({ nc , v });
			}
		}
	}
}


int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	dijkstra();
	int k;
	scanf("%d", &k);
	while (k--){
		int x; scanf("%d", &x);
		if (x >= d[x%a[0]]) puts("TAK");
		else puts("NIE");
	}
}