#include<bits/stdc++.h>
using namespace std;



char li[300500];

double readD(string st){
	int j = 0;
	if (st[0] == '-') j++;
	return ((st[j] - '0')*1. + (st[j + 2] - '0')*.1 + (st[j + 3] - '0')*.01)*((j == 1) ? -1. : 1.);
}


double rec(string st){
	if (isdigit(st[0]) || st[0] == '-') return readD(st);
	double l, r;
	char op;
	int j;
	if (isdigit(st[2]) || st[2] == '-') l = readD(st.substr(2)), j = 7;
	else{
		int in = 0;
		string le = "";
		j = 2;
		while (true) {
			if (st[j] == ')') in--;
			if (st[j] == '(') in++;
			le += st[j];
			j++;
			if (in == 0) break;
		}
		j++;
		l = rec(le);
	}
	op = st[j];
	j += 2;
	if (isdigit(st[j]) || st[j] == '-') r = readD(st.substr(j));
	else{
		int in = 0;
		string re = "";
		while (true) {
			if (st[j] == ')') in--;
			if (st[j] == '(') in++;
			re += st[j];
			j++;
			if (in == 0) break;
		}
		j++;
		r = rec(re);
	}
	double ret;
	if (op == '+') ret = l + r;
	if (op == '-') ret = l - r;
	if (op == '*') ret = l * r;
	if (op == '/') ret = l / r;
	return ret;
}


int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	gets(li);
	while (T--){
		gets(li);
		printf("%.2lf\n", round(rec(li)*100.) / 100.);
	}
}
