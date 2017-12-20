#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

const int maxn = 200500;

char s1[maxn], s2[maxn];

string f(string s){
	if (s.size() % 2) return s;
	string f1 = f(s.substr(0, s.size() / 2));
	string f2 = f(s.substr(s.size() / 2));
	return ((f1 < f2) ? f1 + f2:f2 + f1);
}

int main(){
	freopen("uva.txt", "r", stdin);
	scanf("%s%s", s1, s2);
	puts(f(s1) == f(s2) ? "YES" : "NO");
}