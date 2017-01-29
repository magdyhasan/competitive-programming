#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

unsigned int wx[10], wo[10];
char gr[10][10];

map<unsigned int, int> ma;
int cntW;

bool checkW(unsigned int msk){
	for (int i = 0; i < 10; i++)
		if (((wx[i] & msk) == wx[i]) || ((wo[i] & msk) == wo[i]))
			return 1;
	return 0;
}

int rec(unsigned int msk, bool turn){
	if (ma.find(msk) != ma.end()) return ma[msk];
	int &ret = ma[msk];
	if (checkW(msk)) return ret = -1;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) if (((msk >> ((i * 4 + j) * 2)) & 3) == 0){
			int pos = i * 4 + j;
			unsigned int curP = turn ? 2UL : 1UL;
			if (rec(msk | (curP << (pos * 2)), !turn) == -1)
				return ret = pos;
		}
	return ret = -1;
}

int main(){
    freopen("uva.txt","rt",stdin);
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++) // row with number i
			wx[cntW] |= 1UL << ((i * 4 + j)*2),
			wo[cntW] |= 2UL << ((i * 4 + j)*2);
		cntW++;
		for (int j = 0; j < 4;j++) // column with number i
			wx[cntW] |= 1UL << ((j * 4 + i)*2),
			wo[cntW] |= 2UL << ((j * 4 + i)*2);
		cntW++;
	}
	for (int i = 0; i < 4;i++) // main diagonal
		wx[cntW] |= 1UL << ((i * 4 + i) * 2),
		wo[cntW] |= 2UL << ((i * 4 + i) * 2);
	cntW++;
	for (int i = 0; i < 4;i++) // second diagonal
		wx[cntW] |= 1UL << ((i * 4 + 3 - i) * 2),
		wo[cntW] |= 2UL << ((i * 4 + 3 - i) * 2);
	cntW++;
	char t[10];
	while (scanf("%s", t)){
		if (t[0] == '$') break;
		ma.clear();
		for (int i = 0; i < 4; i++)	scanf("%s", gr[i]);
		unsigned int msk = 0;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				if (gr[i][j] == 'x') msk |= 1UL << ((i * 4 + j) * 2);
				else if (gr[i][j] == 'o')	msk |= 2UL << ((i * 4 + j) * 2);
		int ret = rec(msk, 0);
		if (ret == -1) puts("#####");
		else printf("(%d,%d)\n", ret / 4, ret % 4);
	}
}
