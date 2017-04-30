#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

vector<char> to;

char st[10000];
set<char> no[1000], ye[1000];

int n = 0;
vector<char > cur;
bool f;

void rec(int idx){
	if (f)  return;
	if (idx == to.size()){
		for (int i = 0; i < n; i++){
			bool ok = 0;
			for (char ch : ye[i]) if (find(cur.begin(), cur.end(), ch) != cur.end()) ok = 1;
			for (char ch : no[i]) if (find(cur.begin(), cur.end(), ch) == cur.end()) ok = 1;
			if (!ok) return;
		}
		f = 1;
		return;
	}
	cur.push_back(to[idx]);
	rec(idx + 1);
	if (!f){
		cur.pop_back();
		rec(idx + 1);
	}
}

int main(){
    freopen("uva.txt","rt",stdin);
	for (char c = 'A'; c <= 'P'; c++) to.push_back(c);
	while (true){
		n = 0;
		for (int i = 0; i < 1000; i++) no[i].clear(), ye[i].clear();
		to.clear();
		set<char> un;
		while (scanf("%s", st) != EOF){
			int ln = strlen(st);
			if (st[0] == '.') break;
			for (int i = 0; i+1 < ln; i += 2) {
				if (st[i] == '+'){
					ye[n].insert(st[i + 1]);
				}
				else{
					no[n].insert(st[i + 1]);
				}
				un.insert(st[i + 1]);
			}
			n++;
		}
		if (n == 0) break;
		to.assign(un.begin(), un.end());
		f = 0;
		cur.clear();
		rec(0);
		if (f){
			printf("Toppings: ");
			for (char c : cur) putchar(c);
			puts("");
		}
		else
			puts("No pizza can satisfy these requests.");
	}
}

