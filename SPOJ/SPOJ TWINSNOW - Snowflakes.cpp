#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;

set<vector<int>> s;

int main(){
	freopen("uva.txt", "r", stdin);
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++){
		vector<int> a(6);
		for (int j = 0; j < 6; j++) scanf("%d", &a[j]);;
		sort(a.begin(), a.end());
		if (s.find(a) != s.end()){
			puts("Twin snowflakes found.");
			return 0;
		}
		s.insert(a);
	}
	puts("No two snowflakes are alike.");
}
