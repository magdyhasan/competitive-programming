/*
				       | 0 | n-1 |
	let trans matrix = | 1 | n-2 |
		
					   | a[i] | (s-a[i]) |
	and init matrix =  | 0    |  0       |
	where s is sum of all a[i], so init[0][0] is current number, init[0][1] is sum of other terms except this one

                   | a[i] | (s-a[i]) | * | 0 | n-1 |   = | (s-a[i]) | a[i]*(n-1)+(s-a[i])*(n-2) |
	init * trans = | 0    |  0       |   | 1 | n-2 |     |   0      |     0                     |

	firt term(s-a[i]) is just a[i] after 1 round by rules
	second term, you can notice that in new sum we will add a[i] (n-1) times, and other terms will be added (n-2),
	play with sample to get sense of that
*/
#include<stdlib.h>
#include<stdio.h>
#include<cstring>
using namespace std;

typedef long long ll;

// another code from http://codeforces.com/contest/450/submission/7159071
struct matrix
{
	ll a[2][2];
	matrix() {
		memset(a, 0, sizeof(a));
	}
	matrix operator * (const matrix &p) {
		matrix c;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				for (int k = 0; k < 2; k++)
					c.a[i][j] = (c.a[i][j] + a[i][k] * p.a[k][j]) % 98765431LL;
		return c;
	}
};

matrix pow(ll n, matrix t){
	if (n == 1) return t;
	if (n & 1LL) return pow(n / 2, t * t) * t;
	return pow(n / 2, t * t);
}

int a[50500];


int main(){
    freopen("uva.txt","rt",stdin);
	int N, T;
	scanf("%d%d", &N, &T);
	ll s = 0;
	for (int i = 0; i < N; i++) scanf("%d", a + i), s += a[i];
	matrix init, trans;
	trans.a[1][0] = 1, trans.a[0][1] = N - 1, trans.a[1][1] = N - 2;
	trans = pow(T, trans);
	for (int i = 0; i < N; i++){
		init.a[0][0] = a[i], init.a[0][1] = (s - a[i]) % 98765431LL;
		printf("%d\n", (init * trans).a[0][0]);
	}
}
