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

char seq[maxn];
int idx;


string build(){
	vector<string> ret;
	while (seq[idx] == '0') idx++, ret.push_back(build());
	sort(ret.begin(), ret.end());
	string sret = "(";
	for (string st : ret) sret += st;
	sret += ")";
	idx++;
	return sret;
}


int main(){
	int T; scanf("%d", &T);
	while (T--){
		scanf("%s", seq);
		idx = 0;
		string s1 = build();
		scanf("%s", seq);
		idx = 0;
		string s2 = build();
		puts(s1 == s2 ? "same" : "different");
	}

}

