#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<sstream>
using namespace std;



double rec(string st){
	double t;
	if (st[0] != '(') {
		istringstream(st) >> t;
		return t;
	}
	int i = 1;
	string tt, b, c;
	for (;; i++) 
		if (st[i] == ',') break;
		else tt += st[i];
	i++;
	istringstream(tt) >> t;
	int in = -1;
	if (st[i] == '('){
		while (st[i] != ')' || in) {
			in += st[i] == '(';
			in -= st[i] == ')';
			b += st[i];
			i++;
		}
		b += st[i];
		i += 2;
	}
	else{
		while (st[i] != ',') b += st[i++];
		i++;
	}
	c = st.substr(i);
	return t*(rec(b) + rec(c)) + (1. - t)*(rec(b) - rec(c));
}

int main(){
    freopen("uva.txt","rt",stdin);
	string li;
	while (getline(cin, li)){
		if (li[0] == '(' && li[1] == ')') break;
		for (int i = 0; i < li.size(); i++) if (li[i] == ' ') li[i] = ',';
		printf("%.2lf\n", rec(li));
	}
}
