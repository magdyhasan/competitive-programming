/*
	one can observate that if there's some balanced substring, then doing operation on it 
	won't make unbalanced
	so we can look at string after removing all balanced parts
	now we have 4 cases:
	1- no unbalaned parts, answer is 0
	2- (((..((( here we can do operation on half it and it will be balanced
	3- )))..))) also here we can do operation on half it and it will be balanced 
	4- )))..((( now here we 2 operation, first transfer ')' to '(' with just one operation
		now we are at case 1 again which need another operation
*/

#include<bits/stdc++.h>
using namespace std;

#define lp(i, n)         for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)     for(int i=(j);i>=(int)(n);--i)

int main(){
	int n; string st;
	cin >> n >> st;
	int op = 0, cl = 0;
	lp(i, n){
		if (st[i] == '(') op++;
		else{
			if (op > 0) op--;
			else cl++;
		}
	}
	cout << ((op && cl) ? 2 : ((op || cl) ? 1 : 0));
}
