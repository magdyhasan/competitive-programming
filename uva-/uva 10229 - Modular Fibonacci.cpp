#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<cstring>
#include<vector>
using namespace std;

int pow_2, n, m;


typedef vector<long long> row;
typedef vector<row> matrix;

matrix zero(int n, int m) {
	return matrix(n, row(m, 0));
}

matrix _identity(int n) {
	matrix ret = zero(n, n);
	for (int i = 0; i < (int)ret.size(); i++)
		ret[i][i] = 1;
	return ret;
}


matrix multiply(const matrix &a, const  matrix &b) {
	matrix ret = zero(a.size(), b[0].size());
	for (int i = 0; i < (int)a.size(); i++)
		for (int j = 0; j < (int)b[0].size(); j++)
			for (int k = 0; k < (int)a[0].size(); k++)
				ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % pow_2;
	return ret;
}

matrix pow(const matrix& a, int k){
	if (k == 0)
		return _identity(a.size());
	if (k % 2 == 1)
		return multiply(a, pow(a, k - 1));
	return pow(multiply(a, a), k / 2);
}





int main(){
	matrix fib = zero(2, 2);
	while (scanf("%d%d", &n, &m) != EOF) {
		if (m == 0) {
			puts("0");
			continue;
		}
		fib[0][1] = fib[1][0] = fib[1][1] = 1; // construct the fibonacci matrix 
		pow_2 = (1 << m); // 2^m
		int cycle = pow_2 * 3; // remove all cycle from n 
		n %= cycle;
		printf("%lld\n", pow(fib, n)[0][1]); // find nth power of fib matrix
	}
}

