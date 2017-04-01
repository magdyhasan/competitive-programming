#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;

char li[1000500];
int a[1000500], b[1000500];

int main(){
    freopen("uva.txt","rt",stdin);
	while (gets(li)){
		istringstream iss(li);
		int n = 0, m = 0, tn;
		while (iss >> tn){
			a[n++] = tn;
		}
		gets(li);
		istringstream iss2(li);
		while (iss2 >> tn){
			b[m++] = tn;
		}
		sort(a, a + n);
		sort(b, b + m);
		{
			bool subset = 1; 
			int out = 0;
			for (int i = 0; i < m; i++) if (!binary_search(a, a + n, b[i])) subset = 0, out++;
			if (subset){
				if (n == m)
					puts("A equals B");
				else
					puts("B is a proper subset of A");
				continue;
			}
			if (out == m){
				puts("A and B are disjoint");
				continue;
			}
		}
		{
			bool subset = 1;
			for (int i = 0; i < n; i++) if (!binary_search(b, b + m, a[i])) subset = 0;
			if (subset){
				puts("A is a proper subset of B");
				continue;
			}
		}
		puts("I'm confused!");
	}
}
