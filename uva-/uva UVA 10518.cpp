#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
/*
f(0) = 1, f(1) = 1
f(n) = f(n-1)+f(n-2)+1
Let's use matrix pow
|1 1 1|   |1 0 1|
|0 0 0| * |0 0 1| ^ n-1
|0 0 0|   |0 1 1|
-add 1 every time ( first column)
-switch last column
-last element is 1 + f(n-1) + f(n-2)
*/


#include<algorithm>
using namespace std;

const int maxn = 10500;

typedef long long ll;

ll n, b;

// another code from http://codeforces.com/contest/450/submission/7159071
struct matrix
{
	long long a[3][3];
	matrix() {
		memset(a, 0, sizeof(a));
	}
	matrix operator * (const matrix &p) {
		matrix c;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 3; k++)
					c.a[i][j] = (c.a[i][j] + a[i][k] * p.a[k][j]) % b;
		return c;
	}
};

matrix pow(long long n, matrix t)
{
	if (n == 1) return t;
	if (n & 1LL) return pow(n / 2, t * t) * t;
	return pow(n / 2, t * t);
}



int main(){
	freopen("uva.txt", "r", stdin);
	int tc = 0;
	while (scanf("%lld%lld", &n, &b)){
		if (!n&&!b) break;
		printf("Case %d: %lld %lld ", ++tc, n, b);
		if (n < 3){
			if (n < 2) printf("%lld\n", 1 % b);
			else  printf("%lld\n", 3 % b);
			continue;
		}
		matrix init, trans;
		init.a[0][0] = 1 % b, init.a[0][1] = init.a[0][2] = 1 % b;
		trans.a[0][0] = 1 % b, trans.a[2][1] = 1 % b,
			trans.a[0][2] = 1 % b, trans.a[1][2] = 1 % b, trans.a[2][2] = 1 % b;
		trans = pow(n - 1, trans);
		init = init*trans;
		printf("%lld\n", init.a[0][2]);
	}
}