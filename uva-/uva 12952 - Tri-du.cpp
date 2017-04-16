#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("uva.txt","rt",stdin);
	int x, y;
	while (scanf("%d%d", &x, &y) != EOF){
		if (x == y) printf("%d\n", x);
		else printf("%d\n", max(x, y));
	}
}
