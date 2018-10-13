/*
	number of paths in grid n*m, is (m-1 + n-1)!/(m-1)!(n-1)!
	which is about 35345263800 here.
	we can notice that the limits are not far away froom getting in time
	so if we divided by 2, we can have 17672631900 that can runs in time.

	so this leads us to meet-in-middle, we first generate paths of length (n+m-2)/2
	and at end of this path we store xor of this path in map

	and then start from end start another path of the remaining original path length, 
	and at the end of current path, we test if there's number in map that xor with k give us our current value
*/
#include<bits/stdc++.h>
using namespace std;


#define all(v)           ((v).begin()), ((v).end())
#define sz size()
#define clr(v,d)         memset(v,d,sizeof(v))
#define lp(i, n)         for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define sci(a)	scanf("%d",&a)
#define scii(a, b)	scanf("%d%d",&a, &b)
#define pri(a)	printf("%d\n",a)



typedef long long ll;

const int maxn = 300500;

ll n, m, k;

map<ll, int> cnt[22][22];
ll a[22][22];

ll ret;

void rec1(int i, int j, ll v, int rem){
	v ^= a[i][j];
	if (rem == 0){
		++cnt[i][j][v];
		return;
	}
	if (i + 1 < n) rec1(i + 1, j, v, rem - 1);
	if (j + 1 < m) rec1(i, j + 1, v, rem - 1);
}

void rec2(int i, int j, ll v, int rem){
	if (rem == 0){
		ret += cnt[i][j][v^k];
		return;
	}
	v ^= a[i][j];
	if (i > 0) rec2(i - 1, j, v, rem - 1);
	if (j > 0) rec2(i, j - 1, v, rem - 1);
}

int main(){
	ios::sync_with_stdio(0);
	cin >> n >> m >> k;
	lp(i, n) lp(j, m) cin >> a[i][j];
	int fi = (n + m - 2 + 1) / 2;
	rec1(0, 0, 0, fi);
	rec2(n - 1, m - 1, 0, (n + m - 2) - fi);
	cout << ret;
}