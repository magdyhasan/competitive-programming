#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

char line[100500];

bool isVowel(char ch){
	return (ch == 'i' || ch == 'e' || ch == 'o' || ch == 'u' || ch == 'a' || ch == 'y');
}

int main(){
    freopen("uva.txt","rt",stdin);
	while (gets(line)){
		int n = strlen(line);
		if (line[0] == 'e' && line[2] == 'o' && line[4] == 'i') break;
		int cnt[3] = {}, i = 0;
		for (int nli = 0; nli < 3; nli++){
			while (line[i] && line[i] != '/'){
				if (isVowel(line[i])){
					cnt[nli]++;
					while (isVowel(line[i])) i++;
				}
				else
					i++;
			}
			i++;
		}
		if (cnt[0] != 5) puts("1");
		else if (cnt[1] != 7) puts("2");
		else if (cnt[2] != 5) puts("3");
		else puts("Y");
	}
}
