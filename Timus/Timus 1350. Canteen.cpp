#include<bits/stdc++.h>
using namespace std;



int main(){
    freopen("uva.txt","rt",stdin);
	int n; cin >> n;
	set<string> ing;
	string st;
	while (n--){
		cin >> st;
		ing.insert(st);
	}
	int k; cin >> k;
	cin >> n;
	while (n--){
		cin >> st;
		ing.erase(st);
	}
	vector<int> f;
	while (k--){
		cin >> n;
		f.push_back(0);
		while (n--){
			cin >> st;
			if (ing.find(st) != ing.end())  f.back()++;
		}
	}
	int m; cin >> m;
	for (int i : f){
		if (i == 0) cout << "YES" << "\n";
		else if (m <= ing.size() - i) cout << "MAYBE" << "\n";
		else cout << "NO" << "\n";
	}
}
