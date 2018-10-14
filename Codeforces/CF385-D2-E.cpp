/*
	since t is up to 1e18 we can't simulate

	usually contranits like this, where we need variables dependable on linear combination on some other variables
	we need matrix power

	how to get matrix here

	first, since we need to work with mod, let's change indices to 0-based
	but notice now k = x+ y + 2, because we subtracted 1 from x and 1 from y

	and we don't have to worry about doing mod operations on t or other variables
	because we are doing +,* operations only 

	with little work we can get this formulas:
	dx = dx+sx+sy+t+2, as k = sx+sy+2 because 0-based
	dy = dy+sx+sy+t+2, as k = sx+sy+2 because 0-based
	sx = dx+2*sx+sy+t+2, here we have 2*sx, because sx = sx + k, where k sx+sy+2
	sy = dy+sx+2*sy+t+2, sumilar as above
	t = t + 1, just moving one step

	here's the matrix correspending to above formula:
	{sx}  {2, 1, 1, 1, 0, 0}
	{sy}  {1, 2, 1, 1, 0, 0}
	{dx}  {1, 0, 1, 0, 0, 0}
	{dy}  {0, 1, 0, 1, 0, 0}
	{t}   {1, 1, 1, 1, 1, 0}
	{1}   {2, 2, 2, 2, 1, 1}

*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mod;

typedef vector<ll> row;
typedef vector<row> matrix;


#define all(v)           ((v).begin()), ((v).end())
#define sz size()
#define clr(v,d)         memset(v,d,sizeof(v))
#define lp(i, n)         for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define sci(a)	scanf("%d",&a)
#define scii(a, b)	scanf("%d%d",&a, &b)
#define pri(a)	printf("%d\n",a)





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
	ios::sync_with_stdio(0);
	ll n, sx, sy, dx, dy, t;
	cin >> n >> sx >> sy >> dx >> dy >> t;
	--sx; --sy;
	dx = (dx%n + n) % n;
	dy = (dy%n + n) % n;
	matrix init = zero(1, 6);
	init[0][0] = sx; init[0][1] = sy;
	init[0][2] = dx; init[0][3] = dy;
	init[0][4] = 0; init[0][5] = 1;
	matrix trans = {
			{2, 1, 1, 1, 0, 0},
			{1, 2, 1, 1, 0, 0},
			{1, 0, 1, 0, 0, 0},
			{0, 1, 0, 1, 0, 0},
			{1, 1, 1, 1, 1, 0},
			{2, 2, 2, 2, 1, 1}
	};
	mod = n;
	trans = pow(trans, t);
	init = multiply(init, trans);
	cout << init[0][0]+1 << " " << init[0][1]+1;
}
