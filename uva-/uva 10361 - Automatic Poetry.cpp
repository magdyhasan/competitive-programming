#include<bits/stdc++.h>
using namespace std;



char st1[1000500], st2[1000500];

vector<string> s;


void builds(){
	string t;
	int i = 0;
	while (st1[i] != '<')  t += st1[i], i++;	i++;
	s.push_back(t); t = "";
	while (st1[i] != '>') t += st1[i], i++; i++;
	s.push_back(t); t = "";
	while (st1[i] != '<')  t += st1[i], i++;	i++;
	s.push_back(t); t = "";
	while (st1[i] != '>') t += st1[i], i++; i++;
	s.push_back(t); t = "";
	while (st1[i]) t += st1[i], i++;
	s.push_back(t);
}


int main(){
	freopen("test.txt", "r", stdin);
	int n; scanf("%d", &n);
	gets(st1);
	for (int li = 0; li < n; li++){
		gets(st1);
		gets(st2);
		s.clear();
		builds();
		int i = 0;
		string l2 = "";
		while (!(st2[i] == '.' && st2[i + 1] == '.' &&st2[i + 2] == '.')) l2 += st2[i], i++;
		for (i = 0; i < 5; i++) printf("%s", s[i].c_str()); puts("");
		printf("%s", l2.c_str());
		printf("%s%s%s%s", s[3].c_str(), s[2].c_str(), s[1].c_str(), s[4].c_str()); puts("");
	}
}