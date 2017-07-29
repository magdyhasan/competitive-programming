#include<bits/stdc++.h>
using namespace std;

string rec(string st){
	if (st.size() < 2) return st;
	int ln = st.size() - 1;
	return rec(st.substr(1, ln / 2)) + st[0] + rec(st.substr(ln / 2 + 1));
}


int main(){
    freopen("uva.txt","rt",stdin);
	string st;
	getline(cin, st);
	cout << rec(st);
}

