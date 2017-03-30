#include<bits/stdc++.h>
using namespace std;


map<int, int> cnt;

bool cmp(pair<int, int> a, pair<int, int> b){
	if (a.first != b.first) return a.first < b.first;
	return a.second > b.second;
}

int main(){
	freopen("uva.txt", "r", stdin);
	char st[100005];
	bool f = false;
	while (gets(st)){
		if (f)	puts("");
		f = true;
		cnt.clear();
		for (int i = 0; st[i]; i++)  cnt[st[i]]++;
		vector<pair<int, int>> ret;
		for (auto i : cnt) ret.push_back({ i.second, i.first });
		sort(ret.begin(), ret.end(), cmp);
		for (auto i : ret) printf("%d %d\n", i.second, i.first);
	}
}