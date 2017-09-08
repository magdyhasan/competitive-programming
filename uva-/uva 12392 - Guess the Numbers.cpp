#include<bits/stdc++.h>
using namespace std;




int a[8];

char ex[10050];
int p[8];
map<char, int> idx;

int rec(string st){
	if (st[0] <= 'z' && st[0] >= 'a') return a[p[idx[st[0]]]];
	int fi = 0, se = 0, j = 0;
	char op;
	if (st[1] <= 'z' && st[1] >= 'a') fi = a[p[idx[st[1]]]], j += 2;
	else {
		int in = 0;
		string cur = "";
		do{
			j++;
			if (st[j] == '(') in++;
			else if (st[j] == ')') in--;
			cur += st[j];
		} while (in > 0 || st[j] != ')');
		j++;
		fi = rec(cur);
	}
	op = st[j];
	if (st[j] <= 'z' && st[j] >= 'a') se = a[p[idx[st[j]]]], j++;
	else {
		int in = 0;
		string cur = "";
		do{
			j++;
			if (st[j] == '(') in++;
			else if (st[j] == ')') in--;
			cur += st[j];
		} while (in > 0 || st[j] != ')');
		j++;
		se = rec(cur);
	}
	if (op == '+') fi = fi + se;
	else if (op == '-') fi = fi - se;
	else fi = fi*se;
	return fi;
}

int main(){
    freopen("uva.txt","rt",stdin);
	int n, m;
	while (scanf("%d", &n)){
		for (int i = 0; i < n; i++) scanf("%d", a + i);
		scanf("%d", &m);
		if (!n && !m) break;
		idx.clear();
		scanf("%s", ex);
		int cnt = 0;
		for (int i = 0; ex[i]; i++) if (ex[i] <= 'z' && ex[i] >= 'a'){
			if (idx.find(ex[i]) == idx.end()) idx[ex[i]] = cnt++;
		}
		for (int i = 0; i < n; i++) p[i] = i;
		bool yes = 0;
		do{
			if (rec(ex) == m) {
				yes = 1; break;
			}
		} while (next_permutation(p, p + n));
		puts(yes ? "YES" : "NO");
	}
}
