/*
just generate all number in the given range and store them in map
so we can answer all questions
*/
#include<bits/stdc++.h>
using namespace std;


map<int, string> tob;
map<string, int> tod;
int p2[32];


int main(){
	//freopen("test.txt","rt",stdin);
	p2[0] = 1;
	for (int i = 1; i < 30; i++) p2[i] = p2[i - 1] * 2;
	for (int msk = 0; msk < (1 << 20); msk++){
		string st = "";
		bool f = 0;
		int nu = 0;
		for (int j = 19; j >= 0; j--){
			if ((msk&(1 << j))) f = 1;
			if (f) st += (msk&(1 << j)) ? '1' : '0';
			int p = p2[j];
			if (j & 1) p *= -1;
			nu += p*((msk&(1 << j)) > 0);
		}
		if (st.empty()) st = "0";
		tob[nu] = st;
		tod[st] = nu;
	}
	int q; cin >> q;
	string st;
	while (q--){
		cin >> st;
		if (st[0] == 'b') {
			cin >> st;
			int i = 0;
			while (i + 1 < st.size() && st[i] == '0') i++;
			string s;
			while (i < st.size()){
				s.push_back(st[i]);
				i++;
			}
			cout << "From binary: " << st << " is " << tod[s] << "\n";
		}
		else{
			int d;
			cin >> d;
			cout << "From decimal: " << d << " is " << tob[d] << "\n";
		}
	}
}
