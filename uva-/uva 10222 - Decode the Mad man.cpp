#include<bits/stdc++.h>
using namespace std;


char st[1000500];

char li1[] = "qwertyuiop[]";
char li2[] = "asdfghjkl;'";
char li3[] = "zxcvbnm,./";

int main(){
	freopen("test.txt", "r", stdin);
	gets(st);
	int ln = strlen(st);
	int li1n = strlen(li1), li2n = strlen(li2), li3n = strlen(li3);
	for (int i = 0; i < ln; i++) if (st[i] != ' '){
		for (int j = 0; li1[j]; j++) if (st[i] == li1[j] || (st[i] | 32) == li1[j]) {
			st[i] = li1[((j - 2) + li1n) % li1n];
		}
		for (int j = 0; li2[j]; j++) if (st[i] == li2[j] || (st[i] | 32) == li2[j]) {
			st[i] = li2[((j - 2) + li2n) % li2n];
		}
		for (int j = 0; li3[j]; j++) if (st[i] == li3[j] || (st[i] | 32) == li3[j]) {
			st[i] = li3[((j - 2) + li3n) % li3n];
		}
	}
	puts(st);
}
