#include<bits/stdc++.h>
using namespace std;






typedef vector<int> row;
typedef vector<row> matrix;

int mod;

matrix zero(int n, int m) {
	return matrix(n, row(m, 0));
}

matrix identityMatrix(int n) {
	matrix ret = zero(n, n);
	for (int i = 0; i < ret.size(); i++)
		ret[i][i] = 1;
	return ret;
}



matrix multiply(const matrix &a, const  matrix &b) {
	matrix ret = zero(a.size(), b[0].size());
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < b[0].size(); j++)
			for (int k = 0; k < a[0].size(); k++)
				ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % mod;
	return ret;
}

matrix pow(const matrix& a, int k){
	if (k == 0)
		return identityMatrix(a.size());
	if (k % 2 == 1)
		return multiply(a, pow(a, k - 1));
	return pow(multiply(a, a), k / 2);
}




int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	while (T--){
		int a, b, n, m;
		scanf("%d%d%d%d", &a, &b, &n, &m);
		mod = 1;
		while (m--) mod *= 10;
		matrix init = zero(2, 2), trans = zero(2, 2);
		init[0][0] = a%mod, init[0][1] = b%mod;
		trans[0][0] = 0; trans[0][1] = trans[1][0] = trans[1][1] = 1;
		trans = pow(trans, n);
		init = multiply(init,trans);
		printf("%d\n", init[0][0]);
	}
}
