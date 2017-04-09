#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string st[3][3];

bool check(char ch, int heavy){
	for (int li = 0; li < 3; li++){
		int l = 0, r = 0;
		for (char c : st[li][0])
			if (c == ch) l += heavy * 50;
			else l++;
		for (char c : st[li][1])
			if (c == ch) r += heavy * 50;
			else r++;
		if (st[li][2] == "even" && l != r) return 0;
		if (st[li][2] == "up" && l <= r) return 0;
		if (st[li][2] == "down" && l >= r) return 0;
	}
	return true;
}

int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	while (T--){
		for (int i = 0; i < 3; i++)
			cin >> st[i][0] >> st[i][1] >> st[i][2];
		for (char ch = 'A'; ch <= 'L';ch++)
			if (check(ch, 1)) 
				printf("%c is the counterfeit coin and it is heavy.\n", ch);
			else if (check(ch, -1)) 
				printf("%c is the counterfeit coin and it is light.\n", ch);
			
	}
}
