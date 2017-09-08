#include<bits/stdc++.h>
using namespace std;



typedef long long ll;


const ll mod = 1000000009;

typedef vector<ll> row;
typedef vector<row> matrix;

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

matrix pow(const matrix& a, ll k){
	if (k == 0)
		return identityMatrix(a.size());
	if (k % 2 == 1)
		return multiply(a, pow(a, k - 1));
	return pow(multiply(a, a), k / 2);
}

int main(){
    freopen("uva.txt","rt",stdin);
	ll n; 
	while (scanf("%lld", &n)){
		if (!n) break;
		matrix init = zero(3, 3), trans = zero(3, 3);
		init[0][0] = 0, init[0][1] = 1, init[0][2] = 2;
		trans[0][2] = 1;
		trans[1][0] = trans[1][2] = 1;
		trans[2][1] = trans[2][2] = 1;
		trans = pow(trans, n - 1);
		init = multiply(init, trans);
		printf("%lld\n", init[0][0]);
	}
}
