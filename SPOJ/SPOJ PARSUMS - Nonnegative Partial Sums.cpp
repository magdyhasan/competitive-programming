#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

int a[2000500];

int main(){
    freopen("uva.txt","rt",stdin);
	int n;
	while (scanf("%d", &n) && n){
		for (int i = 0; i < n; i++) scanf("%d", a + i), a[i + n] = a[i];
		int s = 0, ret = 0;
		for (int i = n * 2 - 1; i >= 0; i--){
			s += a[i];
			if (s >= 0)	{
				if (i < n) ret++;
				s = 0;
			}
		}
		printf("%d\n", ret);
	}
}
