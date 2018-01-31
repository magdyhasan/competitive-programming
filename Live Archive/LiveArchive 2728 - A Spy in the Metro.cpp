/*
	since number of stations <= 50 and time of meeting <= 200
	use dp of current station and curent time 

	in each state we can wait for one second
	or we can see upcoming trains in this station and take them to all possible stations
*/
#include<bits/stdc++.h>
using namespace std;

int n, T;
int m1, m2;
int d[64], e[64], t[64];
vector<int> st[64], rst[64];

int dp[52][205];

int rec(int si, int ti){
	if (ti >= T){
		if (si != n - 1 || ti > T) return 123456789;
		return 0;
	}
	int &ret = dp[si][ti];
	if (ret != -1) return ret;
	ret = rec(si, ti + 1) + 1;
	for (int i : st[si]) if (i >= ti){
		int cur = i;
		for (int j = si + 1; j < n; j++){
			cur += t[j - 1];
			ret = min(ret, rec(j, cur) + i - ti);
		}
	}
	for (int i : rst[si]) if (i >= ti){
		int cur = i;
		for (int j = si - 1; j >= 0; j--){
			cur += t[j];
			ret = min(ret, rec(j, cur) + i - ti);
		}
	}
	return ret;
}


int main(){
    freopen("uva.txt","rt",stdin);
	int tc = 0;
	while (scanf("%d", &n) && n){
		scanf("%d", &T);
		for (int i = 0; i+1 < n; i++) scanf("%d", t + i);
		scanf("%d", &m1);
		for (int i = 0; i < m1; i++) scanf("%d", d + i);
		scanf("%d", &m2);
		for (int i = 0; i < m2; i++) scanf("%d", e + i);
		for (int i = 0; i < 64; i++) st[i].clear(), rst[i].clear();
		for (int i = 0; i < m1; i++){
			int cur = d[i];
			for (int j = 0; j < n; j++){
				st[j].push_back(cur);
				if (j + 1 < n)	cur += t[j];
			}
		}
		for (int i = 0; i < m2; i++){
			int cur = e[i];
			for (int j = n - 1; j >= 0;j--){
				rst[j].push_back(cur);
				if (j > 0) cur += t[j - 1];
			}
		}
		memset(dp, -1, sizeof(dp));
		int ret = rec(0, 0);
		if (ret >= 123456789) printf("Case Number %d: impossible\n", ++tc);
		else printf("Case Number %d: %d\n", ++tc, ret);
	}
}
