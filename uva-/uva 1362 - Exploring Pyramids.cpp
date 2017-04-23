#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string cur;
char st[10000];
string pa;
int n, nways;

void rec(int lvl,char p, int idx){
	if (lvl == 0 && cur.size() == n){
		if (cur == pa) nways++;
		return;
	}
	cur += st[idx];
	if (p != '#' && st[idx + 1] == p){
		rec(lvl-1,)
	}
}

int main(){
    freopen("uva.txt","rt",stdin);
	while (scanf("%s", st) != EOF){
		nways = 0;
		n = strlen(st);
		pa = st;
		rec(0);
		printf("%d\n", nways);
	}
}

