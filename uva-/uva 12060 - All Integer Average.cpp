#include<bits/stdc++.h>
using namespace std;

const int maxn = 300500;


int n;
int gcd(int x, int y){
	int t;
	while (x%y)
		t = x, x = y, y = t%y;
	return y;
}

int len(int x){
	int ret = 0;
	while (x > 0){
		x /= 10;
		ret++;
	}
	return ret;
}

int main(){
    freopen("uva.txt","rt",stdin);
	int tc = 0;
	while (scanf("%d", &n) && n){
		printf("Case %d:\n", ++tc);
		int x, s= 0;
		for (int i = 0; i < n; i++){
			scanf("%d", &x);
			s += x;
		}
		if (s%n == 0){
			if (s < 0) printf("- "), s = -s;
			printf("%d\n", s / n);
		}
		else{
			bool ne = (s < 0);
			if (ne) s = -s;
			int b = s%n, c = n;
			int gc = gcd(b, c);
			b /= gc; c /= gc;
			int a = s / n;
			if (ne) printf("  ");
			for (int i = 0;a > 0 && i < len(a); i++) putchar(' ');
			printf("%*d", len(c), b);
			puts("");
			if (ne) printf("- ");
			if (a > 0) printf("%d", a);
			for (int i = 0; i < len(c); i++) putchar('-');
			puts("");
			if (ne) printf("  "); 
			for (int i = 0; a > 0 && i < len(a); i++) putchar(' ');
			printf("%d\n", c);
		}
	}
}
