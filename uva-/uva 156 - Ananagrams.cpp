#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

const int maxn = 10500;

typedef long long ll;

vector<string> words;
set<string> ret, re;
map<string, string> orig;

int main(){
	string st;
	while (cin >> st){
		if (st == "#") break;
		string st2 = st;
		for (char &ch : st) ch |= 32;
		sort(st.begin(), st.end());
		orig[st] = st2;
		words.push_back(st);

	}
	for (int i = 0; i < words.size(); i++) {
		bool f = false;
		for (int j = 0; j < words.size(); j++)if (i != j && words[i] == words[j])  f = true;
		if (f) continue;
		ret.insert(words[i]);
	}
	for (string st : ret) re.insert(orig[st]);
	for (string st : re) puts(st.c_str());
}

