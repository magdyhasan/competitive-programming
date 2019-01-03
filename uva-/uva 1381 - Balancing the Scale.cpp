/*
we can see that we can solve for each 8 numbers independtly,
so our answer will be ans[some 8 numbers] * ans[remaining 8 numbers]

now to solve for 8 numbers,
let's think about all different 4 numbers that we can get with their premutations
if for some fixed 4 number we have their sum = s
then we want to find all other 4 numbers that doesn't intersect with those 4 numbers,
and increase answer for those 8 numbers

so for each sum we get from some 4 numbers, let's store that we got sum from this current mask
now when we get this sum again from some other 4 numbers,
we can access previous masks by the given masks, and check if previous 4 numbers doesn't intersect current 4 numbers

*/
#include <bits/stdc++.h>	
using namespace std;


#define all(v)           ((v).begin()), ((v).end())
#define sz size()
#define clr(v,d)         memset(v,d,sizeof(v))
#define lp(i, n)         for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define sci(a)	scanf("%d",&a)
#define scll(a)	scanf("%lld",&a)
#define scii(a, b)	scanf("%d%d",&a, &b)
#define pri(a)	printf("%d\n",a)
#define prll(a)	printf("%lld\n",a)


const int maxn = 300500;

typedef long long ll;

typedef pair<int, int> pii;

int n = (1 << 16) - 1;

int a[16], b[16];

vector<int> ha[maxn];
int cn[maxn];

int main() {
	freopen("in.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc = 0;
	while (++tc){
		cin >> a[0];
		if (!a[0]) break;
		lpi(i, 1, 16) cin >> a[i];
		sort(a, a + 16);
		int c;
		lp(i, maxn) ha[i].clear(), cn[i] = 0;
		lp(msk, n){
			c = 0;
			lp(j, 16) if (msk&(1 << j))
				b[c++] = a[j];
			if (c == 4){
				do{
					int su = b[0] + b[1] * 2 + b[2] * 3 + b[3] * 4;
					for (auto j : ha[su]) if (!(j&msk)){
						++cn[j | msk];
					}
					ha[su].push_back(msk);
				} while (next_permutation(b, b + 4));
			}
		}
		int ret = 0;
		lp(msk, n) ret += cn[msk] * cn[msk^n];
		cout << "Case " << tc << ": " << ret / 2 << "\n";
	}
}