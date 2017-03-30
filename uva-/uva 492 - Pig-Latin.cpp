#include<bits/stdc++.h>
using namespace std;


char st[1000500];

char vo[] = { 'a', 'e', 'i', 'o', 'u' };

bool isVol(char st){
	for (int i = 0; i < 5; i++) if ((st | 32) == vo[i]) return true;
	return false;
}

int main(){
	freopen("uva.txt", "r", stdin);
	while (gets(st)){
		string t;
		for (int i = 0; st[i]; i++){
			if (!((st[i] | 32) >= 'a' && (st[i] | 32) <= 'z')){
				if (t.size()) {
					if (!isVol(t[0])){
						t += t[0];
						t = t.substr(1);
					}
					t += "ay";
					printf("%s", t.c_str());
					t = "";
				}
				putchar(st[i]);
			}
			else
				t += st[i];
		}
		puts("");
	}
}