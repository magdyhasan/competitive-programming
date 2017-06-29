/*
-Build a matrix to get sequence element
-add an extra column to keep sum of previous elements
-ans = sum[n] - sum[m-1]
*/

#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<vector>
using namespace std;


typedef long long ll;



typedef vector<ll> row;
typedef vector<row> matrix;

ll m, n, p;

matrix zero(int n, int m) {
	return matrix(n, row(m, 0));
}

matrix identityMatrix(int n) {
	matrix ret = zero(n, n);
	for (int i = 0; i < ret.size(); i++)
		ret[i][i] = 1;
	return ret;
}

matrix reflect(matrix a) {
	matrix ret = zero(a.size(), a[0].size());
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < a[i].size(); j++)
			ret[i][j] = a[i][a[0].size() - 1 - j];
	return ret;
}

matrix rotate(matrix a) {
	matrix ret = zero(a[0].size(), a.size());
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < a[i].size(); j++)
			ret[j][a.size() - 1 - i] = a[i][j];
	return ret;
}

matrix add(matrix &a, matrix &b) {
	matrix ret = zero(a.size(), a[0].size());
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < a[i].size(); j++)
			ret[i][j] = a[i][j] + b[i][j];
	return ret;
}

matrix addidentity(matrix &a) {
	matrix ret = a;
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < a[i].size(); j++)
			ret[i][i] += 1;
	return ret;
}

matrix multiply(const matrix &a, const  matrix &b) {
	matrix ret = zero(a.size(), b[0].size());
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < b[0].size(); j++)
			for (int k = 0; k < a[0].size(); k++)
				ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % p;
	return ret;
}

matrix pow(const matrix& a, ll k){
	if (k == 0)
		return identityMatrix(a.size());
	if (k % 2 == 1)
		return multiply(a, pow(a, k - 1));
	return pow(multiply(a, a), k / 2);
}

int b[15], c[15];

int main(){
    freopen("uva.txt","rt",stdin);
	int T;	scanf("%d", &T);
	while (T--){
		int k;	scanf("%d", &k);
		ll sk = 0;
		for (int i = 0; i < k; i++) scanf("%d", b + i), sk += b[i];
		for (int i = 0; i < k; i++) scanf("%d", c + i);
		sk -= b[k - 1];
		scanf("%lld%lld%lld", &m, &n, &p);
		matrix init = zero(k+1, k+1);
		for (int i = 0; i < k; i++)
			init[0][i] = b[i];
		init[0][k] = sk;
		matrix trans = zero(k+1, k+1);
		for (int j = 1; j < k; j++)
			trans[j][j - 1] = 1;
		for (int i = 0; i < k; i++)
			trans[i][k - 1] = c[k - i - 1];
		for (int i = k-1; i < k + 1; i++)
			trans[i][k] = 1;
		matrix trans_n = pow(trans, n - k + 1);
		ll sm = 0;
		if (m - 1 <= k){
			for (int i = 0; i + 1 < m; i++)  sm += b[i];
		}
		else{
			matrix trans_m = pow(trans, m - k);
			matrix tm = multiply(init, trans_m);
			sm = tm[0][k];
		}
		sm %= p;
		matrix ret = multiply(init, trans_n);
		printf("%lld\n", ((ret[0][k] - sm )%p+p)%p);
	}
}
